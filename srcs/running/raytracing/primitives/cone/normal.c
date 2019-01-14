/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 02:44:37 by toliver           #+#    #+#             */
/*   Updated: 2019/01/14 18:49:51 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vec		get_real_axis(t_ray *ray)
{
	t_vec			axis1;
	t_vec			axis2;
	t_vec			hit_to_axis1;
	t_vec			hit_to_axis2;
	t_vec			real_axis;

	axis1 = vec_add(ray->obj_hit->dir, ray->obj_hit->pos);
	axis2 = vec_add(vec_opposite(ray->obj_hit->dir), ray->obj_hit->pos);
	hit_to_axis1 = vec_init(ray->hit_pos, axis1);
	hit_to_axis2 = vec_init(ray->hit_pos, axis2);
	if (vec_magnitude(hit_to_axis1) < vec_magnitude(hit_to_axis2))
		real_axis = axis1;
	else
		real_axis = axis2;
	real_axis = vec_normalize(vec_sub(real_axis, ray->obj_hit->pos));
	return (real_axis);
}

static t_vec		get_hypotenuse(t_ray *ray, t_vec real_axis)
{
	t_vec			center_to_hit;
	t_vec			rot_axis;
	t_vec			hypotenuse;
	float			hypotenuse_len;
	t_matrix		matrix;

//	ft_printf(" KFEJWELFKJ : %f\n",ray->obj_hit->params.shape.params.cone.angle);
	center_to_hit = vec_init(ray->obj_hit->pos, ray->hit_pos);
	rot_axis = vec_crossproduct(vec_normalize(center_to_hit), real_axis);
	rot_axis = vec_normalize(vec_opposite(rot_axis));
	matrix = rotmatrix_axis_angle(rot_axis, degtorad(90));
	hypotenuse = vec_normalize(matrix_mult_vec(matrix, real_axis));
	hypotenuse_len = vec_magnitude(center_to_hit)
		/ cosf(degtorad(90) - ray->obj_hit->params.shape.params.cone.angle);
	hypotenuse = vec_add(
			vec_mul(hypotenuse, hypotenuse_len), ray->obj_hit->pos);
	return (hypotenuse);
}

void				get_conenormal(t_ray *ray)
{
	t_vec			real_axis;
	t_vec			hypotenuse;
	t_vec			normal;

//	ft_printf(" KFEJWELFKJ : %f\n",ray->obj_hit->params.shape.params.cone.angle);
	real_axis = get_real_axis(ray);
	hypotenuse = get_hypotenuse(ray, real_axis);
	normal = vec_init(ray->hit_pos, hypotenuse);
	normal = vec_normalize(normal);
	ray->normal = normal;
}
