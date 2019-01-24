/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_raytracing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 03:45:34 by toliver           #+#    #+#             */
/*   Updated: 2019/01/21 16:53:55 by toliver          ###   ########.fr       */
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

void				_shoot_ray(t_scene *scene, t_ray *ray)
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

void			ray_tracing(t_scene *scene, t_ray *ray, t_obj *cam, float contrib)
{
	t_ray		*reflected_ray;
//	t_ray		*refracted_ray;

	_shoot_ray(scene, ray);
	if (ray->length != INFINITY)
	{
		shoot_ray_lights(scene, ray, cam);
		if (ray->obj_hit->params.shape.reflection != 0 && contrib * ray->obj_hit->params.shape.reflection > 0.2)
		{
			reflected_ray = (t_ray*)ft_malloc(sizeof(t_ray));
			*reflected_ray = ray_init(ray->hit_pos, reflect_vec(vec_opposite(ray->dir), ray->normal));
			ray->reflected_ray = reflected_ray;
			ray_tracing(scene, reflected_ray, cam, contrib * ray->obj_hit->params.shape.reflection);
		}
//		if (ray->obj_hit->params.shape.alpha != 1)
//		{
//			refracted_ray = (t_ray*)ft_malloc(sizeof(t_ray));
//			*refracted_ray = ray_init(vec_sub(ray->hit_pos, vec_mul(vec_opposite(ray->normal), (TOLERANCE * 2.0))), ray->dir);
//		}
	}
}

void			_set_ray_color(t_ray *ray)
{
	t_ray		*ptr;
	t_rgb		color;
	float		contrib;
	
	if (ray->obj_hit && ray->obj_hit->params.shape.reflection != 0)
	{
		ptr = ray;
		contrib = 1;
		while (ptr && ptr->obj_hit)
		{
			color = rgb_add(color, rgb_mul(ptr->color, contrib
					* (1.0 - ptr->obj_hit->params.shape.reflection)));
			contrib *= ptr->obj_hit->params.shape.reflection;
			ptr = ptr->reflected_ray;
		}
		ray->color = color;
	}
	rgb_updatevalue(&ray->color);
}

void			malloc_raytracing(t_scene *scene, t_renderer *renderer,
		t_obj *cam)
{
	int				i;
	int				raymax;

	i = 0;
	raymax = renderer->height * renderer->width * renderer->depth;
	while (i < raymax)
	{
		ray_tracing(scene, &renderer->renderer[i], cam, 100);
		_set_ray_color(&renderer->renderer[i]);	
//		shoot_ray(scene, &renderer->renderer[i]); // ici
//		if (renderer->renderer[i].length != INFINITY)
//			shoot_ray_lights(scene, &renderer->renderer[i], cam);
		i++;
		if (i % 10000 == 0)
			ft_printf("%d\n", i);
	}
}

/*
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
*/
