/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:47:49 by opariy            #+#    #+#             */
/*   Updated: 2017/10/20 14:47:51 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

t_process *ft_create_car(unsigned int pos, unsigned int num, t_process *process)
{
	t_process	*new_p;

	new_p = (t_process *)malloc(sizeof(t_process));
	new_p->mem_addres = pos;
	new_p->number = process->number;
	new_p->f = NULL;
	new_p->exec_cycle = -1;
	new_p->alive = process->alive;
	new_p->command= 0;
	new_p->codage_octal = 0;
	new_p->next = NULL;
	ft_bzero(new_p->regs, 4 * REG_NUMBER);
	if (process)
	{
		ft_memcpy(new_p->regs, process->regs, 4 * REG_NUMBER);
		new_p->cary = process->cary;
		new_p->number = (char)new_p->regs[1];
	}
	else
	{
		new_p->regs[1] = num;
		new_p->number = (char)num;
		new_p->cary = 0;
	}
	return (new_p);
}

void	ft_lfork_fork(t_process *process, char l)
{
	t_process *new_p;

	ft_increment_index(process);
	process->args[1] = (short)(g_dt.map[0][ft_increment_index(process)]
			<< 8) | g_dt.map[0][ft_increment_index(process)];
	if (l == 'l')
	{
		process->args[1] = ft_get_value(process->mem_addres + process->args[1]);
		new_p = ft_create_car(process->args[1], process->regs[1], process);
	}
	else
	{
		process->args[1] = ft_get_value((process->mem_addres - 3) + (process->args[1] % IDX_MOD));
		new_p = ft_create_car(process->args[1], process->number, process);
	}
	g_dt.count_processes++;
	new_p->next = g_dt.process_g;
	g_dt.process_g = new_p;
	ft_bzero(process->args, 16);
}