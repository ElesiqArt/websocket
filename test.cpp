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
