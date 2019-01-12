/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:37:39 by toliver           #+#    #+#             */
/*   Updated: 2019/01/12 15:12:30 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			main(int argc, char **argv)
{
	t_args		*args;
	t_env		*env;
	
	(void)argv;
	if (argc == 1)
		launch_editor();
	else 
	{
		args = args_parsing(argc, argv);
		env = rt_init(args);
		env->scene = parsing(args);
	}
	return (EXIT_SUCCESS);
}
