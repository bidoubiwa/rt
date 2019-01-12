/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:59:19 by toliver           #+#    #+#             */
/*   Updated: 2019/01/12 15:05:53 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCTS_H
# define RT_STRUCTS_H

#include "rt_obj_structs.h"
# include "args_parsing.h"

# define WINX 800
# define WINY 600

typedef struct		s_scene
{
	char			*name;
	t_obj			*objs;
	t_obj			*lights;
	t_obj			*cameras;
	struct s_scene	*next;
}					t_scene;

typedef struct		s_env
{
	t_scene			*scene;
	t_args			*args;
	t_win			*win;
}					t_env;

#endif
