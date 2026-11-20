CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = interface

SRCS = interface.c taskq.c schFcfs.c sortF.c statsFormat.c schSjf.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c utility.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(TARGET)

