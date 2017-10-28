/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_double_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:36:54 by ymushet           #+#    #+#             */
/*   Updated: 2017/06/16 14:36:58 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_malloc_double_str(int x, int y)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char*) * (y + 1));
	res[y] = NULL;
	while (i < y)
	{
		res[i] = ft_strnew((size_t)x);
		i++;
	}
	return (res);
}
