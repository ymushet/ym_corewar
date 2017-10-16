#include "corewar_vm_validation.h"

/*
 *  Структура игрока описана в хедере.
 * .cor можно разделить на следующие поля.
 *  Меджик - всегда должен быть равен COREWAR_EXEC_MAGIC и имеет размер 4 байта.
 *  Имя программы - имеет размер PROG_NAME_LENGTH (сейчас 128 байт).
 *  Выравнивающий байт (0000) - 4 байта сразу за именем программы.
 *  Комментарий - имеет длину COMMENT_LENGTH (сейчас 2048).
 *  Размер программы - 4 байта. Указывает длину следующего поля в байтах.
 *  Инструкции - бот которого размещаем на поле.
 */

int ft_read_instructions(int fd, t_player *player)
{
	ssize_t r;
	
	player->instructions = (unsigned char*)ft_strnew(CHAMP_MAX_SIZE + 1);
	r = read(fd, player->instructions, CHAMP_MAX_SIZE + 1);
	if (r != player->player_size)
	{
		ft_free_player(&player);
		close(fd);
		ft_error(6);
	}
	else if (r == player->player_size)
	{
		r = read(fd, NULL, 1);
		if (r != 0)
		{
			ft_free_player(&player);
			close(fd);
			ft_error(6);
		}
	}
	return (1);
}

int ft_read_comment(int fd, t_player *player)
{
	/*
	 * Чтение и проверка длины комментария.
	 */
	ssize_t r;
	size_t len;
	
	len = COMMENT_LENGTH + 1;
	while ((len % 4) != 0)
		len++;
	r = read(fd, player->comment, len);
	if (r != len)
	{
		ft_free_player(&player);
		close(fd);
		ft_error(3);
	}
	return (1);
}

int ft_read_program_size(int fd, t_player *player)
{
	/*
	 * Чтение и проверка длины размера программы.
	 */
	ssize_t r;
	
	r = read(fd, player->prog_size, 4);
	if (r != 4)
	{
		ft_free_player(&player);
		close(fd);
		ft_error(5);
	}
	player->player_size = ft_create_int(player->prog_size);
	if (player->player_size == 0 || player->player_size > CHAMP_MAX_SIZE)
	{
		ft_free_player(&player);
		close(fd);
		ft_error(5);
	}
	return (1);
}

int ft_core_file_validation(int fd, t_player **player)
{
	if (ft_read_magic(fd, *player))
		if (ft_read_program_name(fd, *player))
			if (ft_read_program_size(fd, *player))
				if (ft_read_comment(fd, *player))
					if (ft_read_instructions(fd, *player))
						return (1);
	return (0);
}

/*
 * Чтение и проверка всего .cor файла. Запись данных об игроке в t_player.
 */
t_player *ft_read_from_core(int fd, unsigned int n)
{
	t_player	*player;
	
	player = ft_malloc_player(n);
	if (!ft_core_file_validation(fd, &player))
	{
		ft_free_player(&player);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (player);
}

/*
 * Тестовый мейн для компиляции кусков кода.
 */
int main(int argc, char **argv)
{
	if (argc == 0)
		exit (1);
	t_player *p;
	t_process *c;
	printf("%s\n", argv[1]);
	int fd = open(argv[1], O_RDONLY);
	p = ft_read_from_core(fd, 1);
	close(fd);
	int dd = open(argv[1], O_RDONLY);
	p->next = ft_read_from_core(dd, 2);
	close(dd);
	char **map = ft_create_map(p, 2);
//	int k = 0;
//	while (k < MEM_SIZE)
//	{
//		printf("%.2X ", map[0][k]);
//		k++;
//		if (k % 32 == 0)
//			printf("\n");
//	}
	//c = ft_create_proceses(p);
	return (0);
}