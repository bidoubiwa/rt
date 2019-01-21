/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 04:18:57 by toliver           #+#    #+#             */
/*   Updated: 2019/01/21 08:16:54 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				get_quadricnormal(t_ray *ray)
{
	t_quadric		var;
	t_vec			pos;
	t_vec			normal;

	var = ray->obj_hit->params.shape.params.quadric;
	pos = ray->hit_pos;
	normal.x = 2 * var.a * pos.x + var.d * pos.y + var.e * pos.z + var.g;
	normal.y = 2 * var.b * pos.y + var.d * pos.x + var.f * pos.z + var.h;
	normal.z = 2 * var.c * pos.z + var.e * pos.x + var.f * pos.y + var.i;
	normal = vec_norm(normal);
	if (vec_dot(ray->dir, normal) > 0)
		normal = vec_opposite(normal);
	ray->normal = normal;
//	print_vec(normal);
}
