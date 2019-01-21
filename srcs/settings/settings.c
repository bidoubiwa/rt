/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 06:28:16 by toliver           #+#    #+#             */
/*   Updated: 2019/01/21 16:52:09 by toliver          ###   ########.fr       */
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

// parser la reflection de 0 a 1, et si la valeur donnee est > 0.99 on la set a 0.99 sans lui dire :o

void			_tmp_settings(t_env *env)
{
	env->scene->objs->next->next->next->next->next->next->next->next->next->params.shape.reflection = 0.3;
//	env->scene->objs->next->next->next->next->next->next->next->next->next->next->next->next->next->params.shape.alpha = 0.5;
//	env->scene->objs->next->next->next->next->next->next->next->next->next->params.shape.alpha = 0.5;
//	env->scene->objs->next->next->next->next->next->next->next->next->next->next->next->next->next->params.shape.refraction = 0.5;
	env->scene->objs->next->next->next->next->next->next->next->next->params.shape.reflection = 0.5;
	env->scene->objs->next->next->next->next->next->params.shape.reflection = 0.5;
	env->scene->objs->next->next->next->next->next->next->params.shape.reflection = 0.5;
	env->scene->objs->next->next->next->next->next->next->next->params.shape.reflection = 0.5;
//	env->scene->objs->next->next->next->next->next->next->next->next->params.shape.reflection = 0.5;
	/*
	env->scene->objs->params.shape.params.quadric.a = 1;
	env->scene->objs->params.shape.params.quadric.b = -0.9;
	env->scene->objs->params.shape.params.quadric.c = -0.8;
	env->scene->objs->params.shape.params.quadric.d = -5;
	env->scene->objs->params.shape.params.quadric.e = 2;
	env->scene->objs->params.shape.params.quadric.f = -5;
	env->scene->objs->params.shape.params.quadric.g = -5;
	env->scene->objs->params.shape.params.quadric.h = 1000;
	env->scene->objs->params.shape.params.quadric.i = -5;
	env->scene->objs->params.shape.params.quadric.j = 1;
	env->scene->objs->params.shape.intersect = &quadric_intersection;
	env->scene->cameras->pos.x = 0;
	env->scene->cameras->pos.y = 0;
	env->scene->cameras->pos.z = 0;
	env->scene->cameras->dir.x = 0;
	env->scene->cameras->dir.y = 0;
	env->scene->cameras->dir.z = 1;
	env->scene->objs->next = NULL;
	*/
}

void			rt_settings(t_args *args, t_env *env)
{
	renderers_settings(args, env);
	_tmp_settings(env);
	if (args->verbose_mode == SETTINGS || args->verbose_mode == ALL_VERBOSE)
		verbose_settings(args, env);
}
