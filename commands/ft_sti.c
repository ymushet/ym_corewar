/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:15:35 by opariy            #+#    #+#             */
/*   Updated: 2017/10/19 16:15:36 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void			ft_sti_load(t_process *p, char op_code, int i)
{
	g_dt.map[0][ft_get_value(i)] = p->regs[p->args[1]] >> 24;
	g_dt.map[0][ft_get_value(i + 1)] = p->regs[p->args[1]] >> 16;
	g_dt.map[0][ft_get_value(i + 2)] = p->regs[p->args[1]] >> 8;
	g_dt.map[0][ft_get_value(i + 3)] = p->regs[p->args[1]];
	ft_write_col(p->number, i);
	ft_write_bold(-50, i, 4);
}

static void		ft_sti_03(t_process *p, char op_code, int i)
{
	if (op_code == 120 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER)
	{
		p->args[2] = ft_get_ind(i + p->args[2] % IDX_MOD);
		i += (int)(p->args[2] + p->args[3]) % IDX_MOD;
		ft_sti_load(p, op_code, i);
	}
	else if (op_code == 116 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
	p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		p->args[2] = ft_get_ind(i + p->args[2] % IDX_MOD);
		i += (int)(p->args[2] + p->regs[p->args[3]]) % IDX_MOD;
		ft_sti_load(p, op_code, i);
	}
}

static void		ft_sti_02(t_process *p, char op_code, int i)
{
	if (op_code == 104 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER)
	{
		i += (int)(p->args[2] + p->args[3]) % IDX_MOD;
		ft_sti_load(p, op_code, i);
	}
	else if (op_code == 100 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
		p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		i += (int)(p->args[2] + p->regs[p->args[3]]) % IDX_MOD;
		ft_sti_load(p, op_code, i);
	}
}

void			ft_sti_01(t_process *p, char op_code, int i)
{
	if (op_code == 88 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
		p->args[2] >= 0 && p->args[2] <= REG_NUMBER)
	{
		i += (int)(p->regs[p->args[2]] + p->args[3]) % IDX_MOD;
		ft_sti_load(p, op_code, i);
	}
	else if (op_code == 84 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
		p->args[2] >= 0 && p->args[2] <= REG_NUMBER && p->args[3] >= 0 &&
		p->args[3] <= REG_NUMBER)
	{
		i += (int)(p->regs[p->args[2]] + p->regs[p->args[3]]) % IDX_MOD;
		ft_sti_load(p, op_code, i);
	}
}

void			ft_sti(t_process *process)
{
	char	codage_octal;
	int		i;

	i = process->mem_addres;
	codage_octal = g_dt.map[0][ft_get_value(process->mem_addres + 1)];
	if (codage_octal == 88 || codage_octal == 84 || codage_octal == 104 ||
			codage_octal == 100 || codage_octal == 120 || codage_octal == 116)
		ft_take_args(process, 1, g_dt.map[0][i]);
	if (codage_octal == 88 || codage_octal == 84)
		ft_sti_01(process, codage_octal, i);
	else if (codage_octal == 104 || codage_octal == 100)
		ft_sti_02(process, codage_octal, i);
	else if (codage_octal == 120 || codage_octal == 116)
		ft_sti_03(process, codage_octal, i);
	else
		ft_take_args(process, 0, g_dt.map[0][process->mem_addres]);
//		process->mem_addres = ft_increment_index(process);
	ft_bzero(process->args, 16);
}
