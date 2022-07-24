#include "../Includes/header.h"

char	*end(char *index)
{
	int		i;
	char	*c;

	if (!index)
		return (NULL);
	i = 0;
	while (index[i] && index[i] != '\n')
		i++;
	if (index[i] == '\n')
		c = (char *)malloc(sizeof(char) * (i + 2));
	else
		c = (char *)malloc(sizeof(char) * (i + 1));
	if (c == NULL)
		return (0);
	i = 0;
	while (index[i] && index[i] != '\n')
	{
		c[i] = index[i];
		i++;
	}
	if (index[i] == '\n')
		c[i++] = '\n';
	c[i] = '\0';
	return (c);
}

char	*deletbegin(char *index)
{
	int		i;
	char	*c;
	int		l;

	i = 0;
	while (index[i] && index[i] != '\n')
		i++;
	if (!index[i])
	{
		free(index);
		return (NULL);
	}
	c = (char *)malloc(ft_strlen(index) - i);
	if (!c)
		return (NULL);
	l = 0;
	i++;
	while (index[i] != '\0')
		c[l++] = index[i++];
	c[l] = '\0';
	free(index);
	return (c);
}

char	*loop(char *index, int fd)
{
	int				error ;
	char			*buffer;

	error = 1;
	buffer = malloc(sizeof(char) * 1000 + 1);
	if (!buffer)
		return (0);
	if (index == NULL)
		index = ft_strdup("");
	while (ft_strchr(index, '\n') == 0 && error > 0)
	{
		error = read(fd, buffer, 1000);
		if (error == -1)
		{
			free(buffer);
			free(index);
			return (NULL);
		}
		buffer[error] = '\0';
		index = ft_strjoin(index, buffer);
	}
	free(buffer);
	return (index);
}

char	*get_next_line(int fd)
{
	static char		*index;
	char			*temp;

	if (fd < 0)
	{
		free (index);
		return (0);
	}
	index = loop(index, fd);
	if (index == NULL)
	{
		return (0);
	}
	if (!index[0])
	{
		free(index);
		index = 0;
		return (0);
	}
	temp = end(index);
	index = deletbegin(index);
	return (temp);
}

/*
int main(int ac, char **av)
{
	int fd;
	ssize_t x;
	if(ac == 2)
	{
		fd = open(av[1],O_RDONLY);
		char	*a;
		//printf("%s",line);
		while ((a = get_next_line(fd)) != NULL)
		{
			printf("%s",a);
			free(a);
		}
		//printf("%s",get_next_line(fd));
		//  printf("%s",get_next_line(fd));
		// printf("%s",get_next_line(fd));
		// printf("%s",get_next_line(fd));
		// printf("%s",get_next_line(fd));
	 }

} 
*/
