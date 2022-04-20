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
#include<stdlib.h>
#include<unistd.h>

int main()
{
    char buffer[128];
    int size = 128;
    ssize_t message = 0;
    int sfd = 0;
    char hostname[512];
    int confd = 0;
    int rtn;
    int *frtn;
    char ch;
    int index;

    gethostname(hostname,512);
    sfd = serve_socket(hostname, 51100);
    printf("server created \n");
    // confd = accept_connection(sfd);
    if (sfd >= 0)
    {
        confd = accept_connection(sfd);
        while(1){
            rtn = read(conft, &ch, 1);
            if (rtn < 0){
                close(confd);
                return 0;
            }
            buffer[index] = ch;
            if (ch == '\n'){
                
            }
        }
        // confd = accept_connection(sfd);
        // printf("connection established \n");
        while (1)
        {
            recv(confd, &buffer, size, 0);
            if (buffer > 0)
                printf("%s",  buffer);
            else
                break;
        }
        close(confd);
    }

    // if(message < 0)
    //     close(51100);
    // printf("port closed\n");
}