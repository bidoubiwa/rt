/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_material_structs.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:20:45 by toliver           #+#    #+#             */
/*   Updated: 2019/01/11 16:17:08 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATERIAL_STRUCTS_H
# define RT_MATERIAL_STRUCTS_H


typedef struct				s_material_light
{
	float			specular; // voir si toutes ces valeurs sont pas liees au materia
	
	float			diffuse;
	float			brillance;
	float			reflection;
	float			refraction;
	float			alpha;
}							t_material_light;

typedef enum				e_material_type
{
	PLAIN,
	TEXTURE,
//	BUMP,
//	ALPHA,
//	CUT,	
}							t_material_type;

typedef struct				s_plain
{
	t_rgb					color;
	t_material_light		light;
}							t_plain;

typedef struct				s_texture
{
	char					*path; // ou la texture parsee totalement;
	float					scale;
	float					xoffset;
	float					yoffset;
	t_material_light		light;
}							t_texture;

typedef struct				s_perturbation_texture
{
	char					*path; // ou la texture parsee totalement;
	float					scale;
	float					xoffset;
	float					yoffset;
}							t_perturbation_texture;


typedef union				u_material_params
{
	t_plain					plain;
	t_texture				texture;	
}							t_material_params;

typedef struct				s_material
{
	t_material_type			type;
	t_material_params		params;
}							t_material;

#endif
