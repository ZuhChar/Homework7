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

int main(){
    sfd = serve_socket(fish, 51100);
    confd = accept_connection(sfd);
    
}