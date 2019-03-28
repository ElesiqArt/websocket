#ifndef WEBSOCKET_KEY_HPP
#define WEBSOCKET_KEY_HPP

namespace websocket
{
  constexpr char guid[] = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";

  constexpr std::size_t key_size = 24;// 16-bytes base64 encoded
  constexpr std::size_t concatenated_key_guid_size = key_size + 36;
  constexpr std::size_t header_field_value_size = 28;// 20 bytes base64 encoded
};

#endif/*WEBSOCKET_KEY_HPP*/
