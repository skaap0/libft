/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:20:06 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/02 14:43:34 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_c(char const c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	check_s(const char *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (check_c(s1[i], set) == 0)
			break ;
		i++;
	}
	return (i);
}

static size_t	check_e(char const *s1, char const *set, size_t i)
{
	while (i > 0)
	{
		i--;
		if (check_c(s1[i], set) == 0)
			break ;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s;
	int		e;
	int		i;
	char	*new;

	if (!s1 || !set)
		return (0);
	e = ft_strlen(s1);
	s = check_s(s1, set);
	if (s != e)
		e = check_e(s1, set, e);
	new = (char *)malloc(sizeof(char) * ((e - s) + 1));
	if (new != NULL)
	{
		i = 0;
		while (s < e)
		{
			new[i] = s1[s];
			i++;
			s++;
		}
		new[i] = '\0';
	}
	return (new);
}
