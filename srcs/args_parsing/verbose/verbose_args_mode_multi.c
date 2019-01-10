/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_args_mode_multi.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 03:28:10 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 12:07:38 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static char		*verbose_mode_string(int mode)
{
	if (mode == ARGS_PARSING)
		return ("ARGS_PARSING");
	if (mode == INIT)
		return ("INIT");
	if (mode == PARSING)
		return ("PARSING");
	if (mode == SETTINGS)
		return ("SETTINGS");
	if (mode == RUNNING)
		return ("RUNNING");
	if (mode == PRINTING)
		return ("PRINTING");
	if (mode == LOOP)
		return ("LOOP");
	return ("ERROR, BAD VERBOSE MODE !\n");
}

void			print_verbose_mode(int mode)
{
	char		*value;

	value = NULL;
	if (mode == NO_VERBOSE)
		ft_printf("	Verbose is OFF (should be impossible)\n");
	else if (mode >= MAX_VERBOSE_MODE)
		ft_printf("	Verbose is higher than verbose max !\n");
	else if (mode == ALL_VERBOSE)
		ft_printf("	Verbose is ON for all steps\n");
	else
	{
		value = verbose_mode_string(mode);
		ft_printf("	Verbose is ON for %s\n", value);
	}
}
