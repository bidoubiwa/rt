/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:08:23 by cvermand          #+#    #+#             */
/*   Updated: 2019/01/14 17:17:21 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_cone(t_elem *elem, t_obj *obj)
{
	obj->params.shape.type = CONE;
	obj->params.shape.params.cone.angle =
		default_float(
			required_float(
				parse_degree_to_rad(
					parse_float(
						find_elem_by_key(elem, "angle"))),
				CONE_ANGLE_REQUIRED,
				"Angle of plane"),
			0.0);
	obj->params.shape.intersect = &cone_intersection;
	obj->type = SHAPE;
	obj->params.shape.material.type = PLAIN;
}

void		init_plane(t_elem *elem, t_obj *obj)
{
	(void)elem;
	(void)obj;
	obj->params.shape.type = PLANE;
	obj->params.shape.intersect = &plane_intersection;
	obj->type = SHAPE;
	obj->params.shape.material.type = PLAIN;
}

void		init_cylinder(t_elem *elem, t_obj *obj)
{
	obj->params.shape.type = CYLINDER;
	obj->params.shape.params.cylinder.radius =
		default_float(
			required_float(
				parse_radius(
					parse_float(
						find_elem_by_key(elem, "radius"))),
				CYLINDER_RADIUS_REQUIRED,
				"Radius of cylinder"),
			0.0);
	obj->params.shape.intersect = &cylinder_intersection;
	obj->type = SHAPE;
	obj->params.shape.material.type = PLAIN;
}

void		init_sphere(t_elem *elem, t_obj *obj)
{
	obj->params.shape.type = SPHERE;
	obj->params.shape.params.sphere.radius =
		default_float(
			required_float(
				parse_radius(
					parse_float(
						find_elem_by_key(elem, "radius"))),
				SPHERE_RADIUS_REQUIRED,
				"Radius of sphere"),
			0.0);
	obj->params.shape.intersect = &sphere_intersection;
	obj->type = SHAPE;
	obj->params.shape.material.type = PLAIN;
}
