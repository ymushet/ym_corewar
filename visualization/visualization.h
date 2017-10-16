//
// Created by Maksym Kaliberda on 14.10.17.
//

#ifndef __VISUALIZATION_H
#define __VISUALIZATION_H

# include <unistd.h>
# include <pthread.h>
# include <ncurses.h>
# include <curses.h>

# include "../corewar_vm_validation.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "ncurses.h"
# include "curses.h"
# include <pthread.h>
# define FIELD_Y

# define P1 1
# define P2 2
# define P3 3
# define P4 4
# define START 5
# define BORDER 6
# define P1CAR 11
# define P2CAR 12
# define P3CAR 13
# define P4CAR 14


typedef struct  s_visual
{
	WINDOW *gen_win;
	WINDOW *info;
	int     width_w;
	int     step;
	int     x;
	int     y;
	int     xg;
	int     xin;
	
}               t_vis;

t_vis        g_vh;


void	init_ncurses(void);
void    print_map(char **map);

void    ft_set_pair();

void set_color_on_map(int gen, int pl, int car);
void set_color_off_map(int gen, int pl, int car);
void   ft_adaptive();
#endif
