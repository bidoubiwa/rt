/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 03:11:04 by toliver           #+#    #+#             */
/*   Updated: 2019/01/13 19:14:26 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			running_rt(t_args *args, t_scene *scenes)
{
	t_scene		*scene;
	t_obj		*camera;

	scene = scenes;
	while (scene)
	{
		camera = scene->cameras;
		while (camera)
		{
			raytracing(scene, camera);
			camera = camera->next;
		}
		scene = scene->next;
	}
	if (args->verbose_mode == RUNNING || args->verbose_mode == ALL_VERBOSE)
		verbose_running(args, scenes);
}
