 #----------------------------------------------------------------------------
# Author: H. James de St. Germain
# Date: Spring 2011
#
# Sample Makefile
#----------------------------------------------------------------------------

#
# First declare aliases for use later on
#
CC              = g++
CFLAGS          = -g -Wall -pedantic
CPPFLAGS        = $(CFLAGS)
LIBS            = # -lm


################################################################
# ALL
#
# when you run make by itself, this is what it will try to create
#
all: main


################################################################
# 
# Rules for each executable/compilable unit
#
# Commented out lines show variations on how to compile
# and if all are commented out, this uses the implicit rule
#
# Don't forget tabs before rules!
#

main: AVLNode.o AVLTree.o FileReader.o HashTable.o Dictionary.o TestMain.c
	$(CC) $(CFLAGS) -o $@ AVLNode.o AVLTree.o FileReader.o HashTable.o Dictionary.o TestMain.c
#       g++ -g -Wall -pedantic -o main AVLTree.o FileReader.o HashTable.o Dictionary.o TestMain.c

AVLNode.o: AVLNode.c AVLNode.h
AVLTree.o: AVLTree.c AVLTree.h
HashTable.o: HashTable.C HashTable.h
FileReader.o: FileReader.h FileReader.c
Dictionary.o: Dictionary.C Dictionary.h

################################################################
#
# Define what it means to "cleanup" (remove all .o's and executables)
#
clean:
	rm -rf *.o main

#----------------------------------------------------------------------------
# End of file.
#----------------------------------------------------------------------------