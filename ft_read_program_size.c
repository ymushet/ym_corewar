#include "corewar.h"

int ft_read_program_size(int fd, t_player *player)
{
	ssize_t r;
	
	r = read(fd, player->prog_size, 4);
	if (r != 4)
	{
		ft_free_player(&player);
		close(fd);
		ft_error("Not valid program size\n");
	}
	player->player_size = ft_create_int(player->prog_size);
	if (player->player_size == 0 || player->player_size > CHAMP_MAX_SIZE)
	{
		ft_free_player(&player);
		close(fd);
		ft_error("Not valid program size at \n");
	}
	return (1);
}