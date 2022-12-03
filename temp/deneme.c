#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define  BUFFER_SIZE  13

//ssize_t read(int fildes, void *buf, size_t nbyte);
//https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/


//return Number of bytes read on success
//return 0 on reaching end of file
//return -1 on error
//return -1 on signal interrupt


char *get_next_line(int fd);
char *ft_rline(int fd, char *buffer);


char *get_next_line(int fd)
{
	static char *buffer; //str array
	char *line;

	

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));

	read(fd, buffer, BUFFER_SIZE);

	int lLen = 0;
	while(buffer[lLen] != '\n')
	{
		lLen++;
	}

	line = malloc((lLen + 1) * sizeof(char));

	int i = 0;

	while(buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';

	return (line);

}

char *ft_rline(int fd, char *buffer)
{

	

	return (buffer);

}


int main()
{
	char *line = malloc(sizeof(char) * 10);
	free(line);


	int bsize = 6;

	int fd = open("yazi.txt", O_RDONLY | O_CREAT);
	printf("fd = %d\n", fd);

	

	printf("%s$\n", get_next_line(fd));
	printf("%s$\n", get_next_line(fd));

	//printf("%s$\n", get_next_line(fd));

	//printf("%s$\n", get_next_line(fd));

	close(fd);
}



/*
	printf("return %zd \n",read(fd, line, BUFFER_SIZE));
	printf("line = %s$\n", line);

	printf("return %zd \n",read(fd, line, BUFFER_SIZE));
	printf("line = %s$\n", line);

	printf("return %zd \n",read(fd, line, BUFFER_SIZE));
	printf("line = %s$\n", line);

	printf("return %zd \n",read(fd, line, BUFFER_SIZE));
	printf("line = %s$\n", line);

\n de karakter 
offset
fd = 3
return 6
line = 12345
$
return 6
line = aaaaa
$
return 6
line = bbbbb
$
return 5
line = ccccc
$
*/
