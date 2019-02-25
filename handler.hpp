#ifndef WEBSOCKET_HANDLER_HPP
#define WEBSOCKET_HANDLER_HPP

#include <websocket/frame.hpp> // frame_t

namespace websocket
{
  struct handler_t : frame_t
  {
  public:
    handler_t();

  public:
    bool is_payload_masked() const;
    void is_payload_masked(bool val);

  public:
    void encode();
    void decode();

  public:
    uint8_t * payload;
    bool encoded;
  };
};

#include <websocket/handler.hcp>

#endif/*WEBSOCKET_HANDLER_HPP*/
