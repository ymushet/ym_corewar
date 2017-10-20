/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_vis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:33:01 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/19 18:33:03 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../corewar.h"


void   ft_putstr_vis(char *str)
{
	int x,y = 0;
	g_vh.term_i = 1;
	
	int i = 0;
	int n = 0;
	char *term;
	term = ft_strnew(1);
	wattron(g_vh.term, COLOR_PAIR(P4));
	mvwprintw(g_vh.term, g_vh.term_i, 1, "%s",  str);
	wattroff(g_vh.term, COLOR_PAIR(P4));
	wattron(g_vh.term, COLOR_PAIR(BORDER));
	wborder(g_vh.term, '.', '.', '.', '.', '.', '.', '.', '.');
	wattroff(g_vh.term, COLOR_PAIR(BORDER));
	if (g_vh.term_i > 17)
	{
		g_vh.term_i = 0;
		wclear(g_vh.term);
		wattron(g_vh.term, COLOR_PAIR(BORDER));
		wborder(g_vh.term, '.', '.', '.', '.', '.', '.', '.', '.');
		wattroff(g_vh.term, COLOR_PAIR(BORDER));
		wrefresh(g_vh.term);
	}
	g_vh.term_i++;
	wrefresh(g_vh.term);
	i++;
	
}
