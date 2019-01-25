#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <websocket/opcode.hpp>
#include <websocket/frame.hpp>

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
