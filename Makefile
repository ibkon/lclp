CC		= gcc
SRCS	= main.c\
			src/udpService.c
OBJS	= src/$(SRCS:.c=.o)
EXEC	= lclp

start:$(OBJS)
	$(CC) -Wall -I include/ -o $(EXEC) $(OBJS)
.c.o:
	$(CC) -Wall -I include/ -o $@ -c $<
clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)
