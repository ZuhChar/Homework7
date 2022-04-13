# 
# Makefile
# Author: Zachary Crimmel
# Date: Apr 12, 2022
#
# COSC 3750, Homework 7
#
# This is a Makefile designed to compile the wytar.c file
# Collaborated with Ian Moon on this Homework
#

CC=gcc
CFLAGS= -Wall -ggdb
RM= rm -f

.PHONY: all clean tidy

all: wytalkC wytalkD

wytalkC: wytalkC.c
	${CC} ${CFLAGS} wytalkC.c socketfun.c -o wytalkC

wytalkD: wytalkD.c
	${CC} ${CFLAGS} wytalkD.c socketfun.c -o wytalkD

clean:
	${RM} *.o wytalkC wytalkD

tidy:
	${RM} a.out core.* wytalkC wytalkD