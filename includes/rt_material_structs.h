/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_material_structs.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:20:45 by toliver           #+#    #+#             */
/*   Updated: 2019/01/09 21:12:55 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATERIAL_STRUCTS_H
# define RT_MATERIAL_STRUCTS_H

typedef enum				e_material_type
{
	PLAIN,
	TEXTURE,
//	BUMP,
//	ALPHA,
//	CUT,	
}							t_material_type;

typedef struct				s_texture
{
	char					*path; // ou la texture parsee totalement;
	float					scale;
	float					xoffset;
	float					yoffset;
}							t_texture;

typedef struct				s_plain
{
	t_rgb					color;
}							t_plain;

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
