/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:06:42 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/05 10:52:45 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*first_occurence;

	i = 0;
	first_occurence = NULL;
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
		{
			first_occurence = ((char *) s + i);
			return (first_occurence);
		}
		i++;
	}
	if ((char)c == s[i])
	{
		first_occurence = ((char *) s + i);
		return (first_occurence);
	}
	return (first_occurence);
}

// int     main()
// {
//     char s[] = "1-2-3-4-5-6-7-8--8-8--8-4------4--4";
//     int c;

//     c = '-';

//     printf("result = %s\n", ft_strchr(s, c));
//     printf("result = %s", strchr(s, c));
//     return 0;
// }