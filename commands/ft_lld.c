/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:46:00 by opariy            #+#    #+#             */
/*   Updated: 2017/10/22 19:46:02 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ft_take_ind_short(int index)
{
	int res;

	res = (g_dt.map[0][ft_get_value(index + 2)] << 8) |
	g_dt.map[0][ft_get_value(index + 3)];
	return (res);
}

void	ft_lld(t_process *process)
{
	char	position;

	position = g_dt.map[0][ft_get_value(process->mem_addres + 1)];
	if (position == -48)
	{
		ft_take_args(process, 0, g_dt.map[0][process->mem_addres]);
		if (process->args[2] >= 0 && process->args[2] <= REG_NUMBER)
		{
			process->regs[process->args[2]] =
	(unsigned int)ft_take_ind_short(process->mem_addres - 5 + process->args[1]);
			process->cary = (process->regs[process->args[2]] == 0) ? 1 : 0;
		}
	}
	else if (position == -112)
	{
		ft_take_args(process, 0, g_dt.map[0][process->mem_addres]);
		if (process->args[2] >= 0 && process->args[2] <= REG_NUMBER)
		{
			process->regs[process->args[2]] = (unsigned int)process->args[1];
			process->cary = (process->regs[process->args[2]] == 0) ? 1 : 0;
		}
	}
	else
		ft_increment_index(process);
	ft_bzero(process->args, 16);
}
