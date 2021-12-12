SRC		= *.c
CFLAGS	= -Wall -Wextra -Wpedantic -g -fsanitize=address

aa		: $(SRC) Makefile
	$(CC) $(CFLAGS) -o $@ $(SRC)

fclean	:
	$(RM) aa
