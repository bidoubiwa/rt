/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:50:27 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 12:48:53 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_args			*args_init(void)
{
	t_args		*args;

	args = (t_args*)ft_malloc(sizeof(t_args));
	args->verbose_mode = NO_VERBOSE;
	args->debug_mode = 0;
	args->files = NULL;
	return (args);
}

t_args			*args_parsing(int ac, char **av)
{
	t_args		*args;

	args = args_init();
	parse_arguments(ac, av, args);
	if (args->verbose_mode == ARGS_PARSING || args->verbose_mode == ALL_VERBOSE)
		verbose_args(args);
	return (args);
}
