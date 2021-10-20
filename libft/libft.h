/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschumac <nschumac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:39:43 by nschumac          #+#    #+#             */
/*   Updated: 2021/06/22 13:53:28 by nschumac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int				ft_atoi(const char *str);

void			ft_bzero(void *s, unsigned int n);

int				ft_toupper(int c);

void			*ft_calloc(unsigned int num, unsigned int size);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft__isprint(int c);

char			*ft_itoa(int num);

int				ft_abs(int num);

void			*ft_memccpy(void *restrict dest, const void *restrict src,
					int c, unsigned long n);

void			*ft_memchar(void *ptr, int value, unsigned long n);

int				ft_memcmp(const void *ptr1, const void *ptr2, unsigned long n);

void			*ft_memcpy(void *dest, const void *src, unsigned long n);

void			*ft_memmove(void *dest, const void *src, unsigned long n);

void			*ft_memset(void *str, int c, unsigned long n);

char			**ft_split(char *s, char c);

char			*ft_strchr(char *str, int chr);

char			*ft_strdup(const char *str);

char			*ft_strjoin(const char *s1, const char *s2);

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long n);

unsigned long	ft_strlcpy(char *dest, const char *src, unsigned long n);

unsigned long	ft_strlen(const char *str);

int				ft_strncmp(const char *str1, const char *str2, unsigned long n);

char			*ft_strnstr(const char *str1, const char *str2, int n);

char			*ft_strrchr(const char *str, int chr);

char			*ft_strtrim(const char *s, const char *set);

char			*ft_substr(const char *s, unsigned int startm,
					unsigned long len);

int				ft_tolower(int c);

int				ft_toupper(int c);

char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));

void			ft_putchar_fd(char c, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putunbr_fd(unsigned int n, int fd);

void			ft_putnbrbase_fd(unsigned long long n, int fd, const char *set);

void			ft_putstr_fd(char *s, int fd);

char			*ft_itoabase(unsigned long long num, const char *set);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);

void			ft_lstadd_front(t_list **lst, t_list *new);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_back(t_list **lst, t_list *new);

void			ft_lstdelone(t_list *lst, void (*del)(void *));

void			ft_lstclear(t_list **lst, void (*del)(void *));

void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
