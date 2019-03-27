#ifndef WEBSOCKET_PRINTER_HPP
#define WEBSOCKET_PRINTER_HPP

#include <ostream>

#include <websocket/frame.hpp>

namespace websocket
{
  std::ostream & print_control(std::ostream & os, uint8_t value);
  std::ostream & print_info(std::ostream & os, uint8_t value);
  std::ostream & print_size(std::ostream & os, uint64_t size, size_t width);
  std::ostream & print_mask(std::ostream & os, const frame_t & frame, size_t width);

  std::ostream & print_header(std::ostream & os, const frame_t & frame);

  uint64_t print_payload(std::ostream & os, const frame_t & frame, const char * payload, bool encoded, size_t width, uint64_t length = 0);

  std::ostream & print(std::ostream & os, const frame_t & frame, const char * payload, bool encoded);
};

#include <websocket/printer.hcp>

#endif/*WEBSOCKET_PRINTER_HPP*/
