#ifndef WEBSOCKET_WRITER_HPP
#define WEBSOCKET_WRITER_HPP

#include <websocket/frame.hpp>

namespace websocket
{
  uint8_t * write_medium_size(uint64_t size, uint8_t * out);
  uint8_t * write_large_size(uint64_t size, uint8_t * out);
  uint8_t * write_mask(uint32_t mask, uint8_t * out);

  uint8_t * write_forward(frame_t frame, uint8_t * out);
  uint8_t * write_backward(frame_t frame, uint8_t * out);

  uint8_t * write(frame_t frame, uint8_t * out);
};

#include <websocket/writer.hcp>

#endif/*WEBSOCKET_WRITER_HPP*/
