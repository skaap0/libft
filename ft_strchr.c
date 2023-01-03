/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:06:42 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/02 14:41:17 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*fo;

	i = 0;
	fo = NULL;
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
		{
			fo = ((char *) s + i);
			return (fo);
		}
		i++;
	}
	if ((char)c == s[i])
	{
		fo = ((char *) s + i);
		return (fo);
	}
	return (fo);
}
