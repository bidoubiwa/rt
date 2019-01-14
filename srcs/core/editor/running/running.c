/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 02:17:49 by toliver           #+#    #+#             */
/*   Updated: 2019/01/14 16:50:33 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		running(t_enve *env)
{
	(void)env;
	int running = 1;
	SDL_Event event;

	while (running)
		while(SDL_PollEvent(&event))
			if((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type && SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
				running = 0;
}
