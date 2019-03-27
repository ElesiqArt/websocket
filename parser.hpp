#ifndef WEBSOCKET_PARSER_HPP
#define WEBSOCKET_PARSER_HPP

#include <websocket/frame.hpp>

namespace websocket
{
  const uint8_t * parse_control_and_info(const uint8_t * in, frame_t & frame);

  const uint8_t * parse_medium_size(const uint8_t * in, uint64_t & size);
  const uint8_t * parse_large_size(const uint8_t * in, uint64_t & size);
  const uint8_t * parse_mask(const uint8_t * in, uint32_t & mask);
  const uint8_t * parse_size_and_mask(const uint8_t * in, frame_t & frame);

  const uint8_t * parse(const uint8_t * in, frame_t & frame);
};

#include <websocket/parser.hcp>

#endif/*WEBSOCKET_PARSER_HPP*/
