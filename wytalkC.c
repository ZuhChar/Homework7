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
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv)
{
	char buffer[128];
	int length = 128;
	char ch;
	int index;
	int rtn;
	char *frtn;
	int conft = 0;

	conft = request_connection(argv[1], 51100);
	printf("connection made \n");
	while (1)
	{
		index = 0;
		frtn = fgets(buffer, length, stdin);
		if(frtn < 0){
			break;
		}
		write( conft, buffer, length);
		while (1)
		{
			rtn = read(conft, &ch, 1);
			if (rtn < 0)
			{
				close(conft);
				return 0;
			}
			buffer[index] = ch;
			if (ch == '\n')
			{
				break;
			}
			if (index == length - 2)
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
	close(conft);
	printf("port closed\n");
	return 0;
}
