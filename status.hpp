#ifndef WEBSOCKET_STATUS_HPP
#define WEBSOCKET_STATUS_HPP

#include <cstdint> // uint16_t
#include <cstring> // strlen()

namespace websocket
{
  namespace status_code
  {
    typedef uint16_t type;

    bool is_unused(type code);
    bool is_protocol(type code);
    bool is_registered(type code);
    bool is_unregistered(type code);

    constexpr type any = 0;

    constexpr type normal = 1000;
    constexpr type going_away = 1001;
    constexpr type protocol_error = 1002;
    constexpr type invalid_data = 1003;
    constexpr type reserved = 1004;
    constexpr type none = 1005; // do not send in a Close control frame
    constexpr type abnormal = 1006; // do not send in a Close control frame
    constexpr type inconsistent = 1007;
    constexpr type policy_violation = 1008;
    constexpr type too_big = 1009;
    constexpr type extension_negociation_failure = 1010;
    constexpr type unexpected_condition = 1011;
    constexpr type tls_handshake_failed = 1015; // do not send in a Close control frame

    struct rfc6455_t
    {
      static const type max = 4999;
      static const std::size_t max_reason_length = std::strlen("extension negociation failure");
      static const char * reason(type code);
    };
  };
};

#include <websocket/status.hcp>

#endif/*WEBSOCKET_STATUS_HPP*/
