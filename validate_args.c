/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:43:14 by opariy            #+#    #+#             */
/*   Updated: 2017/10/18 18:43:15 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void player_add(t_player **head, t_player *new)
{
	new->next = *head;
	*head = new;
}

int			ft_isadigit(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atoi(str) > 0 && ft_atoi(str) <= MAX_PLAYERS)
		return (1);
	return (0);
}

int		find_players_num(t_player *p, int num)
{
	while (p)
	{
		if (p->number == num)
			return (0);
		p = p->next;
	}
	return (1);
}

void	parse_player(int fd, t_player **h, int num, t_player *p)
{
	p = ft_read_from_core(fd, num);
	player_add(h, p);
//	count_players++;
}

int		get_fd(char *file_name)
{
	int 	length;
	int 	fd;

	fd = 0;
	length = ft_strlen(file_name);
	if (length <= 4 || ft_strcmp((file_name + length - 4), ".cor"))
		ft_error("only .cor files are accepted\n");
	fd = open(file_name, O_RDONLY);
	if (fd <= 2)
		ft_error("Invalid flag\n");
	return (fd);
}

int 		basic_check(char *str)
{
	int 	g_a;
	int 	g_v;

	if (ft_strcmp(str, "-v") == 0)
	{
		g_v = 1;
		return (1);
	}
	else if (ft_strcmp(str, "-a") == 0)
	{
		g_a = 1;
		return (1);
	}
	return (0);
}

int 		check_dump(char *str_next, char *str)
{
	int 	g_dump;

	if (ft_strcmp(str, "-dump") == 0 && str_next && ft_isadigit(str_next))
	{
		g_dump = ft_atoi(str_next);
		printf("dump is %d\n", g_dump);
		return (1);
	}
	return (0);
}

void		ft_parse_args(int argc, char **argv, int i)
{
	int 	fd;
	t_player	*player;
	t_player	*head;

	player = NULL;
	head = NULL;
	while (i < argc)
	{
		if (!basic_check(argv[i]))
		{
			if (argv[i + 1] && check_dump(argv[i + 1], argv[i]))
				i++;
			else if (ft_strcmp(argv[i], "-n") == 0)
			{
				if (argv[i + 1] && argv[i + 2] && ft_isadigit(argv[i + 1]))
				{
					fd = get_fd(argv[i + 2]);
					if (!find_players_num(head, ft_atoi(argv[i + 1])))
						ft_error("Invalid flag\n");
					parse_player(fd, &head, ft_atoi(argv[i + 1]), player);
					i += 2;
				}
				else
					ft_error("Invalid flag\n");
			}
			else
				parse_player(get_fd(argv[i]), &head, 0, player);
		}
		i++;
	}
	// player = head;
	// while (player)
	// {
	// 	printf("!!!\n");
	// 	printf("name %s\n", player->prog_name);
	// 	printf("num %d\n", player->number);
	// 	player = player->next;
	// }
}
