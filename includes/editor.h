/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 01:40:19 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 02:29:19 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "SDL.h"
# include "libft.h"
# include "libftg.h"
# include "colors.h"
# include "libftprintf.h"
# include "rt.h"
# include "editor_struct.h"

int					editor(void);
t_enve				*init(void);
void				settings(t_enve *env);
void				running(t_enve *env);
void				quit(t_enve *env);

#endif
