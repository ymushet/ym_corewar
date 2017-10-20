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
#include "../corewar.h"

void ft_live(t_process *process);
void ft_ld(t_process *process);
void ft_st(t_process *process);
void ft_and(t_process *process);
void ft_or(t_process *process);
void ft_xor(t_process *process);
void ft_zjmp(t_process *process);
void ft_sti(t_process *process);
void	ft_lld(t_process *process, char c);
void ft_aff(t_process *process);
void ft_zjump(t_process *process);
void	ft_add_sub(t_process *process, char sign);
void 	ft_aff(t_process *process);
void	ft_lfork_fork(t_process *process, char l);
void	ft_zjump(t_process *process);
int		ft_take_ind(int index);
#endif