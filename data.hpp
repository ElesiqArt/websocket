#ifndef WEBSOCKET_DATA_HPP
#define WEBSOCKET_DATA_HPP

#include <websocket/frame.hpp>

namespace websocket
{
  namespace data
  {
    frame_t frame(std::size_t id, bool masked);
    const uint8_t * frame_buffer(std::size_t id, bool masked, std::size_t & size);
    const char * frame_payload(std::size_t id);

    frame_t frame_1(bool masked);
    frame_t frame_2(bool masked);
    frame_t frame_3(bool masked);
    frame_t frame_4(bool masked);

    const uint8_t * frame_1_buffer(bool masked, std::size_t & size);
    const uint8_t * frame_2_buffer(bool masked, std::size_t & size);
    const uint8_t * frame_3_buffer(bool masked, std::size_t & size);
    const uint8_t * frame_4_buffer(bool masked, std::size_t & size);

    const char * frame_1_payload();
    const char * frame_2_payload();
    const char * frame_3_payload();
    const char * frame_4_payload();
  };
};

#include <websocket/data.hcp>

#endif/*WEBSOCKET_DATA_HPP*/
