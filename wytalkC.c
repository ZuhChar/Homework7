/*
* wytalkC.c Incomplete
* Author: Ian Moon
* Date: April 13, 2022
*
* COSC 3750, Homework 7
*
* This client program establishes a connection to the deamon process wytalkD from
* port 51100. 
* Collaborated with Zach Crimmel on this project.
*/

#include "socketfun.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define size 128

int main(int argc, char **argv)
{
	char buffer[128];
	int socket = 51100;
	char *ch;
	int index;
	char *rtn;
	char *frtn;
	int conft;



	printf("Enter host name: ");
	scanf("%s", buffer);

	conft = request_connection(buffer, 51100);
	printf("connection made \n");
	while (1)
	{
		index = 0;
		frtn = fgets(buffer, size, stdin);

		if(frtn < 0) {
			close(socket);
			return 0;
		}

		write(socket, buffer, size);

		while(1) {
			rtn = read(socket, &ch, 1);
			if(rtn < 0) {
				close(51100);
				return 0;
			}
			buffer[index] = ch;
			if(ch == '\n')
				break;
			if(index == (size - 2))
				break;
		}
	}
	close(51100);
	printf("port closed\n");
}
