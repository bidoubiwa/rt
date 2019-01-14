/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 09:50:16 by toliver           #+#    #+#             */
/*   Updated: 2019/01/14 18:20:23 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				sdl_px_to_renderer(SDL_Renderer *renderer, int x, int y, int color)
{
	SDL_SetRenderDrawColor(renderer, ((color & 0xff0000) >> 16), ((color & 0xff00) >> 8), color & 0xff, 255);
	if (SDL_RenderDrawPoint(renderer, x, y) != 0)
		ft_printf("Drawpoint error\n");
}

void				rt_print_raytracer(t_scene *scenes, t_win *win)
{
	int				x;
	int				y;
	int				i;
	t_renderer		*renderer;

	(void)win;
	i = 0;
	renderer = scenes->cameras->params.cam.renderer;
	y = 0;

	while (y < renderer->height)
	{
		x = 0;
		while (x < renderer->width)
		{
//			SDL_SetRenderDrawColor(win->renderer, 
//					renderer->renderer[i].color.r, 
//					renderer->renderer[i].color.g, 
//					renderer->renderer[i].color.b, 255);
//			SDL_RenderDrawPoint(win->renderer, x, y);
//			sdl_px_to_renderer(win->renderer, x, y, renderer->renderer[i].obj_hit->params.shape.material.params.plain.color.value);
			sdl_px_to_renderer(win->renderer, x, y, renderer->renderer[i].color.value);
			i++;
			x++;
		}
		y++;
	}
//	SDL_SetRenderDrawColor(win->renderer, 255, 255, 255, 255);
//	SDL_RenderDrawPoint(win->renderer, 400, 400);
	SDL_RenderPresent(win->renderer);
}

void				rt_printing(t_args *args, t_scene *scenes, t_win *win)
{
	if (scenes)
		rt_print_raytracer(scenes, win);
	else
		ft_printf("no scene availlable !\n");
	if (args->verbose_mode == PRINTING || args->verbose_mode == ALL_VERBOSE)
		verbose_printing(args, scenes);
}
