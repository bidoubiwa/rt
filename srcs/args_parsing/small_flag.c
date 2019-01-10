/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 00:06:58 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 12:48:36 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			parse_smallflag(char *flagvalue, t_args *args)
{
	int			i;

	i = 0;
	while (flagvalue[i])
	{
		if (ft_strchr(SHORT_FLAGS, flagvalue[i]) == NULL)
			print_usage();
		else
		{
			if (flagvalue[i] == 'd')
				args->debug_mode = 1;
		}
		i++;
	}
}
