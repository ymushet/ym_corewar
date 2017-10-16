#include "corewar_vm_validation.h"

int ft_validate_magic(unsigned char *magic)
{
	/*
	 * Перевод меджика в инт.
	 */
	unsigned int n;
	
	n = 0;
	n = (unsigned char)magic[0] << 24 | (unsigned char)magic[1] << 16 |
	    (unsigned char)magic[2] << 8 | (unsigned char)magic[3];
	if (n != COREWAR_EXEC_MAGIC)
		return (0);
	return (1);
}

t_player *ft_malloc_player(unsigned int n) //выдиление памяти и инициализация под структуры.
{
	/*
	 * Выдиление памяти и инициализация под структуры. Все чар типы должны быть занулены для правильной
	 * записи памяти.
	 */
	t_player *player;
	size_t len;
	
	player = malloc(sizeof(t_player));
	ft_bzero(player->magic, 4);
	ft_bzero(player->prog_size, 4);
	len = PROG_NAME_LENGTH + 1;
	while ((len % 4) != 0)
		len++;
	player->prog_name = (unsigned char*)ft_strnew(len);
	len = COMMENT_LENGTH + 1;
	while ((len % 4) != 0)
		len++;
	player->comment = (unsigned char*)ft_strnew(len);
	player->number = n;
	player->instructions = NULL;
	player->next = NULL;
	return (player);
}

int ft_read_magic(int fd, t_player *player)
{
	/*
	 * Чтение первых 4 байт в меджик.
	 */
	read(fd, player->magic, 4);
	if (!ft_validate_magic(player->magic))
	{
		ft_free_player(&player);
		close(fd);
		ft_error(1);
	}
	return (1);
}

int ft_check_equlizing_byte(unsigned char *str) //проверка на нули в выравнивающем байте
{
	/*
	 * Проверка уравнивающего байта на содержание.
	 */
	int i;
	
	i = 0;
	while (i < 4)
	{
		if (str[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

int ft_read_program_name(int fd, t_player *player)
{
	/*
	 * Чтение имени программы и проверка его длины.
	 */
	ssize_t          r;
	//ssize_t          j;
	size_t          len;
	//unsigned char   eq_byte[4];
	
	len = PROG_NAME_LENGTH + 1;
	while ((len % 4) != 0)
		len++;
	//ft_bzero(eq_byte, 4);
	r = read(fd, player->prog_name, len);
	//j = read(fd, eq_byte, 4);
	if (r != len)
	{
		ft_free_player(&player);
		close(fd);
		ft_error(2);
	}
//	else //проверка 4х байтов выравнивания.
//	{
//		if (j != 4 || !ft_check_equlizing_byte(eq_byte))
//		{
//			ft_free_player(&player);
//			close(fd);
//			ft_error(4);
//		}
//	}
	return (1);
}