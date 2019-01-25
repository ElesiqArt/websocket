#ifndef WEBSOCKET_OPCODE_HPP
#define WEBSOCKET_OPCODE_HPP

#include <cstdint> // uint8_t

namespace websocket
{
  enum class opcode : uint8_t
  {
    continuation = 0x0,
      text = 0x1,
      binary = 0x2,
      close = 0x8,
      ping = 0x9,
      pong = 0xA
  };

  const char * opcode_name(opcode value);

  template<typename T>
  bool is_valid_opcode(T value);

  bool is_control(opcode value);
  bool is_non_control(opcode value);
};

#include <websocket/opcode.hcp>

#endif/*WEBSOCKET_OPCODE_HPP*/
