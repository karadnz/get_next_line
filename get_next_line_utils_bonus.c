/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:11:42 by mkaraden          #+#    #+#             */
/*   Updated: 2022/12/05 16:15:36 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>

size_t	ft_strlen(char *str)
//null terminate olmadan geliyor malloc yerine calloc yap
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && (i < (dstsize - 1)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rt;
	int		s1_len;
	int		s2_len;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	s1_len = (ft_strlen((char *)s1));
	s2_len = (ft_strlen((char *)s2));
	rt = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (rt == NULL)
		return (NULL);
	ft_strlcpy(rt, s1, s1_len + 1);
	ft_strlcpy(&rt[s1_len], s2, s2_len + 1);
	free(s1);
	return (rt);
}
/*char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*rt;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	rt = (char *)malloc(len + 1);
	if (rt == NULL)
		return (NULL);
	while (s1[i])
	{
		rt[i] = s1[i];
		i++;
	}
	while (s2[j])
		rt[i++] = s2[j++];
	rt[i] = '\0';
	free(s1);
	return (rt);
}*/

int	check_newline(char *ptr)
{
	if (!ptr)
		return (0);
	while (*ptr)
	{
		if (*ptr == '\n')
			return (1);
		ptr++;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*rt;
	size_t	len;

	len = ft_strlen(str);
	rt = malloc(sizeof(char) * (len + 1));
	if (!rt)
		return (0);
	ft_strlcpy(rt, str, len + 1);
	return (rt);
}
