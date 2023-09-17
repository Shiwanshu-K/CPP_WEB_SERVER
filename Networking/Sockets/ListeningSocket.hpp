#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

#include <stdio.h>
#include "BindingSocket.hpp"

namespace HDE
{
    class ListeningSocket : public BindingSocket
    {
    private:
        int listening;

    public:
        ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int bcklg); //: BindingSocket(domain, service, protocol, port, interface,bcklg){};

        void start_listening();
    };

    ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int bcklg) : BindingSocket(domain, service, protocol, port, interface, bcklg)
    {
        set_backlog(bcklg);
        start_listening();
        std::cout<<"Listening is : "<<listening<<std::endl;
        test_connection(listening);
    };

    void ListeningSocket::start_listening()
    {
        listening = listen(get_sock(), get_backlog());
    }

}

#endif