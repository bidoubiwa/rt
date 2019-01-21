/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 04:19:11 by toliver           #+#    #+#             */
/*   Updated: 2019/01/21 07:37:58 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			quadric_get_variables(t_ray ray, t_obj *quadric, float var[3])
{
	t_quadric	v;
	t_vec		dir;

	v = quadric->params.shape.params.quadric;
	dir = ray.dir;
	var[0] = v.a * powf(dir.x, 2) + v.b * powf(dir.y, 2) + v.c * powf(dir.z, 2)
		+ v.d * dir.x * dir.y + v.e * dir.x * dir.z + v.f * dir.y * dir.z;
	var[1] = 2 * v.a * ray.pos.x * dir.x + 2 * v.b * ray.pos.y * dir.y + 2 * v.c
		* ray.pos.z * dir.z + v.d * (ray.pos.x * dir.y + ray.pos.y * dir.x)
		+ v.e * (ray.pos.x * dir.z + ray.pos.z * dir.x) + v.f * (ray.pos.y
				* dir.x + dir.y * ray.pos.z) + v.g * dir.x + v.h * dir.y + v.i * dir.z;
	var[2] = v.a * powf(ray.pos.x, 2) + v.b * powf(ray.pos.y, 2) + v.c
		* powf(ray.pos.z, 2) + v.d * ray.pos.x * ray.pos.y + v.e * ray.pos.x
		* ray.pos.z + v.f * ray.pos.y * ray.pos.z + v.g * ray.pos.x + v.h
		* ray.pos.y + v.i * ray.pos.z + v.j;
}
/*
   static float	quadric_return_length(t_ray ray, float l[2])
   {
   t_vec		v1;
   t_vec		v2;

   v1 = vec_mul(ray.dir, l[0]);
   v2 = vec_mul(ray.dir, l[1]);
   if (l[0] <= 0)
   {
   if (l[1] <= 0)
   return (INFINITY);
   return (vec_magnitude(v2));
   }
   if (l[1] <= TOLERANCE)
   return (vec_magnitude(v1));
   if (l[0] < l[1])
   return (vec_magnitude(v1));
   return (vec_magnitude(v2));
   }
   */

float				test(t_ray ray, t_obj *obj)
{
	double  a, b, c, d, e;        // Coefficents of equation of..
	double  f, g, h, j, k;        // ..quadric surface
	double  acoef, bcoef, ccoef;        // Intersection coefficents
	double  dx, dy, dz;            // Direction - origin coordinates
	double  disc;            // Distance to intersection
	double  root;            // Root of distance to intersection
	double  t;                // Distance along ray to intersection
	double  x0, y0, z0;            // Origin coordinates


	a = obj->params.shape.params.quadric.a;
	b = obj->params.shape.params.quadric.b;
	c = obj->params.shape.params.quadric.c;
	d = obj->params.shape.params.quadric.d;
	e = obj->params.shape.params.quadric.e;
	f = obj->params.shape.params.quadric.f;
	g = obj->params.shape.params.quadric.g;
	h = obj->params.shape.params.quadric.h;
	j = obj->params.shape.params.quadric.j;
	k = obj->params.shape.params.quadric.k;

	t_vec temp;
	temp.x = ray.dir.x;
	temp.y = ray.dir.y;
	temp.z = ray.dir.z;
	temp = vec_normalize(temp);

	dx = temp.x;
	dy = temp.y;
	dz = temp.z;

	//dx = ray.dir.x/* - ray.org.x*/;
	//dy = ray.dir.y/* - ray.org.y*/;
	//dz = ray.dir.z/* - ray.org.z*/;

	x0 = ray.pos.x;
	y0 = ray.pos.y;
	z0 = ray.pos.z;

	acoef = 2 * f * dx * dz + 2 * e * dy * dz + c * dz * dz + b * dy * dy +
		a * dx * dx + 2 * d * dx * dy;

	bcoef = 2 * b * y0 * dy + 2 * a * x0 * dx + 2 * c * z0 * dz +
		2 * h * dy + 2 * g * dx + 2 * j * dz + 2 * d * x0 * dy +
		2 * e * y0 * dz + 2 * e * z0 * dy + 2 * d * y0 * dx +
		2 * f * x0 * dz + 2 * f * z0 * dx;

	ccoef = a * x0 * x0 + 2 * g * x0 + 2 * f * x0 * z0 + b * y0 * y0 +
		2 * e * y0 * z0 + 2 * d * x0 * y0 + c * z0 * z0 + 2 * h * y0 +
		2 * j * z0 + k;
	if ( 1.0 + acoef == 1.0 ) 
	{
		if ( 1.0 + bcoef == 1.0 )
		{
//			ft_putchar('1');
			return INFINITY;
		}

	t = ( -ccoef ) / ( bcoef );
	}
	else 
	{
		disc = bcoef * bcoef - 4 * acoef * ccoef;
		if ( 1.0 + disc < 1.0 )
		{
//			ft_putchar('2');
			return INFINITY;
		}
		root = sqrt( disc );
		t = ( -bcoef - root ) / ( acoef + acoef );
		if ( t < 0.0 ) 
		{
			t = ( -bcoef + root ) / ( acoef + acoef );
		}
	}
	if ( t < 0.001 )
	{
//			ft_putchar('3');
		return INFINITY;
	}
//	printf("%f\n", t);
	return t;
}

float			quadric_intersect(t_ray ray, t_obj *quadric)
{
	float		var[3];
//	float		l[2];

	ray = ray_to_obj(ray, quadric);
	quadric_get_variables(ray, quadric, var);
	if (is_equal_float(var[1], 0) || -var[2] / var[1] <= 0)
		return (INFINITY);
	return (-var[2] / var[1]);
}

static float	try_intersection(t_ray ray, t_obj *quadric)
{
	return (quadric_intersect(ray, quadric));
}

void			quadric_intersection(t_ray *ray, t_obj *quadric)
{
	float		length;

	length = try_intersection(*ray, quadric);
	check_for_closest(length, ray, quadric);
}
