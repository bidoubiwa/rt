/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_obj_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:58:51 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 14:40:35 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OBJ_STRUCTS_H
# define RT_OBJ_STRUCTS_H

#include "libftg.h"
#include "rt_ray_structs.h"
#include "rt_material_structs.h"

typedef struct		s_sphere
{
	float			radius;
}					t_sphere;

typedef struct		s_plane
{
	int				a;
}					t_plane;

typedef struct		s_cone
{
	float			angle;
}					t_cone;

typedef struct		s_cylinder
{
	float			radius;
}					t_cylinder;

typedef struct		s_renderer
{
	int				width;
	int				height;
	int				depth;
	int				renderer_mode;
	int				print_mode;
	t_vec			top_left_vec;
	t_vec			increment;
	struct s_ray	*renderer;
//	t_img			*img; pointeur sur image sur laquelle on ecrit
}					t_renderer;

typedef enum		e_light_type
{
	POINT,
//	AMBIANT,
//	PARALLEL,
}					t_light_type;

typedef enum		e_shape_type
{
	SPHERE,
	PLANE,
	CONE,
	CYLINDER,
//	MOEBIUS,
//	CUBE_HOLE,
//	NAPPE,
//	TORRE,
//	EQUATION,
//	OTHER,
//	PARABOLOID,
//	HYPERBOLOID,
//	QUADRIC,  ?
}					t_shape_type;

typedef enum		e_obj_type
{
	SHAPE,
	LIGHT,
	CAMERA,
}					t_obj_type;

typedef union		u_shape_params
{
	t_sphere		sphere;
	t_plane			plane;
	t_cone			cone;
	t_cylinder		cylinder;
//	t_moebius		moebius;
//	t_cube_hole		cube_hole;
//	t_nappe			nappe;
//	t_torre			torre;
//	t_equation		equation;
//	t_other			other;
//	t_paraboloid	paraboloid;
//	t_hyperboloid	hyperboloid;
//	t_quadric		quadric;
}					t_shape_params;

typedef struct		s_shape
{
	t_shape_type	type;
//	t_rgb			color;
	t_material		*material;
	float			specular; // voir si toutes ces valeurs sont pas liees au material
	float			diffuse;
	float			brillance;
	float			reflection;
	float			refraction;
	float			alpha;
	void			(*intersect)(t_ray*, struct s_obj*);
	t_shape_params	params;
}					t_shape;

typedef struct		s_cam
{
	float			fov;
	t_renderer		*renderer;
}					t_cam;

typedef struct		s_light
{
	t_light_type	type;
	t_rgb			color;
	float			intensity;
	float			size;				// utile que pour point, mais a voir
}					t_light;

typedef union		u_obj_params
{
	t_shape			shape;
	t_cam			cam;
	t_light			light;
}					t_obj_params;
// TODO faire free le maillon du get next line une fois qu'on a fini de lire la derniere ligne dun fichier
typedef struct		s_obj
{
	t_vec			pos;
	t_vec			lookat;
	t_vec			dir;
	t_vec			up;
	t_vec			right;	
	t_matrix		world_to_obj;
	t_matrix		obj_to_world;
	t_obj_type		type;
	t_obj_params	params;
	struct s_obj	*next;
}					t_obj;

#endif
