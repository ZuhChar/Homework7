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
 
int main(){
	char* buffer[128];
	int socket = 51100;
	int length = 128;
	int flags = 0;
	char host = 51100;
	int conft = 0;

	conft = request_connection("fish", 51100);
	ssize_t send(socket, buffer, length, flags);
}
