/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:22:30 by ymushet           #+#    #+#             */
/*   Updated: 2017/04/13 20:16:02 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_struct	*ft_static_struct(int fd, t_struct **head)
{
	t_struct	*tmp;

	tmp = *head;
	if (tmp != NULL)
	{
		while ((tmp != NULL) && (tmp->fd != fd))
			tmp = tmp->next;
		if (tmp && tmp->fd == fd)
			return (tmp);
	}
	if (tmp == NULL)
	{
		tmp = malloc(sizeof(t_struct));
		tmp->fd = fd;
		tmp->line = NULL;
		tmp->next = NULL;
	}
	*head != NULL ? tmp->next = *head : 0;
	*head = tmp;
	return (*head);
}

char		*ft_check_balance(char **str)
{
	char	*line;
	char	*tmp;
	char	*tmp2;

	if (*str == NULL)
		return (NULL);
	if ((tmp = ft_strchr(*str, '\n')) != NULL)
	{
		line = ft_strncpy(ft_strnew(tmp - *str), *str, tmp - *str);
		tmp2 = ft_strdup(tmp + 1);
		ft_strdel(&(*str));
		*str = tmp2;
		return (line);
	}
	return (tmp);
}

char		*ft_get_line(char *buff, t_struct *balance)
{
	char	*line;
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	tmp = NULL;
	line = NULL;
	if ((tmp = ft_strchr(buff, '\n')) != NULL)
	{
		tmp2 = ft_strncpy(ft_strnew(tmp - buff), buff, tmp - buff);
		line = ft_strjoin(balance->line, tmp2);
		ft_strdel(&tmp2);
		ft_strdel(&balance->line);
		balance->line = ft_strdup((tmp + 1));
		return (line);
	}
	balance->line != NULL ? tmp = ft_strdup(balance->line) : 0;
	ft_strdel(&balance->line);
	balance->line = ft_strjoin(tmp, buff);
	ft_strdel(&tmp);
	return (NULL);
}

int			get_next_line(int fd, char **line)
{
	static t_struct	*head = NULL;
	t_struct		*balance;
	char			buff[BUFF_SIZE + 1];

	if (read(fd, NULL, 0) == -1)
		return (-1);
	balance = ft_static_struct(fd, &head);
	if ((*line = ft_check_balance(&balance->line)) != NULL)
		return (1);
	ft_bzero(buff, BUFF_SIZE + 1);
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		if ((*line = ft_get_line(buff, balance)) != NULL)
			return (1);
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	*line = ft_strjoin(balance->line, buff);
	if (ft_strcmp(*line, "") == 0)
		return (0);
	ft_strdel(&balance->line);
	balance->line = ft_strdup("");
	return (1);
}
