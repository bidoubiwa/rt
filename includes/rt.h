/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 21:52:51 by toliver           #+#    #+#             */
/*   Updated: 2019/01/09 20:08:34 by toliver          ###   ########.fr       */
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

# define WIN_WIDTH 1280
# define WIN_HEIGHT 768
# define TOLERANCE 0.01

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

#endif
