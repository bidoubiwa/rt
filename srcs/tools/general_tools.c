/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:16:23 by toliver           #+#    #+#             */
/*   Updated: 2019/01/09 19:37:00 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char				*string_to_lower(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

void				*ft_malloc(size_t size)
{
	void			*ptr;

	if (!(ptr = malloc(size)))
		ft_error(MALLOC_FAIL);
	ft_bzero(ptr, size);
	return (ptr);
}

void				ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
