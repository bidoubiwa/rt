/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_raytracing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 03:45:34 by toliver           #+#    #+#             */
/*   Updated: 2019/01/14 16:49:08 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			malloc_raytracing(t_scene *scene, t_renderer *renderer,
		t_obj *cam)
{
	int				i;
	int				raymax;

	i = 0;
	raymax = renderer->height * renderer->width * renderer->depth;
	while (i < raymax)
	{
		shoot_ray(scene, &renderer->renderer[i]); // ici
		i++;
	}
	i = 0;
	while (i < raymax)
	{
		if (renderer->renderer[i].length != INFINITY)
			shoot_ray_lights(scene, &renderer->renderer[i], cam);
		i++;
	}
}
