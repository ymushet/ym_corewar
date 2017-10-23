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
	int 	i;

	i = -1;
	while (++i < end)
		g_dt.map[2][ft_get_value(start + i)] = (unsigned char)(-num);
}

void 			ft_write_col(int num, int address)
{
	g_dt.map[1][ft_get_value(address)] = (unsigned char)(num + 64);
	g_dt.map[1][ft_get_value(address + 1)] = (unsigned char)(num + 64);
	g_dt.map[1][ft_get_value(address + 2)] = (unsigned char)(num + 64);
	g_dt.map[1][ft_get_value(address + 3)] = (unsigned char)(num + 64);
}

void		ft_sti_01(t_process *p, char codage_octal, int i)
{
	if (codage_octal == 88 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
		p->args[2] >= 0 && p->args[2] <= REG_NUMBER)
	{
		i += (p->regs[p->args[2]] + p->args[3]) % IDX_MOD;
		g_dt.map[0][ft_get_value(i)] = (unsigned char)p->regs[p->args[1]] >> 24;
		g_dt.map[0][ft_get_value(i + 1)] = (unsigned char)p->regs[p->args[1]] >> 16;
		g_dt.map[0][ft_get_value(i + 2)] = (unsigned char)p->regs[p->args[1]] >> 8;
		g_dt.map[0][ft_get_value(i + 3)] = (unsigned char)p->regs[p->args[1]];
		ft_write_col(p->number, i);
		ft_write_bold(-50, i, 4);
	}
	else if (codage_octal == 84 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
			 p->args[2] >= 0 && p->args[2] <= REG_NUMBER && p->args[3] >= 0 &&
			 p->args[3] <= REG_NUMBER)
	{
		i += (p->regs[p->args[2]] + p->regs[p->args[3]]) % IDX_MOD;
		g_dt.map[0][ft_get_value(i)] = (unsigned char)p->regs[p->args[1]] >> 24;
		g_dt.map[0][ft_get_value(i + 1)] = (unsigned char)p->regs[p->args[1]] >> 16;
		g_dt.map[0][ft_get_value(i + 2)] = (unsigned char)p->regs[p->args[1]] >> 8;
		g_dt.map[0][ft_get_value(i + 3)] = (unsigned char)p->regs[p->args[1]];
		ft_write_col(p->number, i);
		ft_write_bold(-50, i, 4);
	}
}

int 	ft_increment_index(t_process *process)
{
	process->mem_addres = (process->mem_addres + 1) % MEM_SIZE;
	return (process->mem_addres);
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

void	ft_take_args(t_process *process, int i, int command)
{
	printf("in take args: command %d\n", command);
	printf("in take args: mem address %d\n", process->mem_addres);
	printf("in take args: args1 : %d, %d, %d, %d\n", process->args[0], process->args[1], process->args[2], process->args[3]);
//	process->mem_addres = ft_increment_index(process);
	process->args[0] = command;
	process->args[1] = g_dt.map[0][process->mem_addres] >> 6;
	process->args[2] = (g_dt.map[0][process->mem_addres]) << 2;
	process->args[2] = ((unsigned char)process->args[2]) >> 6;
	process->args[3] = g_dt.map[0][process->mem_addres] << 4;
	process->args[3] = ((unsigned char)process->args[3]) >> 6;
	printf("in take args args2: %d, %d, %d, %d\n", process->args[0], process->args[1], process->args[2], process->args[3]);
	i = 1;
	while (i < 4)
	{
		if (process->args[i] == REG_CODE)
		{
//			process->args[i] = g_dt.map[0][ft_increment_index(process)] - 1;
			process->args[i] = g_dt.map[0][ft_increment_index(process)];

		}
		else if (process->args[i] == DIR_CODE)
		{
			if (command == 2 || command == 6 || command == 7 || command == 8 ||	command == 13)
				process->args[i] = ft_take_args_2(process, 4);
			else
				process->args[i] = ft_take_args_2(process, 2);
		}
		else if (process->args[i] == IND_CODE)
		{
//			printf("arg[i]= %d\n",process->args[i]);
			process->args[i] = ft_take_args_2(process, 2);
//			printf("arg[i]= %d\n",process->args[i]);

		}
		i++;
	}
	printf("in take args args3: %d, %d, %d, %d\n", process->args[0], process->args[1], process->args[2], process->args[3]);

//	printf("arg[] %d %d %d %d\n", process->args[0], process->args[1], process->args[2], process->args[3]);
	ft_increment_index(process);
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

static void		ft_sti_03(t_process *p, char op_code, int i)
{
	if (op_code == 120 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER)
	{
		p->args[2] = ft_get_ind(i + p->args[2] % IDX_MOD);
		i += (p->args[2] + p->args[3]) % IDX_MOD;
		g_dt.map[0][ft_get_value(i)] = (unsigned char)p->regs[p->args[1]] >> 24;
		g_dt.map[0][ft_get_value(i + 1)] = (unsigned char)p->regs[p->args[1]] >> 16;
		g_dt.map[0][ft_get_value(i + 2)] = (unsigned char)p->regs[p->args[1]] >> 8;
		g_dt.map[0][ft_get_value(i + 3)] = (unsigned char)p->regs[p->args[1]];
		ft_write_col(p->number, i);
		ft_write_bold(-50, i, 4);
	}
	else if (op_code == 116 && p->args[1] >= 0 && p->args[1] <= REG_NUMBER &&
			 p->args[3] >= 0 && p->args[3] <= REG_NUMBER)
	{
		p->args[2] = ft_get_ind(i + p->args[2] % IDX_MOD);
		i += (p->args[2] + p->regs[p->args[3]]) % IDX_MOD;
		g_dt.map[0][ft_get_value(i)] = (unsigned char)p->regs[p->args[1]] >> 24;
		g_dt.map[0][ft_get_value(i + 1)] = (unsigned char)p->regs[p->args[1]] >> 16;
		g_dt.map[0][ft_get_value(i + 2)] = (unsigned char)p->regs[p->args[1]] >> 8;
		g_dt.map[0][ft_get_value(i + 3)] = (unsigned char)p->regs[p->args[1]];
		ft_write_col(p->number, i);
		ft_write_bold(-50, i, 4);
	}
}



static void		ft_sti_02(t_process *process, char op_code, int i)
{
	if (op_code == 104 && process->args[1] >= 0 && process->args[1] <= REG_NUMBER)
	{
//		printf("regs %d, %d, %d, %d\n", process->regs[0], process->regs[1], process->regs[2], process->regs[3]);
		i += (process->args[2] + process->args[3]) % IDX_MOD;
//		printf("i is %d\n", i);
		g_dt.map[0][ft_get_value(i)] = (unsigned char)process->regs[process->args[1]] >> 24;
//		printf("ft_get_value(i) %d\n ", (unsigned char)process->regs[process->args[1]] >> 24);
		g_dt.map[0][ft_get_value(i + 1)] = (unsigned char)process->regs[process->args[1]] >> 16;
		g_dt.map[0][ft_get_value(i + 2)] = (unsigned char)process->regs[process->args[1]] >> 8;
		g_dt.map[0][ft_get_value(i + 3)] = (unsigned char)process->regs[process->args[1]];
		ft_write_col(process->number, i);
		ft_write_bold(-50, i, 4);
	}
	else if (op_code == 100 && process->args[1] >= 0 && process->args[1] <= REG_NUMBER &&
			 process->args[3] >= 0 && process->args[3] <= REG_NUMBER)
	{
		i += (process->args[2] + process->regs[process->args[3]]) % IDX_MOD;
		g_dt.map[0][ft_get_value(i)] = (unsigned char)process->regs[process->args[1]] >> 24;
		g_dt.map[0][ft_get_value(i + 1)] = (unsigned char)process->regs[process->args[1]] >> 16;
		g_dt.map[0][ft_get_value(i + 2)] = (unsigned char)process->regs[process->args[1]] >> 8;
		g_dt.map[0][ft_get_value(i + 3)] = (unsigned char)process->regs[process->args[1]];
		ft_write_col(process->number, i);
		ft_write_bold(-50, i, 4);
	}
}

void		ft_sti(t_process *process)
{
	char 	codage_octal;
	int 	i;

	i = process->mem_addres;
	codage_octal = g_dt.map[0][ft_increment_index(process)];
	printf("codage_octal %d\n", codage_octal);
	printf("mem address %d\n", process->mem_addres);
	if (codage_octal == 88 || codage_octal == 84 || codage_octal == 104 || codage_octal == 100 ||
		codage_octal == 120 || codage_octal == 116)
		ft_take_args(process, 1, g_dt.map[0][i]);
	printf("args : %d, %d, %d, %d\n", process->args[0], process->args[1], process->args[2], process->args[3]);
	if (codage_octal == 88 || codage_octal == 84)
		ft_sti_01(process, codage_octal, i);
	else if (codage_octal == 104 || codage_octal == 100) ////
		ft_sti_02(process, codage_octal, i);
	else if (codage_octal == 120 || codage_octal == 116)
		ft_sti_03(process, codage_octal, i);
	else
		process->mem_addres = ft_increment_index(process);
	ft_bzero(process->args, 16);
}