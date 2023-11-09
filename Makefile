CC = gcc
CFLAGS = -std=c11 -Wall -pthread

SRC = test.c
TARGET = test

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(TARGET)