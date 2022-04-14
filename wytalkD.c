//
// wytalkD.c
// Author: Zachary Crimmel
// Date: Apr 12, 2022
//
// COSC 3750, Homework 7
//
// This is the server side of the program responsible for opening the port and listening to the client.
// Collaborated with Ian Moon on this Homework
//
#include "socketfun.h"

int main()
{
    int socket = 51100;
    char *buffer = 128;
    int size = 128;
    ssize_t message = 0;
    int sfd = 0;
    char host = "fish";
    int confd = 0;

    sfd = serve_socket(host, 51100);
    confd = accept_connection(sfd);

    message = recv(socket, buffer, size, 0);
    
    if (message < 0)
        perror("recv() failed");
    printf("%s\n", buffer);
}