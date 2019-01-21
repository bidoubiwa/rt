/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_ray_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:03:12 by toliver           #+#    #+#             */
/*   Updated: 2019/01/21 16:52:00 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RAY_STRUCTS_H
# define RT_RAY_STRUCTS_H

#include "rt_color_structs.h"

typedef struct		s_ray
{
	t_vec			pos;
	t_vec			dir;
	t_vec			lookat;
	t_rgb			color;
	t_vec			normal;
	t_vec			hit_pos;
	float			length;
	struct s_obj	*obj_hit;
	struct s_ray	*reflected_ray;
	struct s_ray	*refracted_ray;
}					t_ray;

#endif
