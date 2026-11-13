CC=$(CROSS_COMPILE)gcc

writer:
	$(CC) -g -Wall -c writer.c -o writer.o
	$(CC) -g -Wall writer.o -o writer

clean:
	$(RM) writer writer.o
