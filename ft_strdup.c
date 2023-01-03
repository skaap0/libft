/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfranchi <tfranchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 17:34:07 by tfranchi          #+#    #+#             */
/*   Updated: 2023/01/03 13:53:22 by tfranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		len;
	int		i;

	len = ft_strlen(src) + 1;
	dst = (char *)ft_calloc((len), sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ft_memmove(dst, src);
		i++;
	}
	dst[i] = 0;
	return (dst);
}
