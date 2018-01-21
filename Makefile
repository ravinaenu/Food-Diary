
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall  -pedantic -g -Iinclude


diary:
	gcc $(CFLAGS)  putYourSourceFileshere -o bin/nameYOurExecutableHere

test: 
	gcc $(CFLAGS) src/yourMainTestFileHere src/linkedList.c  -o bin/listTest

clean:
	@ rm *.o
