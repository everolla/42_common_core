SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

comp_ft_printf:
	@make -C ft_printf all

comp_libft:
	@make -C libft all
	
all: comp_ft_printf comp_libft server client

bonus: server client

server: server.o
	$(CC) -o $@ $< ft_printf/libftprintf.a libft/libft.a

client: client.o
	$(CC) -o $@ $< ft_printf/libftprintf.a libft/libft.a

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)
	make -C ft_printf clean
	make -C libft clean
	
fclean: clean
	rm -f server client ft_printf/libftprintf.a libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re