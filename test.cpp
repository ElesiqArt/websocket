#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <websocket/codec.hpp>
#include <websocket/data.hpp>
#include <websocket/frame.hpp>
#include <websocket/opcode.hpp>
#include <websocket/parser.hpp>
#include <websocket/status.hpp>

using namespace websocket;

SCENARIO("Opcode", "[opcode]")
{
  REQUIRE(!is_control(opcode::continuation));
  REQUIRE(!is_control(opcode::text));
  REQUIRE(!is_control(opcode::binary));
  REQUIRE(is_control(opcode::close));
  REQUIRE(is_control(opcode::ping));
  REQUIRE(is_control(opcode::pong));

  REQUIRE(!is_non_control(opcode::continuation));
  REQUIRE(is_non_control(opcode::text));
  REQUIRE(is_non_control(opcode::binary));
  REQUIRE(!is_non_control(opcode::close));
  REQUIRE(!is_non_control(opcode::ping));
  REQUIRE(!is_non_control(opcode::pong));
}

SCENARIO("Frame", "[frame]")
{
  REQUIRE(size::max::medium == std::pow(2, 16) - 1);
  REQUIRE(size::max::large == std::pow(2, 64 - 1) - 1);

  GIVEN("A web socket frame")
    {
      frame_t frame;

      WHEN("Toggling values")
	{
	  frame.is_final(true);
	  REQUIRE(frame.control == 0b10000000);
	  frame.is_final(false);
	  REQUIRE(frame.control == 0);

	  frame.control = 0b11110000;
	  frame.has_rsv2(false);
	  REQUIRE(frame.control == 0b11010000);
	}

      WHEN("set to 0b10101010")
	{
	  frame.control = 0b10101010;

	  THEN("verify")
	    {
	      REQUIRE(frame.is_final());
	      REQUIRE(!frame.has_rsv1());
	      REQUIRE(frame.has_rsv2());
	      REQUIRE(!frame.has_rsv3());
	      REQUIRE(frame.opcode_() == opcode::pong);
	    }
	}

      WHEN("set to 0b01010011")
	{
	  frame.control = 0b01010011;

	  THEN("verify")
	    {
	      REQUIRE(!frame.is_final());
	      REQUIRE(frame.has_rsv1());
	      REQUIRE(!frame.has_rsv2());
	      REQUIRE(frame.has_rsv3());
	      REQUIRE(!is_valid_opcode(frame.opcode_()));
	    }
	}
    }
}

bool test_encoding(const uint8_t * value, std::size_t length, const uint8_t mask[4], const uint8_t * out)
{
  for(std::size_t i = 0; i < length; ++i)
    {
      if(out[i] != (value[i] ^ mask[i%4])) return false;
    }

  return true;
}

SCENARIO("Codec", "[codec]")
{
  const uint8_t buffer[] = {0x48,0x65,0x6c,0x6c,0x6f,0x20,0x77,0x6f,0x72,0x6c,0x64,0x21};
  const std::size_t size = 12;
  const uint8_t mask[] = {0x3F, 0x8A, 0xF1, 0x32};

  uint8_t out[size] = {0};

  for(std::size_t i = 1; i < size; ++i)
    {
      xcode(buffer, i, mask, out);
      REQUIRE(test_encoding(buffer, i, mask, out));
    }
}

template<bool Masked>
void parser()
{
  const uint8_t * buffer;
  std::size_t size;

  for(int i = 1; i <= 4; ++i)
    {
      buffer = data::frame_buffer<Masked>(i, size);
      const char * text = data::frame_payload(i);

      frame_t frame;
      const uint8_t * current = parse(buffer, frame);

      REQUIRE((std::size_t)(current - buffer) == size - std::strlen(text));
      REQUIRE(frame.length() == std::strlen(text));

      char data[frame.length()] = {0};
      xcode(current, frame.length(), frame.mask, (uint8_t *)data);

      REQUIRE(std::memcmp(data, text, std::strlen(text)) == 0);
    }
}

SCENARIO("Parser", "[parser]")
{
  parser<true>();
  parser<false>();
}
