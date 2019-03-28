#include <cstdio>
#include <iostream>

#include <websocket/printer.hpp>
#include <websocket/data.hpp>

using namespace websocket;

void run(bool masked)
{
  for(int i = 1; i <= 4; ++i)
    {
      frame_t frame = data::frame(i, masked);
      const char * buffer = data::frame_payload(i);

      print(std::cout, frame, buffer, masked) << std::endl;
    }
}

int main()
{
  {
    frame_t frame;

    frame.is_final(true);
    frame.length(124);
    frame.is_masked(false);

    print_header(std::cout, frame);
  }

  {
    frame_t frame;

    frame.length(125);
    frame.is_masked(true);
    frame.payload_mask(9272);

    print_header(std::cout, frame);
  }

  {
    frame_t frame;

    frame.length(2429);
    frame.is_masked(false);

    print_header(std::cout, frame);
  }

  {
    frame_t frame;

    frame.length(2429);
    frame.is_masked(true);
    frame.payload_mask(35);

    print_header(std::cout, frame);
  }

  {
    frame_t frame;

    frame.length(100000);
    frame.is_masked(false);

    print_header(std::cout, frame);
  }

  {
    frame_t frame;

    frame.length(100000);
    frame.is_masked(true);
    frame.payload_mask(973);

    print_header(std::cout, frame);
  }

  run(false);
  run(true);
}
