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
#include <string.h>

int main()
{
    int socket = 51100, valread;
    char buffer[128];
    int size = 128;
    ssize_t message = 0;
    int sfd = 0;

    int confd = 0;

    sfd = serve_socket("fish16", 51100);
    printf("server created \n");
    // confd = accept_connection(sfd);
    if (sfd >= 0)
    {
        confd = accept_connection(sfd);
        printf("connection established \n");
        while (1)
        {
            // recv(socket, &buffer, size, 0);
            // if (message > 0)
            //     printf("%.*s\n", message, buffer);
            // memset(&buffer, 0, sizeof(buffer));
            valread = read(socket, buffer, 1024);
            printf("%s\n", buffer);
            send(socket, buffer, strlen(buffer), 0);
            //printf("Hello message sent\n");
        }
    }

    // if(message < 0)
    //     close(51100);
    // printf("port closed\n");
}