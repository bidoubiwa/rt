/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:42:52 by cvermand          #+#    #+#             */
/*   Updated: 2019/01/11 14:51:44 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_matrix_obj(t_obj *obj, t_vec rotation)
{
	t_matrix	matrix;

	matrix = world_to_obj_matrix(obj);
	matrix = matrix_mult(matrix, rotmatrix_axis_angle(vec_x(), rotation.x));
	matrix = matrix_mult(matrix, rotmatrix_axis_angle(vec_y(), -rotation.y));
	matrix = matrix_mult(matrix, rotmatrix_axis_angle(vec_z(), rotation.z));
	obj->world_to_obj = matrix;
	obj->obj_to_world = obj_to_world_matrix(obj);
}

static void		parse_rotation_translation(t_elem *elem, t_obj *obj)
{
	t_vec	translation;
	t_vec	rotation;

	translation = default_vec(required_vec(
		parse_vector(find_elem_by_key(elem, "translation")),
		TRANSLATION_REQUIRED, "translation"), vec_init0(0.0, 0.0, 0.0));
	obj->pos = vec_add(obj->pos, translation);
	rotation = default_vec(required_vec(
		parse_angle_vector(find_elem_by_key(elem, "rotation")),
		ROTATION_REQUIRED, "rotation"), vec_init0(0.0, 0.0, 0.0));
	set_matrix_obj(obj, rotation);
}

static void		parse_color_information(t_elem *child_elem, t_obj *obj)
{
	t_plain				plain;
	t_material_type		material_type;
	t_material_light	material_light;

	material_type = obj->params.shape.material.type;
	if (material_type == PLAIN)
	{
		plain = obj->params.shape.material.params.plain;	
		plain.color = parse_color(find_elem_by_key(child_elem, "color"), COLOR_REQ);
	}
	if (material_type == PLAIN || material_type == TEXTURE)
	{
		if (material_type == PLAIN)
			material_light = obj->params.shape.material.params.plain.light;	
		else if (material_type == TEXTURE)
			material_light = obj->params.shape.material.params.texture.light;
		material_light.specular = default_float(required_float(
					parse_float(find_elem_by_key(child_elem, "specular")),
					SPECULAR_REQ, "Specular"), 1.0);
		material_light.diffuse = default_float(required_float(
					parse_float(find_elem_by_key(child_elem, "diffuse")),
					DIFFUSE_REQ, "Diffuse"), 1.0);
	/*	material_light.ambiant = default_float(required_float(
					parse_float(find_elem_by_key(child_elem, "ambiant")),
					AMBIANT_REQ, "Ambiant"), 0.0);*/
		material_light.brillance = default_float(required_float(
					parse_float(find_elem_by_key(child_elem, "brillance")),
					BRILLANCE_REQ, "Brillance"), 1.0);
		if (material_light.brillance < 1.0 || material_light.brillance > 128)
			ft_error(BRILLANCE_BAD_FORMAT);
		material_light.brillance = material_light.brillance / 128.0;
		if (material_light.specular < 0.0 || material_light.specular > 1.0)
			ft_error(SPECULAR_BAD_FORMAT);
		if (material_light.diffuse < 0.0 || material_light.diffuse > 1.0)
			ft_error(DIFFUSE_BAD_FORMAT);
		/*if (material_light.ambiant < 0.0 || material_light.ambiant > 1.0)
			ft_error(AMBIANT_BAD_FORMAT);*/
	}
}

t_obj			*parse_one_object(t_elem *elem,
								void (*parse_obj)(t_elem *, t_obj *))
{
	t_obj			*obj;
	t_elem			*child_elem;

	obj = new_obj();
	child_elem = elem->value.objecty;
	parse_dir_lookat_pos(child_elem, obj);
	parse_up_right_vec(child_elem, obj);
	parse_obj(child_elem, obj);
	if (obj->type != LIGHT && obj->type != LIGHT)
		parse_color_information(child_elem, obj);
	parse_rotation_translation(child_elem, obj);
	return (obj);
}
