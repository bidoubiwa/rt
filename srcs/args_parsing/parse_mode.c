/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 03:35:36 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 12:48:24 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			parse_verbose_mode(char *flagvalue, t_args *args)
{
	char		*value;
	int			final_val;

	final_val = -1;
	value = ft_strchr(flagvalue, '=') + 1;
	if (value[0] < '0' || value[0] > '9' || value[1]
			|| (final_val = ft_atoi(value)) >= MAX_VERBOSE_MODE)
		print_verbose_usage();
	args->verbose_mode = final_val;
}
