#ifndef TestServer_hpp
#define TestServer_hpp

#include <stdio.h>
#include "SimpleServer.hpp"
namespace HDE
{
    class TestServer : public SimpleServer
    {
    private:
        char buffer[30000] ={0};
        int new_socket;

        void accepter() override;
        void handler() override;
        void responder() override;
    public:
        TestServer(/* args */);
        void launch() override;
    };
    
    TestServer::TestServer() : SimpleServer(AF_INET,SOCK_STREAM,0,80,INADDR_ANY,10)
    {
        launch();
    }

    void TestServer::accepter()
    {
        struct sockaddr_in address = get_socket()->get_address();
        int addrlen = sizeof(address);
        new_socket = accept(
                        get_socket()->get_sock(),
                        (struct sockaddr *)&address, 
                        (socklen_t *)&addrlen
                    );

        read(new_socket,buffer,30000);
    }
    
    void TestServer::handler()
    {
        std::cout<<buffer<<std::endl;
    }

    void TestServer::responder()
    {
        char *hello = "Hello from the server";
        write(new_socket,hello,strlen(hello));
        close(new_socket);
    }

    void TestServer::launch()
    {
        while(true)
        {
            std::cout<<" ============ Waiting ============ "<<std::endl;
            accepter();
            handler();
            responder();
            std::cout<<" ============ Done ============ "<<std::endl;
        }
    }
    
}

#endif