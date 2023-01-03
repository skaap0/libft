/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:41:18 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/03 11:55:52 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_str(const char *s, char c)
{
	int	nbr_str;

	nbr_str = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != '\0' && *s != c)
				s++;
			nbr_str++;
			continue ;
		}
		s++;
	}
	return ((nbr_str));
}

static char	**ft_free_array(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	ft_next_start(const char *s, char c, int last_index)
{
	int	i;

	i = last_index;
	while (s[i] != '\0')
	{
		if (s[0] != c && i == 0)
			return (0);
		if (s[i] == c && (s[i + 1] != c || s[i + 1] == '\0'))
			return (i + 1);
		i++;
	}
	return (-1);
}

static int	ft_next_stop(const char *s, char c, int last_index)
{
	int	i;

	i = last_index;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

char	**ft_split(const char *s, char c)
{
	int		nbs;
	char	**array;
	int		i;
	int		index;
	int		stop;

	if (!s)
		return (NULL);
	nbs = ft_nb_str(s, c);
	array = (char **)ft_calloc(((nbs) + 1), sizeof(char *));
	index = ft_next_start(s, c, 0);
	i = 0;
	if (!array)
		return (NULL);
	while (i < (nbs))
	{
		stop = ft_next_stop(s, c, index);
		array[i] = ft_substr(s, index, ((stop - index) + 1));
		index = ft_next_start(s, c, stop);
		if (!array[i])
			return (ft_free_array(array, i));
		i++;
	}
	array[i] = NULL;
	return (array);
}
