/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 01:44:42 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 03:16:59 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_STRUCT_H
# define EDITOR_STRUCT_H

typedef enum			e_button_state
{
	IDLE,
	HOVER,
	CLICKED,
}						t_button_state

typedef struct			s_button
{
	t_button_state		state;
	SDL_Rect			surface;
	SDL_Surface			*idle;
	SDL_Surface			*hover;
	SDL_Surface			*clicked;
	SDL_Surface			*icon;
}						t_button;

typedef struct			s_virtual_window
{
	SDL_Rect			surface;
	SDL_Point			hitbox;	
}						t_virtual_window;

typedef struct			s_win
{
	int					width;
	int					height;
	SDL_Window			*win;
	SDL_Renderer		*renderer;
}						t_win;

typedef struct			s_assets
{
	SDL_Surface			*icons;
	int					icons_number;
	SDL_Surface			
}						t_assets;

typedef struct			s_enve
{
	t_win				window;
	t_assets			assets;
}						t_enve;

#endif
