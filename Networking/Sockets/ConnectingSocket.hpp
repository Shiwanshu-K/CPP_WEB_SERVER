#ifndef ConnectingSocket_hpp
#define ConnectingSocket_hpp

#include <stdio.h>
#include "SimpleSocket.hpp"

namespace HDE
{

    class ConnectingSocket : public SimpleSocket
    {
    private:
        /* data */
        int connection;
    public:
        ConnectingSocket(int domain, int service, int protocol, int port, u_long interface) ;
        void connect_to_network(int sock, struct sockaddr_in address) override;
    };

    ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long interface) : SimpleSocket(domain, service, protocol, port, interface)
    {
        connect_to_network(get_sock(), get_address());
        test_connection(connection);
    }

    void ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address)
    {
        connection =  connect(sock, (struct sockaddr *)&address, sizeof(address));
    }

}

#endif