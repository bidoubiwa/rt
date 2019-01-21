/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_parsing_printing.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 05:58:45 by toliver           #+#    #+#             */
/*   Updated: 2019/01/21 13:01:53 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				print_object_common(t_obj *obj)
{
	t_material_type		material_type;
	t_material_light	material_light;

	ft_printf("\t\t%-10s : ", "pos");
	print_vec(obj->pos);
	ft_printf("\t\t%-10s : ", "right");
	print_vec(obj->right);
	ft_printf("\t\t%-10s : ", "up");
	print_vec(obj->up);
	ft_printf("\t\t%-10s : ", "dir");
	print_vec(obj->dir);
	if (obj->type != LIGHT)
	{
		material_type = obj->params.shape.material.type;
		if (material_type == PLAIN)
			print_color(obj->params.shape.material.params.plain.color, "color");
		if (material_type == PLAIN || material_type == TEXTURE)
		{
			if (material_type == PLAIN)
				material_light = obj->params.shape.material.params.plain.light;	
			else if (material_type == TEXTURE)
				material_light = obj->params.shape.material.params.texture.light;
			ft_printf("\t\t%-10s : %f\n", "brillance", material_light.brillance);
			ft_printf("\t\t%-10s : %f\n", "specular", material_light.specular);
			ft_printf("\t\t%-10s : %f\n", "diffuse", material_light.diffuse);
			//ft_printf("\t\t%-10s : %f\n", "ambiant", material_light.ambiant);
			//ft_printf("\t\t%-10s : %f\n", "roll", material_light.roll);
		}
	}
	else if (obj->type == LIGHT)
			print_color(obj->params.light.color, "color");
	ft_printf("\t\t%-10s : \n", "world to obj");
	print_matrix(obj->world_to_obj);
	ft_printf("\t\t%-10s : \n", "obj to world ");
	print_matrix(obj->obj_to_world);
}

void				print_object_specs(t_obj *obj)
{
	if (obj->type == CONE)
		ft_printf("\t\t%-10s : %f\n", "angle", obj->params.shape.params.cone.angle);
	else if (obj->type == CYLINDER)
		ft_printf("\t\t%-10s : %f\n", "radius", obj->params.shape.params.cylinder.radius);
	else if (obj->type == SPHERE)
		ft_printf("\t\t%-10s : %f\n", "radius", obj->params.shape.params.sphere.radius);
	else if (obj->type == LIGHT)
		ft_printf("\t\t%-10s : %f\n", "intensity", obj->params.light.intensity);
	else if (obj->type == CAMERA)
		ft_printf("\t\t%-10s : %f\n", "fov", obj->params.cam.fov);
}

void				print_object(t_obj *obj)
{
	print_object_common(obj);
	print_object_specs(obj);
}

void				print_scene(t_scene *scene)
{
	ft_printf("\tname : %s\n", scene->name);
	print_objects(scene->objs);
	print_lights(scene->lights);
	print_cameras(scene->cameras);
}
