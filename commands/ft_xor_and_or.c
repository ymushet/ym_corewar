/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:18:56 by opariy            #+#    #+#             */
/*   Updated: 2017/10/20 17:18:57 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void		ft_and_or_xor_5(t_process *process, char op, char c)
{
	if (c == -12 && process->args[3] >= 0 && process->args[3] <= REG_NUMBER)
	{
		process->args[1] = ft_take_ind(process->mem_addres - 7 + process->args[1] % IDX_MOD);
		process->args[2] = ft_take_ind(process->mem_addres - 7 + process->args[2] % IDX_MOD);
		(op == 6) ? (process->regs[process->args[3]] = process->args[1] & process->args[2]) : 0;
		(op == 7) ? (process->regs[process->args[3]] = process->args[1] | process->args[2]) : 0;
		(op == 8) ? (process->regs[process->args[3]] = process->args[1] ^ process->args[2]) : 0;
		process->cary = (process->regs[process->args[3]] == 0) ? 1 : 0;
	}
	else if (c == -28 && process->args[3] >= 0 && process->args[3] <= REG_NUMBER)
	{
		process->args[1] = ft_take_ind(process->mem_addres - 9 + process->args[1] % IDX_MOD);
		(op == 6) ? (process->regs[process->args[3]] = process->args[1] & process->args[2]) : 0;
		(op == 7) ? (process->regs[process->args[3]] = process->args[1] | process->args[2]) : 0;
		(op == 8) ? (process->regs[process->args[3]] = process->args[1] ^ process->args[2]) : 0;
		process->cary = (process->regs[process->args[3]] == 0) ? 1 : 0;
	}
}

void	ft_and_or_xor_1(t_process *process, char op)
{
	if (process->args[1] >= 0 && process->args[1] <= REG_NUMBER && process->args[2] >= 0 &&
		process->args[2] <= REG_NUMBER && process->args[3] && process->args[3] <= REG_NUMBER)
	{
		(op == 6) ? (process->regs[process->args[3]] = process->regs[process->args[1]] & process->regs[process->args[2]])
				  : 0;
		(op == 7) ? (process->regs[process->args[3]] = process->regs[process->args[1]] | process->regs[process->args[2]])
				  : 0;
		(op == 8) ? (process->regs[process->args[3]] = process->regs[process->args[1]] ^ process->regs[process->args[2]])
				  : 0;
		process->cary = (process->regs[process->args[3]] == 0) ? 1 : 0;
	}
}

void	ft_and_or_xor_2(t_process *process, char op, char c)
{
	if (c == -108 && process->args[2] >= 0 && process->args[2] <= REG_NUMBER && process->args[3]
																  >= 0 && process->args[3] <= REG_NUMBER)
	{
		(op == 6) ? (process->regs[process->args[3]] = process->args[1] & process->regs[process->args[2]]) : 0;
		(op == 7) ? (process->regs[process->args[3]] = process->args[1] | process->regs[process->args[2]]) : 0;
		(op == 8) ? (process->regs[process->args[3]] = process->args[1] ^ process->regs[process->args[2]]) : 0;
		process->cary = (process->regs[process->args[3]] == 0) ? 1 : 0;
	}
	else if (c == -44 && process->args[2] >= 0 && process->args[2] <= REG_NUMBER && process->args[3]
																	  >= 0 && process->args[3] <= REG_NUMBER)
	{
		process->args[1] = ft_take_ind(process->mem_addres - 6 + process->args[1] % IDX_MOD);
		(op == 6) ? (process->regs[process->args[3]] = process->args[1] & process->regs[process->args[2]]) : 0;
		(op == 7) ? (process->regs[process->args[3]] = process->args[1] | process->regs[process->args[2]]) : 0;
		(op == 8) ? (process->regs[process->args[3]] = process->args[1] ^ process->regs[process->args[2]]) : 0;
		process->cary = (process->regs[process->args[3]] == 0) ? 1 : 0;
	}
}

void	ft_and_or_xor_3(t_process *process, char op, char c)
{
	if (c == 116 && process->args[1] >= 0 && process->args[1] <= REG_NUMBER && process->args[3] >= 0
		&& process->args[3] <= REG_NUMBER)
	{
		process->args[2] = ft_take_ind(process->mem_addres - 6 + process->args[2] % IDX_MOD);
		(op == 6) ? (process->regs[process->args[3]] = process->regs[process->args[1]] & process->args[2]) : 0;
		(op == 7) ? (process->regs[process->args[3]] = process->regs[process->args[1]] | process->args[2]) : 0;
		(op == 8) ? (process->regs[process->args[3]] = process->regs[process->args[1]] ^ process->args[2]) : 0;
//		printf("hre %d\n", process->regs[3]);
		process->cary = (process->regs[process->args[3]] == 0) ? 1 : 0;
	}
	else if (c == 100 && process->args[1] >= 0 && process->args[1] <= REG_NUMBER && process->args[3]
																	  >= 0 && process->args[3] <= REG_NUMBER)
	{
//		printf("args1 args2: %d %d\n", process->args[1], process->args[2]);
		(op == 6) ? (process->regs[process->args[3]] = process->regs[1] & process->args[2]) : 0;
		(op == 7) ? (process->regs[process->args[3]] = process->regs[1] | process->args[2]) : 0;
		(op == 8) ? (process->regs[process->args[3]] = process->regs[1] ^ process->args[2]) : 0;
//		printf("process->regs[process->args[3]]: %d\n", process->regs[process->args[3]]);
//		printf("regs %d %d %d %d\n", process->regs[0], process->regs[1], process->regs[2], process->regs[3]);
		process->cary = (process->regs[process->args[3]] == 0) ? 1 : 0;
	}
}

void	ft_and_or_xor_4(t_process *process, char op, char c)
{
	if (c == -76 && process->args[3] >= 0 && process->args[3] <= REG_NUMBER)
	{
		process->args[2] = ft_take_ind(process->mem_addres - 9 + process->args[2] % IDX_MOD);
		(op == 6) ? (process->regs[process->args[3]] = process->args[1] & process->args[2]) : 0;
		(op == 7) ? (process->regs[process->args[3]] = process->args[1] | process->args[2]) : 0;
		(op == 8) ? (process->regs[process->args[3]] = process->args[1] ^ process->args[2]) : 0;
		process->cary = (process->regs[process->args[3]] == 0) ? 1 : 0;
	}
	else if (c == -92 && process->args[3] >= 0 && process->args[3] <= REG_NUMBER)
	{
//		printf("hre\n");
		(op == 6) ? (process->regs[process->args[3]] = process->args[1] & process->args[2]) : 0;
		(op == 7) ? (process->regs[process->args[3]] = process->args[1] | process->args[2]) : 0;
		(op == 8) ? (process->regs[process->args[3]] = process->args[1] ^ process->args[2]) : 0;
		process->cary = (process->regs[process->args[3]] == 0) ? 1 : 0;
	}
}

void	ft_xor_and_or(t_process *process)
{
	char operation;
	char op_code;

//	printf("com %d\n", g_dt.map[0][process->mem_addres]);
//	printf("byte %d\n", g_dt.map[0][process->mem_addres + 1]);
	operation = g_dt.map[0][process->mem_addres];
	op_code = g_dt.map[0][ft_get_value(process->mem_addres + 1)];
	if (op_code == 84 || op_code == -108 || op_code == -44 || op_code == 116 ||
		op_code == 100 || op_code == -76 || op_code == -92 || op_code == -12 ||
		op_code == -28)
		ft_take_args(process, 0, g_dt.map[0][process->mem_addres]);
//	printf("args: %d, %d, %d, %d\n", process->args[0], process->args[1], process->args[2], process->args[3]);
	if (op_code == 84)
		ft_and_or_xor_1(process, operation);
	else if (op_code == -108 || op_code == -44)
		ft_and_or_xor_2(process, operation, op_code);
	else if (op_code == 116 || op_code == 100)
		ft_and_or_xor_3(process, operation, op_code);
	else if (op_code == -76 || op_code == -92)
	{
//		printf("hre\n");
		ft_and_or_xor_4(process, operation, op_code);
	}
	else if (op_code == -12 || op_code == -28)
		ft_and_or_xor_5(process, operation, op_code);
	else
		ft_increment_index(process);
	ft_bzero(process->args, 16);
}