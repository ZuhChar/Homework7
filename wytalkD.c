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
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int socket = 51100;
    char buffer[128];
    int size = 128;
    ssize_t mess = 0;
    int sfd = 0;
    char hostname[512];
    int confd = 0;

    gethostname(hostname,512);
    sfd = serve_socket(hostname, 51100);
    printf("server created \n");
    // confd = accept_connection(sfd);
    if (sfd >= 0)
    {
        confd = accept_connection(sfd);
        printf("connection established \n");
        while (1)
        {
            recv(socket, &buffer, size, 0);
            if (mess > 0)
                printf("%.*s\n", mess, buffer);
            else
                break;
        }
        close(51100);
    }

}