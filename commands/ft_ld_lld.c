/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:31:07 by opariy            #+#    #+#             */
/*   Updated: 2017/10/20 16:31:08 by opariy           ###   ########.fr       */
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

void	ft_lld(t_process *process, char c)
{
	if (g_dt.map[0][process->mem_addres + 1] == -48)
	{
		if (c != 'l')
			process->args[1] %= IDX_MOD;
		ft_take_args(process, 0, g_dt.map[0][process->mem_addres]);
		if (process->args[2] >= 0 && process->args[2] <= REG_NUMBER)
		{
			process->regs[process->args[2]] = (unsigned int)ft_take_ind(process->mem_addres
													   - 5 + process->args[1]);
			process->cary = (process->regs[process->args[2]] == 0) ? 1 : 0;
		}
	}
	else if (g_dt.map[0][process->mem_addres + 1] == -112)
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










