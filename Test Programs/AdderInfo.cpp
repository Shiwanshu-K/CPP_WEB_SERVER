#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
using namespace std;

// struct addrinfo {
//     int              ai_flags;     // AI_PASSIVE, AI_CANONNAME, etc.
//     int              ai_family;    // AF_INET, AF_INET6, AF_UNSPEC
//     int              ai_socktype;  // SOCK_STREAM, SOCK_DGRAM
//     int              ai_protocol;  // use 0 for "any"
//     size_t           ai_addrlen;   // size of ai_addr in bytes
//     struct sockaddr *ai_addr;      // struct sockaddr_in or _in6
//     char            *ai_canonname; // full canonical hostname

//     struct addrinfo *ai_next;      // linked list, next node
// };

int print_addrinfo_node(struct addrinfo *head, int &count ){
    return printf("\nnode number\t\t\t\t%d\nai_family\t\t\t\t%d\nai_socktype\t\t\t\t%d\nai_protocol\t\t\t\t%d\nai_addrlen\t\t\t\t%d\nai_canonname\t\t\t\t%s\nsockaddr{\n\tsa_family:\t\t\t%c\n\tsa_data:\t\t\t%s}\n",
                    count,
                    head->ai_family,
                    head->ai_socktype,
                    head->ai_protocol,
                    head->ai_addrlen,
                    head->ai_canonname,
                    head->ai_addr->sa_family,
                    head->ai_addr->sa_data);

}

int main(){

    int status,count=1;
    struct addrinfo hints;
    struct addrinfo *servinfo,*head;

    memset(&hints,0,sizeof(hints));
    hints.ai_family =AF_UNSPEC;
    hints.ai_socktype= SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if(status = getaddrinfo(NULL,"3490",&hints,&servinfo) !=0){
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }
    head = servinfo;
    while(head !=NULL){

        print_addrinfo_node(head,count);
        head = head->ai_next;
        count++;
    }
    freeaddrinfo(servinfo);

    return 0;
}

