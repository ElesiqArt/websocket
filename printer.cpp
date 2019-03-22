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

      print_header(std::cout, frame);
    }
}

int main()
{
  {
    frame_t frame;

    frame.is_final(true);
    frame.length(124);

    print_header(std::cout, frame);
  }

  {
    frame_t frame;

    frame.length(125);

    print_header(std::cout, frame);
  }

  run(true);
}
