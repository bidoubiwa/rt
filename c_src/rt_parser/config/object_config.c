/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvermand <cvermand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 19:13:09 by cvermand          #+#    #+#             */
/*   Updated: 2019/02/10 19:37:15 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_elem		*get_object_elem(t_elem *elem)
{
	return (elem->value.objecty);
}