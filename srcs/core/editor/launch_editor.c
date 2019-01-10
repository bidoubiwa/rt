/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_editor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 01:36:55 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 02:23:37 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

int		editor(void)
{
	t_enve	*env;

	env = init();
	settings(env);
	running(env);
	quit(env);
	return (EXIT_SUCCESS);
}

void		launch_editor(void)
{
	editor();
}


