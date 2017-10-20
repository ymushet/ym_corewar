/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_plushki.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 19:20:21 by mkaliber          #+#    #+#             */
/*   Updated: 2017/10/19 19:20:25 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../corewar.h"

void    ft_pause_first()
{
	int s;
	
	while (g_vh.pause == 1)
	{
		usleep(1);
		s = wgetch(stdscr);
		if (s == 32)
			g_vh.pause = 0;
	}
}

void    ft_pause(int c)
{
	int s;
	
	if (c == 32 && g_vh.pause == 0)
	{
		g_vh.pause = 1;
		while (g_vh.pause == 1)
		{
			usleep(1);
			s = wgetch(stdscr);
			if (s == 32)
				g_vh.pause = 0;
		}
	}
}

void    gen_key()
{
	int c;
	c = wgetch(stdscr);
	ft_pause(c);
}