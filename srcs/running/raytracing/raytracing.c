/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 03:44:10 by toliver           #+#    #+#             */
/*   Updated: 2019/01/14 16:39:59 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			raytracing(t_scene *scene, t_obj *camera)
{
	t_renderer	*renderer;

	renderer = camera->params.cam.renderer;
	malloc_raytracing(scene, renderer, camera);
}
