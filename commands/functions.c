/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:35:57 by opariy            #+#    #+#             */
/*   Updated: 2017/10/28 13:35:58 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_and_or_xor_5(t_process *p, char op, char c)
{
	if (c == -12 && p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		p->args[1] = ft_take_ind(p->mem_addres - 7 + p->args[1] % IDX_MOD);
		p->args[2] = ft_take_ind(p->mem_addres - 7 + p->args[2] % IDX_MOD);
		if (op == 6)
			(p->regs[p->args[3]] = p->args[1] & p->args[2]);
		if (op == 7)
			(p->regs[p->args[3]] = p->args[1] | p->args[2]);
		if (op == 8)
			(p->regs[p->args[3]] = p->args[1] ^ p->args[2]);
		p->cary = (p->regs[p->args[3]] == 0) ? 1 : 0;
	}
	else if (c == -28 && p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		p->args[1] = ft_take_ind(p->mem_addres - 9 + p->args[1] % IDX_MOD);
		if (op == 6)
			(p->regs[p->args[3]] = p->args[1] & p->args[2]);
		if (op == 7)
			(p->regs[p->args[3]] = p->args[1] | p->args[2]);
		if (op == 8)
			(p->regs[p->args[3]] = p->args[1] ^ p->args[2]);
		p->cary = (p->regs[p->args[3]] == 0) ? 1 : 0;
	}
}

int		ft_take_args_2(t_process *process, int a)
{
	int res;

	if (a == 2)
		res = (short)(g_dt.map[0][ft_increment_index(process)] << 8) |
		g_dt.map[0][ft_increment_index(process)];
	else
		res = ((g_dt.map[0][ft_increment_index(process)] << 24) |
		(g_dt.map[0][ft_increment_index(process)] << 16) |
		(g_dt.map[0][ft_increment_index(process)] << 8) |
		(g_dt.map[0][ft_increment_index(process)]));
	return (res);
}

void	ft_take_args(t_process *process, int i, int com)
{
	process->mem_addres = ft_increment_index(process);
	process->args[0] = com;
	process->args[1] = g_dt.map[0][process->mem_addres] >> 6;
	process->args[2] = (g_dt.map[0][process->mem_addres]) << 2;
	process->args[2] = ((unsigned char)process->args[2]) >> 6;
	process->args[3] = g_dt.map[0][process->mem_addres] << 4;
	process->args[3] = ((unsigned char)process->args[3]) >> 6;
	i = 1;
	while (i < g_tab[com - 1].count_arg + 1)
	{
		if (process->args[i] == REG_CODE)
			process->args[i] = g_dt.map[0][ft_increment_index(process)] - 1;
		else if (process->args[i] == DIR_CODE)
		{
			if (com == 2 || com == 6 || com == 7 || com == 8 || com == 13)
				process->args[i] = ft_take_args_2(process, 4);
			else
				process->args[i] = ft_take_args_2(process, 2);
		}
		else if (process->args[i] == IND_CODE)
			process->args[i] = ft_take_args_2(process, 2);
		i++;
	}
	ft_increment_index(process);
	ft_putstr("args finish\n");
}
