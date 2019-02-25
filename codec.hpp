#ifndef WEBSOCKET_CODEC_HPP
#define WEBSOCKET_CODEC_HPP

#include <cstdint> // uint8_t uint64_t

namespace websocket
{
  void xcode(const uint8_t * in, uint64_t size, uint32_t mask, uint8_t * out);
  void xcode(const uint8_t * in, uint64_t size, const uint8_t mask[4], uint8_t * out);
};

#include <websocket/codec.hcp>

#endif/*WEBSOCKET_CODEC_HPP*/
