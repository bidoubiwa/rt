/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 02:14:00 by toliver           #+#    #+#             */
/*   Updated: 2019/01/14 16:07:44 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

t_enve		*env_init(void)
{
	t_enve	*env;

	env = (t_enve*)ft_malloc(sizeof(t_enve));
	return (env);
}

void		init_libs(t_enve *env)
{
	(void)env;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_error("SDL init failed !\n");
}

void		init_window(t_enve *env)
{
	env->window.win = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
	if (env->window.win == NULL)
		ft_error("Window init failed !\n");
	SDL_GetWindowSize(env->window.win, &env->window.width, &env->window.height);
	env->window.renderer = SDL_CreateRenderer(env->window.win, -1, 0);
	if (env->window.renderer == NULL)
		ft_error("Renderer init failed !\n");
	ft_printf("x = %d y = %d\n", env->window.width, env->window.height);
}

void		init_ui(t_enve *env)
{
	(void)env;
}

t_enve		*init(void)
{
	t_enve	*env;

	env = env_init();
	init_libs(env);
	init_window(env);
	init_ui(env);
	return (env);
}
