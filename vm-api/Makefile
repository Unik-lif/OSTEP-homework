# SRCS
SRCS = memory-user.c strdup.c null.c data.c afterfree.c funny.c

# specify target
TARGET = memory-user strdup null data afterfree funny

# specify compiler, compiler flags, and needed libs.
CC = gcc
OPTS = -Wall -O0 -g

OBJS = $(SRCS:.c=.o)

all:$(TARGET)

memory-user: memory-user.o
	$(CC) -o $@ $^

strdup: strdup.o
	$(CC) -o $@ $^

null: null.o
	$(CC) -o $@ $^

data: data.o
	$(CC) -o $@ $^

afterfree: afterfree.o
	$(CC) -o $@ $^

funny: funny.o
	$(CC) -o $@ $^


%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

val:
	valgrind --leak-check=yes $(FILE)

clean:
	rm -f $(TARGET) $(OBJS)
