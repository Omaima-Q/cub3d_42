/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaimaqaroot <omaimaqaroot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:16:43 by omaimaqaroo       #+#    #+#             */
/*   Updated: 2025/10/17 20:32:29 by omaimaqaroo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
#include <errno.h>
# include <unistd.h>
#include <stdio.h>
# include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(const char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_printf(int fd, const char *format, ...);
char	*get_next_line(int fd);
int		cut_n_chars(char **str, ssize_t n, ssize_t len);
int		ft_checkwarn_argc(int argc, int min_argc, int max_argc);
int		ft_checkwarn_open_fd(int fd);
int		ft_is_atoi_compatible(char *str);
int		ft_str_is_int(char *str);
char	**ft_split_v(char const *s, char const *c);
int		ft_isspace(int c);
char	**ft_split_wspace(char const *s);
int		ft_min(int x, int y);
int		ft_dim(int x, int y);
void	ft_free(void **ptr);
char	*ft_getenv(const char *name, char **envp);
int		ft_setenv(const char *name, const char *value, int overw, char ***envp);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_copy_strv(const char **strv);

#endif
