aa:	*.c
	$(CC) -Wall -Wextra -Wpedantic -g -fsanitize=address -o $@ $^

fclean:
	$(RM) aa
