/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_light_shooting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 08:50:30 by toliver           #+#    #+#             */
/*   Updated: 2019/01/13 20:53:07 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rgb			get_ambiant(t_ray *ray, t_scene *scene)
{
	t_rgb				color;
	t_obj				*lights;
	float				total_intensity;
	t_material_type		material_type;

	color = rgb_init(0);
	lights = scene->lights;
	total_intensity = 0;
	while (lights)
	{
		total_intensity += lights->params.light.intensity;
		color = rgb_add(color,
				rgb_mul(lights->params.light.color, lights->params.light.intensity));
		lights = lights->next;
	}
	if (total_intensity != 0)
		color = rgb_div(color, total_intensity);
	material_type = ray->obj_hit->params.shape.material.type;
	if (material_type == PLAIN)
	{
		color = rgb_mul(color, 0.1);
		color = rgb_mul_rgb(ray->obj_hit->params.shape.material.params.plain.color, color);
		color = rgb_mul(color, ray->obj_hit->params.shape.material.params.plain.light.diffuse);
		rgb_updatevalue(&color);
	}
	return (color);
}

t_rgb			get_specular(t_ray *ray, t_ray to_light, t_obj *light,
		t_obj *cam)
{
	t_rgb		rgb;
	t_vec		reflect;
	t_vec		to_view;
	float		mult_value;
	float		dotproduct;
	t_material_light	material_light;
	t_material_type		material_type;

	material_type = ray->obj_hit->params.shape.material.type;
	if (material_type == PLAIN)
		material_light = ray->obj_hit->params.shape.material.params.plain.light;	
	else if (material_type == TEXTURE)
		material_light = ray->obj_hit->params.shape.material.params.texture.light;
	dotproduct = vec_dotproduct(vec_normalize(
				vec_init(ray->hit_pos, light->pos)), ray->normal);
	if (dotproduct <= 0)
		return (rgb_init(0));
	reflect = reflect_vec(vec_normalize(vec_init(ray->hit_pos, light->pos)),
			ray->normal);
	to_view = vec_normalize(vec_init(ray->hit_pos, cam->pos));
	mult_value = maxf(0, vec_dotproduct(reflect, to_view));
	mult_value = powf(mult_value, (material_light.brillance * 128));
	mult_value *= light->params.light.intensity;
	rgb = rgb_mul(light->params.light.color, mult_value);
	rgb_updatevalue(&rgb);
	(void)to_light;
	return (rgb);
}

t_rgb			get_diffuse(t_ray *ray, t_ray to_light, t_obj *light)
{
	t_rgb		rgb;
	float		dotproduct;
	t_material_type		material_type;

	rgb = rgb_init(0);
	material_type = ray->obj_hit->params.shape.material.type;
	if (material_type == PLAIN)
	{
		dotproduct = vec_dotproduct(ray->normal,
				vec_normalize(vec_init(ray->hit_pos, light->pos)));
		if (dotproduct <= 0)
			return (rgb_init(0));
		dotproduct *= light->params.light.intensity;
		rgb = rgb_mul(light->params.light.color, dotproduct);
		rgb = rgb_mul_rgb(rgb, ray->obj_hit->params.shape.material.params.plain.color);
		rgb_updatevalue(&rgb);
		(void)to_light;
	}
	return (rgb);
}

void			set_light_colors(t_rgb ambiant, t_rgb diffuse, t_rgb specular,
		t_ray *ray)
{
	t_material_light	material_light;
	t_material_type		material_type;

	material_type = ray->obj_hit->params.shape.material.type;
	if (material_type == PLAIN)
		material_light = ray->obj_hit->params.shape.material.params.plain.light;	
	else if (material_type == TEXTURE)
		material_light = ray->obj_hit->params.shape.material.params.texture.light;
	diffuse = rgb_mul(diffuse, material_light.diffuse);
	specular = rgb_mul(specular,  material_light.specular);
	ray->color = rgb_add(ambiant, diffuse);
	ray->color = rgb_add(ray->color, specular);
	rgb_updatevalue(&ray->color);
}

void			shoot_ray_lights(t_scene *scene, t_ray *ray, t_obj *cam)
{
	t_rgb		ambiant_color;
	t_rgb		diffuse_color;
	t_rgb		specular_color;
	t_ray		to_light;
	t_obj		*lights;
	t_material_type		material_type;

	material_type = ray->obj_hit->params.shape.material.type;
	if (material_type == PLAIN || material_type == TEXTURE)
	{
		ambiant_color = (scene->lights) ? get_ambiant(ray, scene) : rgb_init(0);
		diffuse_color = rgb_init(0);
		specular_color = rgb_init(0);
		lights = scene->lights;
		while (lights)
		{
			to_light = ray_init_lookat(ray->hit_pos, lights->pos);
			shoot_ray(scene, &to_light);
			if (to_light.length >
					vec_magnitude(vec_init(ray->hit_pos, lights->pos)))
			{
				diffuse_color = rgb_add(diffuse_color,
						get_diffuse(ray, to_light, lights));
				specular_color = rgb_add(specular_color,
						get_specular(ray, to_light, lights, cam));
			}
			lights = lights->next;
		}
		set_light_colors(ambiant_color, diffuse_color, specular_color, ray);
	}
}
