/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:22:32 by ymushet           #+#    #+#             */
/*   Updated: 2017/10/19 18:22:37 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H
# include "../corewar.h"

void	ft_live(t_process *process);
void	ft_ld(t_process *process);
void	ft_st(t_process *process);
void	ft_add(t_process *process);
void	ft_sub(t_process *process);
void	ft_xor_and_or(t_process *process);
void	ft_xor_and_or(t_process *process);
void	ft_xor_and_or(t_process *process);
void	ft_zjmp(t_process *process);
void	ft_ldi(t_process *p);
void	ft_sti(t_process *process);
void	ft_fork(t_process *p);
void	ft_lld(t_process *process);
void	ft_lldi(t_process *p);
void	ft_lfork(t_process *p);
void	ft_aff(t_process *process);
int		ft_take_ind(int index);
int		ft_get_ind(int value);
int		ft_increment_index(t_process *process);
void	ft_write_col(int num, int address);
void	ft_write_bold(int num, int start, int end);
int		ft_get_value(int ind);
void	ft_take_args(t_process *process, int i, int command);
void	ft_and_or_xor_5(t_process *p, char op, char c);

#endif
