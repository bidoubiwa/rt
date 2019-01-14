/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:37:52 by toliver           #+#    #+#             */
/*   Updated: 2019/01/14 18:44:13 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				rt_win_init(t_args *args, t_env *env)
{
	(void)args;
	env->window = (t_win*)ft_malloc(sizeof(t_win));
	env->window->win = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WINX, WINY, SDL_WINDOW_OPENGL); // ici changer les flags pour virer le fullscreen
	if (env->window->win == NULL)
		ft_error("Window init failed !\n");
	SDL_GetWindowSize(env->window->win, &env->window->width, &env->window->height);
	env->window->renderer = SDL_CreateRenderer(env->window->win, -1, 0);
	if (env->window->renderer == NULL)
		ft_error("Renderer init failed !\n");
	ft_printf("x = %d y = %d\n", env->window->width, env->window->height);
}


t_env				*rt_env_init(t_args *args)
{
	t_env			*env;

	(void)args;
	env = (t_env*)ft_malloc(sizeof(t_env));
	env->scene = NULL;
	rt_win_init(args, env);
	return (env);
}

t_env				*rt_init(t_args *args)
{
	t_env			*env;

	env = rt_env_init(args);
	if (args->verbose_mode == INIT || args->verbose_mode == ALL_VERBOSE)
		verbose_env(env);
	return (env);
}
