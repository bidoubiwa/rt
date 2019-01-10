/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_args_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 03:27:46 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 12:07:19 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			print_args_files(char **files)
{
	int			i;

	i = 0;
	if (files == NULL || files[0] == NULL)
		ft_printf("	There are no files\n");
	else
	{
		ft_printf("	Files in argument are :\n");
		while (files[i])
		{
			ft_printf("		- %s\n", files[i]);
			i++;
		}
	}
	ft_printf("\n");
}
