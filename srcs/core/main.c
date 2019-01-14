/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:37:39 by toliver           #+#    #+#             */
/*   Updated: 2019/01/14 16:37:47 by cvermand         ###   ########.fr       */
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
		rt_settings(args, env);
		rt_running(args, env->scene);
		rt_printing(args, env->scene, env->window);
		rt_loop(args, env);
	}
	return (EXIT_SUCCESS);
}
