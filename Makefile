CC = gcc
CFLAGS = -Wall -Wextra -g -O0
TARGET = hysilen
SRC = main.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
