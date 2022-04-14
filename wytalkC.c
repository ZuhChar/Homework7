//
//  wytalkC.c
//  Author: Zachary Crimmel
//  Date: Apr 12, 2022
//
//  COSC 3750, Homework 7
//
//  This is the client side talk program that will connect to wytalkD host on port 51100.
//  Responsible for reading from the user and sending a line of user input to wytalkD
//  Collaborated with Ian Moon on this Homework
//

#include "socketfun.h"
#include <string.h>

int main()
{
	char buffer[128];
	int socket = 51100;
	int length = 128;
	int flags = 0;
	char ch;
	int index;
	int conft = 0;
	char *rtn;
	char *frtn;

	conft = request_connection(gethostname(), 51100);
	printf("connection made \n");
	while (1)
	{
		frtn = fgets(buffer, length, stdin);
		if(frtn < 0){
			break;
		}
		write(socket, buffer, length);
		while (1)
		{
			rtn = read(socket, &ch, 1);
			if (rtn < 0)
			{
				close(51100);
				return 0;
			}
			buffer[index] = ch;
			if (ch == "\n")
			{
				break;
			}
			if (index == size - 2)
			{
				break;
			}
			// scanf("%s", buffer);
			// printf("Your message:%s", buffer);
			// send(socket, &buffer, length, flags);
			// if (sizeof(buffer) == 0)
			// 	break;
		}
		printf("%s", buffer);
	}
	close(51100);
	printf("port closed\n");
	return 0;
}
