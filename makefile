CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = my_mastermind.c
OBJ = $(SRC:.c=.o)
TARGET = my_mastermind

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all