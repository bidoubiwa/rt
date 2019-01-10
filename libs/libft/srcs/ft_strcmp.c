/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:44:17 by toliver           #+#    #+#             */
/*   Updated: 2017/11/08 06:36:02 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && s1 && *s1)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2 && *s1 == '\0')
		return (0);
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}