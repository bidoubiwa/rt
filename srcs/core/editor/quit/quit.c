/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 02:17:20 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 02:45:13 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		free_env(t_enve *env)
{
	free(env);
}

void		delete_window(t_enve *env)
{
	SDL_DestroyRenderer(env->window.renderer);
	SDL_DestroyWindow(env->window.win);
}

void		quit_libs(t_enve *env)
{
	(void)env;
	SDL_Quit();
}

void		quit(t_enve *env)
{
	delete_window(env);
	quit_libs(env);
	free_env(env);
}
