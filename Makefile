# 
# Makefile
# Author: Ian Moon
# Date: Apr 13, 2022
#
# COSC 3750, Homework 7
#
# This is a Makefile designed to compile the socketfun.c/h, 
# wytalkD.c and wytalkC.c file
# Collaborated with Zach Chrimmel on this Homework
#

CC=gcc
CFLAGS= -Wall -ggdb
RM= rm -f

.PHONY: full clean tidy

full: wytalkC wytalkD

wytalkC: wytalkC.c
	${CC} ${CFLAGS} wytalkC.c socketfun.c -o wytalkC

wytalkD: wytalkD.c
	${CC} ${CFLAGS} wytalkD.c socketfun.c -o wytalkD

clean:
	${RM} *.o wytalkC wytalkD

tidy:
	${RM} a.out core.* wytalkC wytalkD