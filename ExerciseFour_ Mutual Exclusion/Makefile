
 #Project: CDD Labs
 #Author: Michael Chambers
 #License:https://creativecommons.org/licenses/by/4.0/legalcode
 #Date: 22/11/2019



CC=g++
CFLAGS= -std=c++17 -pthread

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: main.o Semaphore.o
	$(CC) -o mutualExclusion main.o Semaphore.o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
