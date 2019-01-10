/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 00:07:38 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 12:48:43 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			parse_bigflag_default_value(char *flagvalue, t_args *args)
{
	if (strcmp(flagvalue, "verbose") == 0)
		args->verbose_mode = ALL_VERBOSE;
	else
		print_usage();
}

void			parse_bigflag_given_value(char *flagvalue, t_args *args)
{
	if (ft_strcmp(flagvalue, "verbose") == '=')
		parse_verbose_mode(flagvalue, args);
	else
		print_usage();
}

void			parse_bigflag(char *flagvalue, t_args *args)
{
	if (ft_strchr(flagvalue, '=') == NULL)
		parse_bigflag_default_value(flagvalue, args);
	else
		parse_bigflag_given_value(flagvalue, args);
}
