#ifndef WEBSOCKET_HELPER_HPP
#define WEBSOCKET_HELPER_HPP

#include <cstdint> // uint8_t uint64_t

namespace websocket
{
  namespace mask
  {
    constexpr uint8_t fin = 0x80;
    constexpr uint8_t rsv1 = 0x40;
    constexpr uint8_t rsv2 = 0x20;
    constexpr uint8_t rsv3 = 0x10;
    constexpr uint8_t opcode = 0x0F;

    constexpr uint8_t masked = 0x80;
    constexpr uint8_t length = 0x7F;
  };

  namespace size
  {
    typedef uint8_t type;

    namespace medium
    {
      constexpr type delimiter = 126;
    };

    namespace large
    {
      constexpr type delimiter = 127;
    };

    namespace max
    {
      constexpr uint64_t small = 125;
      constexpr uint64_t medium = 0xFFFF;//2 bytes
      constexpr uint64_t large = 0x7FFFFFFFFFFFFFFF;//8 bytes with the most signigicant bit always zero
    };
  };
};

#endif/*WEBSOCKET_HELPER_HPP*/
