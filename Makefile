CC = gcc
CFLAGS = -Wall

TARGET = func_pointer

defaul: func

func: func_ptr.h func_ptr.c IntList.o
		$(CC) $(CFLAGS) -o func func_ptr.c IntList.o

IntList.o: IntList.h IntList.c
		$(CC) $(CFLAGS) -c IntList.c

clean:
		$(RM) *.o .*~
