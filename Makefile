NAME = corewar

CFLAGS = -Wall -Wextra -Werror

SRC = ft_create_map.c ft_create_process.c ft_error.c ft_free_player.c ft_game_cycle.c ft_init_global.c ft_kill_process.c ft_read_comment.c ft_read_from_core.c ft_read_magic.c \
	ft_read_program_name.c ft_read_program_size.c ft_reed_instructions.c

CC = gcc

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

LIBFTSRC = libft/

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTSRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf libft/libft.a

re : all