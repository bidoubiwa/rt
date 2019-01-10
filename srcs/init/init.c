/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:37:52 by toliver           #+#    #+#             */
/*   Updated: 2019/01/10 13:27:28 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// TODO rajouter win

t_env				*rt_env_init(t_args *args)
{
	t_env			*env;

	(void)args;
	env = (t_env*)ft_malloc(sizeof(t_env));
	env->scene = NULL;
	return (env);
}

t_env				*rt_init(t_args *args)
{
	t_env			*env;

	env = rt_env_init(args);
	if (args->verbose_mode == INIT || args->verbose_mode == ALL_VERBOSE)
		verbose_env(env);
	return (env);
}
