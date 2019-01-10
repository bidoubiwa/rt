/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 21:52:51 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 14:21:48 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "libftg.h"
# include "libftprintf.h"
# include <limits.h>
# include "rt_structs.h"
# include "colors.h"
# include "json_parser.h"
# include "rt_required_information.h"
# include "rt_errors.h"
# include "libft_errors.h"
# include "args_parsing.h"

# define TOLERANCE 0.01

void				launch_editor(void);

/*
** BASIC UTILS FUNCTIONS
*/

void				*ft_malloc(size_t size);
void				ft_error(char *str);
char				*string_to_lower(char *str);

/*
** BASIC MATH UTILS FUNCTIONS
*/

float				maxf(float a, float b);
float				minf(float a, float b);
int					clampi(int a, int inf_limit, int sup_limit);
float				clampf(float a, float inf_limit, float sup_limit);
int					is_equal_float(float a, float b);
int					is_equal_vec(t_vec a, t_vec b);
int					is_opposite_vec(t_vec a, t_vec b);

/*
** INIT FUNCTIONS
*/

t_env				*rt_init(t_args *args);
t_env				*rt_env_init(t_args *args);
//t_win				*win_init(int width, int height, char *name, void *mlx);

void				verbose_env(t_env *env);

/*
** PARSING
*/

t_scene				*parsing(t_args *args);
/*
** PARSING PRINT
*/ 
void				verbose_parsing(t_scene *scene);
void				print_scene(t_scene *scene);
void				print_scenes(t_scene *scenes);
void				print_objects(t_obj *objs);
void				print_object(t_obj *obj);
void				print_object_common(t_obj *obj);
void				print_object_spec(t_obj *obj);
void				print_lights(t_obj *lights);
void				print_cameras(t_obj *cameras);
/*
** RT PARSING FROM JSON
*/
t_scene				*rt_parsing(t_elem *elem);
t_scene				*parse_scene(t_elem *elem);
t_obj				*parse_objects(t_elem *elem);
t_obj				*parse_lights(t_elem *elem);
t_obj				*parse_cameras(t_elem *elem);
t_rgb				parse_color(t_elem *elem, int required);
void				parse_dir_lookat_pos(t_elem *elem, t_obj *obj);
void				parse_up_right_vec(t_elem *elem, t_obj *obj);
float				parse_float(t_elem *elem);
t_vec				parse_vector(t_elem *elem);
t_vec				parse_angle_vector(t_elem *elem);
t_obj				*parse_one_object(t_elem *elem,
		void (*parse_obj)(t_elem *elem, t_obj *obj));
t_obj				*new_obj();
float				parse_radius(float radius);
float				parse_degree_to_rad(float angle);
void				init_object(t_elem *elem, t_obj *obj);
void				init_cone(t_elem *elem, t_obj *obj);
void				init_plane(t_elem *elem, t_obj *obj);
void				init_cylinder(t_elem *elem, t_obj *obj);
void				init_sphere(t_elem *elem, t_obj *obj);
void				init_light(t_elem *elem, t_obj *obj);
void				init_camera(t_elem *elem, t_obj *obj);
float				required_float(float number, int required, char *error);
t_vec				required_vec(t_vec vec, int required, char *error);
float				default_float(float number, float def);
t_vec				default_vec(t_vec vec, t_vec def);
t_rgb				default_rgb(t_rgb rgb, t_rgb def);
t_elem				*find_elem_by_key(t_elem *elem, char *key);
int					check_type_of_key(char *key, t_json_data type);
int					check_float_keys(char *key);
int					check_int_keys(char *key);
int					hex_color_to_int(t_elem *elem);
t_rgb				parse_rgb(t_elem *elem, t_rgb color);
int					parse_hex(t_elem *elem);
t_rgb				parse_rgb_and_val(t_elem *child_elem);
t_vec				get_right_dir(t_vec dir);
t_vec				get_up_dir(t_vec dir, t_vec right);
t_vec				vec_rot_zaxis_angle(t_vec v, t_vec zaxis, float angle);
/*
** PARSING ERRORS
*/
void				wrong_format(char *form, t_json_data type);
void				is_required(char *key, int one);

/*
** RUNNING FUNCTIONS
*/

t_ray				reflect_ray(t_ray *ray);
t_vec				reflect_vec(t_vec vec, t_vec axis);
/*
** PRIMITIVES FUNCTIONS
*/

void				get_conenormal(t_ray *ray);
void				get_cylindernormal(t_ray *ray);
void				get_planenormal(t_ray *ray);
void				get_spherenormal(t_ray *ray);

float				sphere_radius(t_obj *sphere);
void				sphere_intersection(t_ray *ray, t_obj *sphere);
void				plane_intersection(t_ray *ray, t_obj *plane);
void				cylinder_intersection(t_ray *ray, t_obj *plane);
void				cone_intersection(t_ray *ray, t_obj *cone);

int					quadratic(float a, float b, float c, float l[2]);
void				check_for_closest(float length, t_ray *ray, t_obj *obj);
void				get_normal(t_ray *ray);
#endif
