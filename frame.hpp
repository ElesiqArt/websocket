#ifndef WEBSOCKET_FRAME_HPP
#define WEBSOCKET_FRAME_HPP

#include <cstdint> // uint8_t uint32_t uint64_t

#include <websocket/common.hpp> // size::type
#include <websocket/opcode.hpp> // opcode

namespace websocket
{
  struct frame_t
  {
  public:
    frame_t();

  public:
    bool is_final() const;
    bool has_rsv1() const;
    bool has_rsv2() const;
    bool has_rsv3() const;
    opcode opcode_() const;
    bool is_masked() const;
    uint64_t length() const;
    uint32_t payload_mask() const;

  public:
    void is_final(bool value);
    void has_rsv1(bool value);
    void has_rsv2(bool value);
    void has_rsv3(bool value);
    void opcode_(opcode value);
    void is_masked(bool value);
    bool length(uint64_t value);
    void payload_mask(uint32_t value);

  public:
    size::type size_type() const;
    std::size_t header_size() const;
    std::size_t total_size() const;

  public:
    bool operator == (const frame_t & rhs) const;
    bool operator != (const frame_t & rhs) const;

  public:
    static constexpr std::size_t max_header_size = 14;

  public:
    uint8_t control;
    uint8_t info;
    uint64_t size;
    uint32_t mask;
  };
};

#include <websocket/frame.hcp>

#endif/*WEBSOCKET_FRAME_HPP*/
