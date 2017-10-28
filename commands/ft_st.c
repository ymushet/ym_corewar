/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:16:33 by opariy            #+#    #+#             */
/*   Updated: 2017/10/28 13:16:35 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_st01(t_process *p)
{
	ft_take_args(p, 0, g_dt.map[0][p->mem_addres]);
	if (p->args[1] >= 0 && p->args[1] <= REG_NUMBER)
	{
		p->args[2] = p->mem_addres - 5 + (p->args[2] % IDX_MOD);
		g_dt.map[0][ft_get_value(p->args[2])] =
				(unsigned char)(p->regs[p->args[1]] >> 24);
		g_dt.map[0][ft_get_value(p->args[2] + 1)] =
				(unsigned char)(p->regs[p->args[1]] >> 16);
		g_dt.map[0][ft_get_value(p->args[2] + 2)] =
				(unsigned char)(p->regs[p->args[1]] >> 8);
		g_dt.map[0][ft_get_value(p->args[2] + 3)] =
				(unsigned char)(p->regs[p->args[1]]);
		ft_write_col(p->number, p->args[2]);
		ft_write_bold(-50, p->args[2], 4);
	}
}

void	ft_st(t_process *p)
{
	if (g_dt.map[0][ft_get_value(p->mem_addres + 1)] == 112)
		ft_st01(p);
	else if (g_dt.map[0][ft_get_value(p->mem_addres + 1)] == 80)
	{
		ft_take_args(p, 0, g_dt.map[0][ft_get_value(p->mem_addres + 1)]);
		if (p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
				p->args[1] >= 0 && p->args[1] <= REG_NUMBER)
			p->regs[p->args[2]] = p->regs[p->args[1]];
	}
	else
		ft_take_args(p, 0, g_dt.map[0][ft_get_value(p->mem_addres + 1)]);
	ft_bzero(p->args, 16);
}
