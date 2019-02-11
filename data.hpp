#ifndef WEBSOCKET_DATA_HPP
#define WEBSOCKET_DATA_HPP

#include <websocket/frame.hpp>

namespace websocket
{
  namespace data
  {
    template<bool Masked>
    frame_t frame(std::size_t id);
    template<bool Masked>
    const uint8_t * frame_buffer(std::size_t id, std::size_t & size);
    const char * frame_payload(std::size_t id);

    template<bool Masked>
    frame_t frame_1();
    template<bool Masked>
    frame_t frame_2();
    template<bool Masked>
    frame_t frame_3();
    template<bool Masked>
    frame_t frame_4();

    template<bool Masked>
    const uint8_t * frame_1_buffer(std::size_t & size);
    template<bool Masked>
    const uint8_t * frame_2_buffer(std::size_t & size);
    template<bool Masked>
    const uint8_t * frame_3_buffer(std::size_t & size);
    template<bool Masked>
    const uint8_t * frame_4_buffer(std::size_t & size);

    const char * frame_1_payload();
    const char * frame_2_payload();
    const char * frame_3_payload();
    const char * frame_4_payload();
  };
};

#include <websocket/data.hcp>

#endif/*WEBSOCKET_DATA_HPP*/
