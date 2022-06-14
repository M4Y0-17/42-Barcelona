/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:41:57 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/05/12 15:24:33 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_isalpha(int x);
int				ft_isdigit(int x);
int				ft_isalnum(int x);
int				ft_isascii(int x);
int				ft_isprint(int x);
int				ft_strlen(const char *str);
void			*ft_memset(void *str, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t n);
size_t			ft_strlcpy(char *dest, char *src, size_t dstsize);
size_t			ft_strlcat(char *dest, char *src, size_t size);
int				ft_toupper(int x);
int				ft_tolower(int x);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t nitems, size_t size);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strnstr(const char	*big, const char *little, size_t len);
char			*ft_appendc(char *start, char c);

#endif