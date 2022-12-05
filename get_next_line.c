/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:24:54 by mkaraden          #+#    #+#             */
/*   Updated: 2022/12/05 13:34:27 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		return (NULL);
	}
	stash = ft_init_stash(fd, stash);
	if (!stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_init_line(line, stash);
	stash = ft_edit_stash(stash);
	return (line);
}

char	*ft_init_stash(int fd, char *stash)
{
	char	*buffer;
	int		rd;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (!check_newline(stash) && rd)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(stash);
			stash = NULL;
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*ft_init_line(char *line, char *stash)
{
	int	i;

	i = 0;
	if (!stash)
	{
		return (NULL);
	}
	line = malloc(sizeof(char) * (ft_strlen(stash) + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_edit_stash(char *stash)
{
	char	*new_stash;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		i++;
	}
	if (stash[i] == '\n')
	{
		i++;
	}
	new_stash = ft_strdup(stash + i);
	if (!new_stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	free(stash);
	stash = NULL;
	return (new_stash);
}
/*int main()
{
	int fd = open("yazi.txt", O_RDONLY | O_CREAT);
	int fd2 = open("yazi2.tx", O_RDONLY);
	int len = 9; //line + 1

	for(int i = 0; i < len; i++)
	{
		printf("%s$\n",get_next_line(fd));
	}

	// printf("%s$\n",get_next_line(fd));
	// printf("%s$\n",get_next_line(fd2));
	// printf("%s$\n",get_next_line(fd));
	// printf("%s$\n",get_next_line(fd));
	
	return(0);
	printf("input:\n");
	//get_next_line(0);
	//printf("%s$\n",get_next_line(0));


}*/