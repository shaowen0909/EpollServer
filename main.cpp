#include "src/AsyncServer.h"

int main()
{
    // parameters: (listen_ip, listen_port, timeout)
    AsyncServer async_server("0.0.0.0", 6666, 10);
    async_server.EventLoop();
}