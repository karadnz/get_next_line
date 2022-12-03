/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:25:17 by mkaraden          #+#    #+#             */
/*   Updated: 2022/12/03 12:50:30 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char	*dst, char *src, size_t	dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	if (!dstsize)
		return (srcsize);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
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