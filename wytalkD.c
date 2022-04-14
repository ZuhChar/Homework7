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
    int socket = 51100;
    char buffer[128];
    int size = 128;
    ssize_t message = 0;
    int sfd = 0;

    int confd = 0;

    sfd = serve_socket("fish", 51100);
    if (sfd >= 0)
    {
        confd = accept_connection(sfd);
    }

    message = recv(socket, buffer, size, 0);

    printf("%.*s\n", message, buffer);
    memset(&buffer, 0, sizeof(buffer));
}