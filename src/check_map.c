#include "../Includes/header.h"

int	ft_isdigit(char *c)
{
	int	n;

	n = 0;
	while (c[n])
	{
		if ((c[n] < 48 || c[n] > 57))
			return (1);
		n++;
	}
	return (0);
}
void free_table(char** str)
{
	int i;

	i =0;
	while( str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void check_of_repet(char **str)
{
	int i;
	int v;
	char *temp;

	i = 0;
	while(str[i])
	{
		temp = str[i];
		if(str[i + 1])
		{
			v = i + 1;
			while(str[v])
			{
				if(ft_strcmp(str[v],temp) == 0)
				{
					printf("Error\n");
					exit(1);
				}
				v++;
			}
		}
		i++;
	}
	if(i != 6)
	{
		printf("Error\n");
		exit(1);
	}

}

char **check_of_contaner(char *str)
{
	int i;
	int v;
	int length;
	int size;
	char **c;

	i = 0;
	length = 0;
	c = ft_split(str,'\n');
	while(c[i])
	{
		v = 0;
		while(c[i][v])
			v++;
		if (length < v )
			length = v;
		i++;
	}
	i = 0;
	while(c[i])
	{
		if(ft_strlen(c[i]) < (size_t)length)
		{
			v = ft_strlen(c[i]);
			while(v < length)
			{
				c[i] = ft_strjoin(c[i]," ");
				v++;
			}
		}
		i++;
	}
	size = i;
	i = 0;
	while(c[i])
	{
		v = 0;
		while(c[i][v])
		{
			if((v == 0 && c[i][v] != 32 && c[i][v] != 9 && c[i][v] != 49) || (c[i][v + 1] == '\0' && c[i][v] != 32 && c[i][v] != 9 && c[i][v] != 49))
			{
				printf("%d  %d\n", i , v);
				printf("Error\n");
				exit(1);
			}
			if((i == 0 && c[i][v] != 32 && c[i][v] != 9 && c[i][v] != 49) || (c[i + 1] == '\0' && c[i][v] != 32 && c[i][v] != 9 && c[i][v] != 49))
			{
				printf("%d  %d\n", i , v);
				printf("Error\n");
				exit(1);
			}
			if(c[i][v + 1] != '\0' && c[i][v] == 32 && c[i][v + 1] != 32 && c[i][v + 1] != 49)
			{
				printf("%d  %d\n", i , v);
				printf("Error\n");
				exit(1);
			}
			if(v != 0 && c[i][v] == 32 && c[i][v - 1] != 49 && c[i][v - 1] != 32)
			{
				printf("%d  %d\n", i , v);
				printf("Error\n");
				exit(1);
			}
			if(c[i + 1 ] != '\0' && c[i][v] == 32 && c[i + 1][v] != 49 && c[i + 1][v] != 32)
			{
				printf("%d  %d\n", i , v);
				printf("Error\n");
				exit(1);
			}
			if(i != 0 && c[i][v] == 32 && c[i - 1][v] != 49 && c[i - 1][v] != 32)
			{
				printf("%d  %d\n", i , v);
				printf("Error\n");
				exit(1);
			}
			v++;
		}
		i++;
	}
	return(c);
}

char **check_map(char *str)
{
	int fd;
	int i;
	char	*a;
	int end_of_string;
	char **temp_of_color;
	char **temp_of_repet;
	char *stack_symbol_of_lines;
	char temp_stack_symbol[2];
	int count_rows;
	char *map_contaner;

	fd = open(str,O_RDONLY);
	stack_symbol_of_lines = ft_strdup("");
	temp_stack_symbol[0] = '\0';
	temp_stack_symbol[1] = '\0';
	count_rows = 0;
	map_contaner = ft_strdup("");
	while ((a = get_next_line(fd)) != NULL)
	{
		i = 0;
		while (a[i])
		{
			if(a[i] == '\n')
				break;
			if (a[i] == 9 || a[i] == 32)
				i++;
			else if (ft_strncmp(&a[i],"NO",2) == 0 || ft_strncmp(&a[i],"SO",2) == 0 || ft_strncmp(&a[i],"WE",2) == 0 || ft_strncmp(&a[i],"EA",2) == 0)
			{
				end_of_string = 0;
				while(end_of_string < 2)
				{
					temp_stack_symbol[0] = a[i];
					stack_symbol_of_lines = ft_strjoin(stack_symbol_of_lines,temp_stack_symbol);
					i++;
					end_of_string++;
				}
				stack_symbol_of_lines = ft_strjoin(stack_symbol_of_lines, ",");
				while(a[i] == 9 || a[i] == 32)
					i++;
				i += 2;
				end_of_string = i;
				while (a[end_of_string])
					end_of_string++;
				a[end_of_string - 1] = '\0';
				if(open(&a[i], O_RDONLY) < 0)
				{
					printf("%s %d\n",&a[i],i);
					printf("Error\n");
					exit(1);
				}
				else
					break;
			}
			else if (a[i] == 70 || a[i] == 67)
			{
				temp_stack_symbol[0] = a[i];
				stack_symbol_of_lines = ft_strjoin(stack_symbol_of_lines,temp_stack_symbol);
				stack_symbol_of_lines = ft_strjoin(stack_symbol_of_lines, ",");
				i += 2;
				while(a[i] == 9 || a[i] == 32)
					i++;
				end_of_string = i;
				while (a[end_of_string])
					end_of_string++;
				a[end_of_string - 1] = '\0';
				temp_of_color = ft_split(&a[i],',');
				end_of_string = 0;
				while(temp_of_color[end_of_string])
				{
					if(ft_isdigit(temp_of_color[end_of_string]) == 1)
					{
						printf("Error\n");
						exit(0);
					}
					if(ft_atoi(temp_of_color[end_of_string]) > 255)
					{
						printf("Error\n");
						exit(0);
					}
					end_of_string++;
				}
				free_table(temp_of_color);
				temp_of_color = NULL;
				if (end_of_string > 3)
				{
					printf("Error\n");
					exit(0);
				}
				break;
			}
			else if(ft_strncmp(&a[i],"1",1) == 0 || ft_strncmp(&a[i],"0",1) == 0)
			{
				map_contaner = ft_strjoin(map_contaner,a);
				count_rows++;
				break;
			}
		}
		free(a);
	}
	temp_of_repet = ft_split(stack_symbol_of_lines,',');
	check_of_repet(temp_of_repet);
	free_table(temp_of_repet);
	temp_of_repet = NULL;
	temp_of_repet = check_of_contaner(map_contaner);
	return(temp_of_repet);
}