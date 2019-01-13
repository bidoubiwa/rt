/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_shooting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 03:26:38 by toliver           #+#    #+#             */
/*   Updated: 2019/01/13 19:34:57 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			add_tolerance(t_ray *ray)
{
	ray->hit_pos = vec_add(ray->hit_pos, vec_mul(ray->normal, TOLERANCE));
}

static void			set_ray_hitparams(t_ray *ray)
{
	t_material_type		material_type;

	material_type = ray->obj_hit->params.shape.material.type;

	if (ray->length == INFINITY)
	{
		ray->color = rgb_init(0x000000);
		return ;
	}
	ray->hit_pos = vec_add(ray->pos, vec_mul(ray->dir, ray->length));
	get_normal(ray);
	add_tolerance(ray);
	if (material_type == PLAIN)
		ray->color = ray->obj_hit->params.shape.material.params.plain.color;
}

void				shoot_ray(t_scene *scene, t_ray *ray)
{
	t_obj			*objptr;
	float			current_hit;

	current_hit = INFINITY;
	objptr = scene->objs;
	while (objptr)
	{
		objptr->params.shape.intersect(ray, objptr);
		objptr = objptr->next;
	}
	set_ray_hitparams(ray);
}
