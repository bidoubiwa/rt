/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 00:42:05 by toliver           #+#    #+#             */
/*   Updated: 2019/01/14 17:53:28 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int					key_pressed(int key, t_env *env)
{
	if (key == X_KEY_ESCAPE)
	{
		free_env_rt(env);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int					window_closed(t_env *env)
{
	ft_putstr_fd("Espece de barbare, go utiliser echap !\n", 2);
	free_env_rt(env);
	exit(EXIT_SUCCESS);
	return (0);
}

void				rt_loop(t_args *args, t_env *env)
{
	int running = 1;
	SDL_Event event;

	while (running)
	{
		while(SDL_PollEvent(&event))
			if((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type && SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
				running = 0;
//		SDL_RenderPresent(env->window->renderer);
	}
	env->args = args;
	if (args->verbose_mode == LOOP || args->verbose_mode == ALL_VERBOSE)
		verbose_loop(args, env);
	free_env_rt(env);
}
