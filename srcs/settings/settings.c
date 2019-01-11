/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 06:28:16 by toliver           #+#    #+#             */
/*   Updated: 2019/01/11 19:29:52 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			renderers_settings(t_args *args, t_env *env)
{
	t_scene		*scenes;
	t_obj		*cameras;

	scenes = env->scene;
	while (scenes)
	{
		cameras = scenes->cameras;
		while (cameras)
		{
			cameras->params.cam.renderer = renderer_init(cameras, args, env);
			cameras = cameras->next;
		}
		scenes = scenes->next;
	}
}

void			settings_settings(t_args *args, t_env *env)
{
	renderers_settings(args, env);
	if (args->verbose_mode == SETTINGS || args->verbose_mode == ALL_VERBOSE)
		verbose_settings(args, env);
}
