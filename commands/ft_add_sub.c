/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 13:47:38 by opariy            #+#    #+#             */
/*   Updated: 2017/10/20 13:47:39 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		ft_add_sub(t_process *process, char sign)
{
	if (g_dt.map[0][process->mem_addres + 1] == 84)
	{
		ft_take_args(process, 0, g_dt.map[0][process->mem_addres]);
		if (process->args[1] >= 0 && process->args[1] <= REG_NUMBER && process->args[2] >= 0
			&& process->args[2] <= REG_NUMBER && process->args[3] >= 0 && process->args[3] <=
																REG_NUMBER)
		{
			if (sign == '-')
				process->regs[process->args[3]] = process->regs[process->args[1]] -	process->regs[process->args[2]];
			else
				process->regs[process->args[3]] = process->regs[process->args[1]] +	process->regs[process->args[2]];
			if (process->regs[process->args[3]] == 0)
				process->cary = 1;
			else
				process->cary = 0;
		}
	}
	else
		ft_increment_index(process);
	ft_bzero(process->args, 16);
}
