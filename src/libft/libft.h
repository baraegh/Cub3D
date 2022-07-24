/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmohamm <brmohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:36:19 by brmohamm          #+#    #+#             */
/*   Updated: 2022/06/12 22:54:09 by brmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_isalpha(int c);
int		ft_isdigit(char *c);
int		ft_isalnum(char *c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int value, size_t count);
int		ft_toupper(int chr);
char	*ft_tolower(char *str);
char	*ft_strchr( const char *str, int c );
char	*ft_strrchr( const char *str, int c );
void	ft_bzero(void *str, size_t count);
int		ft_strncmp( const char *s1, const char *s2, size_t length);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_memcpy( void *destination, const void *source, size_t size );
void	*ft_memmove( void *destination, const void *source, size_t size );
char	*ft_strnstr(const char *s, const char *find, size_t slen);
int		ft_memcmp( const void *s1, const void *s2, size_t size );
void	*ft_memchr( const void *membk, int serchar, size_t size );
int		ft_atoi(const char *str);
char	*ft_strdup( const char *src );
void	*ft_calloc( size_t count, size_t size );
int		ft_strcmp( const char *s1, const char *s2);

	/*--------------Second part-------*/

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

	/*--------------Bonus------------*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
#endif