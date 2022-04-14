/*
*
* wytalkD.c Incomplete
* Author: Ian Moon
* Date: April 13, 2022
* COSC 3750, Homework 7
*  
* This program is a deamon process waiting for a respnce from  
* socket 51100 from another program wytalkC.c
* Colaberated with Zach Chrimmel on this project.
*
*/

#include "socketfun.h"
#include <string.h>

int main()
{
    int socket = 51100;
    char buffer[128];
    int size = 128;
    ssize_t mess = 0;
    int sfd = 0;

    int confd = 0;

    sfd = serve_socket("fish10", 51100);
    printf("server created \n");
    // confd = accept_connection(sfd);
    if (sfd >= 0)
    {
        confd = accept_connection(sfd);
        printf("connection established \n");
        while (1)
        {
            mess = 0;
            mess = read(socket, &buffer, size, 0);
            if (mess > 0)
                printf("%.*s\n", mess, buffer);
            memset(&buffer, 0, sizeof(buffer));
        }
    }

    // if(message < 0)
    //     close(51100);
    // printf("port closed\n");
}