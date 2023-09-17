#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
namespace HDE
{

    class SimpleSocket
    {
    private:
        struct sockaddr_in address;
        int sock;

    public:
        SimpleSocket(int domain, int service, int protocol, int port, u_long interface);
        virtual void connect_to_network(int sock, struct sockaddr_in address) = 0;
        void test_connection(int item_to_test);

        // getters
        struct sockaddr_in get_address();
        int get_sock();

    };

    SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
    {
        // define addr structure
        address.sin_family = domain;
        address.sin_port = htons(port);
        address.sin_addr.s_addr = htonl(interface);
        // establish connection
        sock = socket(domain, service, protocol);
        test_connection(sock);
    }

    // Test connection virtual function
    void SimpleSocket::test_connection(int item_to_test)
    {
        // verifies that either the socket or the connection has been properly established
        if (item_to_test < 0)
        {
            perror("Failed To Connect ....");
            exit(EXIT_FAILURE);
        }
    }

    struct sockaddr_in SimpleSocket::get_address()
    {
        return address;
    }

    int SimpleSocket::get_sock()
    {
        return sock;
    }
}

#endif