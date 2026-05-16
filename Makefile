CC = gcc
CFLAGS = -Wall -Wextra -g -O0 -Iinclude
TARGET = hysilen
SRC = src/main.c src/executor.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
