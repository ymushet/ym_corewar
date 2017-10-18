NAME = corewar

LIB = -L./libft -lft

FLAGS = -Wall -Wextra -Werror

SRC = ft_create_map.c ft_free_player.c ft_kill_processes.c ft_read_magic.c ft_reed_instructions.c\
ft_create_precesess.c ft_game_cycle.c ft_read_coment.c ft_read_program_name.c main.c\
ft_error.c ft_init_global.c ft_read_from_core.c ft_read_program_size.c

BINS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINS)
	make -C libft/
	gcc $(LIB) -o $(NAME) $(BINS)
%.o: %.c
	gcc -c -o $@ $<
clean:
	make -C libft/ clean
	rm -rf $(BINS)
fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)
re: fclean all