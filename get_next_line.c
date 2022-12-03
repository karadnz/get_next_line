/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaraden <mkaraden@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:24:54 by mkaraden          #+#    #+#             */
/*   Updated: 2022/12/03 14:43:25 by mkaraden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include "get_next_line_utils.c"


#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;
	line = 0;

	
	stash = ft_init_stash(fd, stash);
	//printf("init stash: %s$\n",stash);


	line = ft_init_line(line,stash);
	//printf("%s$\n",line);
	

	stash = ft_edit_stash(stash);
	//printf("edited stash: %s$\n",stash);
	



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
		buffer[rd] = '\0';
		stash = ft_strjoin(stash, buffer);
		//ft_putstr(stash);
		//printf("loop stash: %s$\n",stash);
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
	if(stash[i] == '\n')
	{
		i++;
	}

	line = malloc(sizeof(char) * (i + 1)); // \n ve \0 icin (i + 2)

	i = 0;
	while(stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if(stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}

	line[i] = '\0';
	return(line);

}


char	*ft_edit_stash(char *stash)
{
	char *new_stash;
	int stash_length;

	stash_length = ft_strlen(stash);

	int i = 0;
	while(stash[i] && stash[i] != '\n')
	{
		i++;
	}
	if (stash[i] == '\n')
	{
		i++;
	}
	new_stash = malloc((stash_length - i + 1) * sizeof(char));
	
	int j = 0;
	while(stash[i])
	{
		new_stash[j] = stash[i];
		i++;
		j++;
	}
	new_stash[i] = '\0';
	
	return(new_stash);
}


/*int main()
{


	int fd = open("yazi.txt", O_RDONLY | O_CREAT);

	

	printf("line: %s$\n", get_next_line(fd));
	printf("line: %s$\n", get_next_line(fd));
	

}*/