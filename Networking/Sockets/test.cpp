#include "ListeningSocket.hpp"

int main(){
    std::cout<<"Starting..."<<std::endl;
    std::cout<<"Binding Socket..."<<std::endl;
    //HDE::BindingSocket bs = HDE::BindingSocket(AF_INET,SOCK_STREAM,0,80,INADDR_ANY,10);
    std::cout<<"Listening Socket ..."<<std::endl;
    //HDE::ListeningSocket ls = HDE :: ListeningSocket(AF_INET,SOCK_STREAM,0,80,INADDR_ANY,10);
    HDE::ListeningSocket ls = HDE::ListeningSocket(AF_INET,SOCK_STREAM,0,80,(u_long)INADDR_ANY,10);
}