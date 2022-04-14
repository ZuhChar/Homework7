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
#define size 128

int main()
{
	char buffer[128];
	int socket = 51100;
	int length = 128;
	int flags = 0;
	char* frtn, rtn;
	int conft = 0;

	printf("Enter host name: ");
	scanf("%s", buffer);

	conft = request_connection(buffer, 51100);
	printf("connection made \n");
	while (1)
	{
		// scanf("%s", buffer);
		frtn = fgets(buffer, size-1, stdin);
		fprintf("%s",buffer);
		if(frtn == NULL) {
			close(socket);
			return 0;
		}
;

		rtn = send(frtn,buffer,strlen(buffer),0);
		if(rtn < 1) {
			close(socket);
			return 0;
		}
		
	}
	close(51100);
	printf("port closed\n");
}
