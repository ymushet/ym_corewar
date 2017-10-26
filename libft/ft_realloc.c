/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymushet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 12:52:11 by ymushet           #+#    #+#             */
/*   Updated: 2017/04/13 20:15:46 by ymushet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new, size_t old)
{
	void *res;

	res = NULL;
	if (!ptr && new > 0)
	{
		res = malloc(new);
		res = ft_memmove(res, ptr, old);
		free(ptr);
	}
	else if (ptr)
	{
		return (malloc(new));
	}
	else if (new == 0)
	{
		free(ptr);
	}
	return (res);
}
