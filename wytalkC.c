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

int main()
{
	char buffer[128];
	int socket = 51100, valread;
	int length = 128;
	int flags = 0;

	int conft = 0;

	conft = request_connection("Zach", 51100);
	printf("connection made \n");
	while (1)
	{
		scanf("%s", buffer);
		// printf("Your message:%s", buffer);
		// send(socket, &buffer, length, flags);
		send(socket, buffer, strlen(buffer), 0);
		printf("Hello message sent\n");
		valread = read(socket, buffer, 1024);
		printf("%s\n", buffer);
	}
	close(51100);
	printf("port closed\n");
}
