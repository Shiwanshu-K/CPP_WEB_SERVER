#ifndef BindingSocket_hpp
#define BindingSocket_hpp
#include <stdio.h>
#include "SimpleSocket.hpp"
namespace HDE
{

    class BindingSocket : public SimpleSocket
    {
    private:
        int backlog;
        int binding;
    public:
        BindingSocket(int domain, int service, int protocol, int port, u_long interface, int bcklg);

        void connect_to_network(int sock, struct sockaddr_in address) override;

        // getters
        int get_backlog();

        // setters
        void set_backlog(int bcklg);
    };

    BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interface, int bcklg) : SimpleSocket(domain, service, protocol, port, interface)
    {
        connect_to_network(get_sock(), get_address());
        test_connection(binding);
    }

    void BindingSocket::connect_to_network(int sock, struct sockaddr_in address)
    {
        binding =  bind(sock, (struct sockaddr *)&address, sizeof(address));
    }

    int BindingSocket::get_backlog()
    {
        return backlog;
    }

    void BindingSocket::set_backlog(int bcklg)
    {
        backlog = bcklg;
    }

}

#endif