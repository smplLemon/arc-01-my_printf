CC = gcc
CFLAGS = -Wall -Wextra -Werror  -g3 -fsanitize=address
TARGET = my_printf
SRC = my_printf.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

.Phony:fclean

fclean:
	rm -f $(TARGET)