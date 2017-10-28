/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:19:04 by opariy            #+#    #+#             */
/*   Updated: 2017/10/28 13:19:06 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ft_get_value(int ind)
{
	int result;

	if (ind < 0)
	{
		while (ind < 0)
			ind += MEM_SIZE;
		result = ind;
	}
	else if (ind >= MEM_SIZE)
		result = ind % MEM_SIZE;
	else
		result = ind;
	return (result);
}

void	ft_write_bold(int num, int start, int end)
{
	int	i;

	i = -1;
	while (++i < end)
		g_dt.map[2][ft_get_value(start + i)] = (unsigned char)(-num);
}

void	ft_write_col(int num, int address)
{
	g_dt.map[1][ft_get_value(address)] = (unsigned char)(num + 64);
	g_dt.map[1][ft_get_value(address + 1)] = (unsigned char)(num + 64);
	g_dt.map[1][ft_get_value(address + 2)] = (unsigned char)(num + 64);
	g_dt.map[1][ft_get_value(address + 3)] = (unsigned char)(num + 64);
}

int		ft_increment_index(t_process *process)
{
	process->mem_addres = (ft_get_value(process->mem_addres + 1)) % MEM_SIZE;
	return (process->mem_addres);
}

int		ft_get_ind(int value)
{
	int result;

	result = (g_dt.map[0][ft_get_value(value)] << 24) |
	(g_dt.map[0][ft_get_value(value + 1)] << 16) |
	(g_dt.map[0][ft_get_value(value + 2)] << 8) |
	g_dt.map[0][ft_get_value(value + 3)];
	return (result);
}
