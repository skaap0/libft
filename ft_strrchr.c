/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:09:46 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/02 14:43:23 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*lo;

	i = ft_strlen(s);
	lo = NULL;
	if (c == '\0')
	{
		lo = ((char *)&s[i]);
		return (lo);
	}
	if (s[1] == '\0')
		return (NULL);
	while ((char)c != s[i] && i != 0)
	{
		i--;
		if ((char)c == s[i])
			lo = ((char *)&s[i]);
	}
	if ((char)c == s[i])
		lo = ((char *)&s[i]);
	return (lo);
}
