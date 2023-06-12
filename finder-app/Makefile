CC = gcc
CROSS_COMPILE = 

CFLAGS = -Wall -Wextra

SRCS = writer.c

OBJS = $(SRCS:.c=.o)

TARGET = writer


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -o $@ $^


%.o: %.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)

