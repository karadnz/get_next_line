/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:24:54 by mkaraden          #+#    #+#             */
/*   Updated: 2022/12/03 13:17:52 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"


#include <stdio.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int i = 0;
	while (*str)
	{
		write(1,str,1);
		str++;
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	
	stash = ft_init_stash(fd, stash);
	ft_putstr(stash);


	line = ft_init_line(stash,line);
	ft_putstr(line);

	ft_edit_stash(stash);
	



	return (line);
}

char	*ft_init_stash(int fd, char *stash)
{
	char	*buffer;
	int rd;

	rd = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));

	while (!check_newline(stash) && rd)
	{
		
		rd = read(fd, buffer, BUFFER_SIZE);
		//ft_putstr(buffer);
		stash = ft_strjoin(stash, buffer);
		//ft_putstr(stash);
	}
	
	return(stash);

}

char	*ft_init_line(char *line, char *stash)
{
	int i = 0;
	while(stash[i] && stash[i] != '\n')
	{
		i++;
	}

	line = malloc(sizeof(char) * (i + 2)); // \n ve \0 icin

	i = 0;
	while(stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if(stash[i] == '\n')
	{
		line[i] = '\n';
	}
	line[i] = '\0';
	return(line);

}


void	ft_edit_stash(char *stash)
{
	char *new_stash;
	int stash_length;

	stash_length = ft_strlen(stash);

	int i = 0;
	while(stash[i] && stash[i] != '\n')
	{
		i++;
	}
	new_stash = malloc((stash_length - i + 1) * sizeof(char));
	
	
	while(stash[i])
	{
		new_stash[i] = stash[i];
		i++;
	}
	new_stash[i] = '\0';
	i = 0;
	while(new_stash[i] != '\0')
	{
		stash[i] = new_stash[i];
		i++;
	}
	stash[i] = '\0';
}


int main()
{


	int fd = open("yazi.txt", O_RDONLY | O_CREAT);

	

	printf("%s\n", get_next_line(fd));
	

}