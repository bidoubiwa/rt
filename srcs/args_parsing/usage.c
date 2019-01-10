/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 23:54:09 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 12:47:42 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			print_usage(void)
{
	ft_putstr_fd("usage: ./rtv1 [-d]", 2);
	ft_putstr_fd(" [--verbose[=VERBOSE_MODE]] ", 2);
	ft_error("file.json\n");
}

void			print_verbose_usage(void)
{
	ft_putstr_fd("rtv1: --verbose param incorrect, it can be :\n", 2);
	ft_putstr_fd("		--verbose : standard verbose on everything\n", 2);
	ft_putstr_fd("		--verbose=VALUE : VALUE can be :\n", 2);
	ft_putstr_fd("			0 : no verbose\n", 2);
	ft_putstr_fd("			1 : verbose on args_parsing\n", 2);
	ft_putstr_fd("			2 : verbose on init\n", 2);
	ft_putstr_fd("			3 : verbose on parsing\n", 2);
	ft_putstr_fd("			4 : verbose on settings\n", 2);
	ft_putstr_fd("			5 : verbose on running\n", 2);
	ft_putstr_fd("			6 : verbose on printing\n", 2);
	ft_putstr_fd("			7 : verbose on loop\n", 2);
	ft_putstr_fd("			8 : all of the above\n", 2);
	ft_error(NULL);
}
