/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:46:30 by opariy            #+#    #+#             */
/*   Updated: 2017/10/22 19:46:32 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ft_take_ind(int index)
{
	int res;

	res = (g_dt.map[0][ft_get_value(index)] << 24) |
			(g_dt.map[0][ft_get_value(index + 1)] << 16) |
			(g_dt.map[0][ft_get_value(index + 2)] << 8) |
			g_dt.map[0][ft_get_value(index + 3)];
	return (res);
}

void	ft_help_ld(t_process *p, char position)
{
	if (position == -48)
	{
		p->args[1] %= IDX_MOD;
		ft_take_args(p, 0, g_dt.map[0][p->mem_addres]);
		if (p->args[2] >= 0 && p->args[2] <= REG_NUMBER)
		{
			p->regs[p->args[2]] = (unsigned int)ft_take_ind((p->mem_addres - 5 +
					p->args[1]) % IDX_MOD);
			p->cary = (p->regs[p->args[2]] == 0) ? 1 : 0;
		}
	}
	else if (position == -112)
	{
		ft_take_args(p, 0, g_dt.map[0][p->mem_addres]);
		if (p->args[2] >= 0 && p->args[2] <= REG_NUMBER)
		{
			p->regs[p->args[2]] = (unsigned int)p->args[1];
			p->cary = (p->regs[p->args[2]] == 0) ? 1 : 0;
		}
	}
	else
		ft_increment_index(p);
	ft_bzero(p->args, 16);
}

void	ft_ld(t_process *process)
{
	char	position;

	position = g_dt.map[0][ft_get_value(ft_get_value(process->mem_addres + 1))];
	ft_help_ld(process, position);
}
