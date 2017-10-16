NAME = corewar

CFLAGS = -Wall -Wextra -Werror

SRC = src/read_core.c src/main.c src/process.c src/ft_atoi_base.c src/map.c src/error.c src/core2.c corewar_vm_validation.h \
		src/read_core2.c visualization/visualization.c visualization/visualization.h visualization/set_color.c

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