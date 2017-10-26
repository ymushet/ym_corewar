/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:35:09 by ymushet           #+#    #+#             */
/*   Updated: 2017/02/01 19:39:56 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# define BUFF_SIZE 50
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include "libft.h"

typedef struct		s_struct
{
	int				fd;
	char			*line;
	struct s_struct	*next;
}					t_struct;

t_struct			*ft_static_struct(int fd, t_struct **head);
char				*ft_get_line(char *buff, t_struct *balance);
char				*ft_check_balance(char **str);
int					get_next_line(const int fb, char **line);
#endif
