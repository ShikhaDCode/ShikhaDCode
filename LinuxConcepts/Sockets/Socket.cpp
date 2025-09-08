#include<iostream>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>

int main()
{
    int sock;
    char buffer[1024] = {0};

    //create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock <= 0){
        perror("Socket creation failed");
    }

    //bind
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    int addrlen = sizeof(address);

    bind(sock, (sockaddr *)&address, addrlen);

    listen(sock, 5);

    int newSockfd = accept(sock, (sockaddr *)&address, (socklen_t*)&addrlen);

    int bytes = recv(newSockfd, buffer, sizeof(buffer), 0);

    char *myMsg = "hello from server";
    send(newSockfd, myMsg, sizeof(myMsg), 0);

    close(newSockfd);
    close(sock);

    return 0;

}