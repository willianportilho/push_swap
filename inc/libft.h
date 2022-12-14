/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:58:58 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/01 23:30:12 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define BUFFER_SIZE 1024

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
int			ft_atoi(const char *nptr);
long		ft_atol(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstclear_alt(t_list **lst);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstdelone_all(t_list *lst);
void		ft_lstiter(t_list *lst, void (*f)(void *));

typedef struct s_list_n
{
	int				content;
	struct s_list_n	*next;
}					t_list_n;

t_list_n	*ft_lstcpy_n(t_list_n *lst);
t_list_n	*ft_lstncpy_n(t_list_n *lst, int n);
t_list_n	*ft_lstlast_n(t_list_n *lst);
t_list_n	*ft_lstnew_n(int content);
int			ft_lstsize_n(t_list_n *lst);
void		ft_lstadd_back_n(t_list_n **lst, t_list_n *new);
void		ft_lstadd_front_n(t_list_n **lst, t_list_n *new);
void		ft_lstclear_n(t_list_n **lst);
void		ft_lstdelone_n(t_list_n *lst);

char		*get_next_line(int fd);
char		*cut_act(char *actual);
char		*line_to_send(char *actual);
char		*ft_strjoin_alt(char *s1, char *s2);
int			check_break(char *actual);

int			ft_printf(const char *s, ...);
void		ft_print_c(char c);
void		ft_print_p(size_t n);
void		ft_print_x_lower(unsigned int n);
void		ft_print_x_upper(unsigned int n);
void		ft_print_u(unsigned int n);
void		ft_print_d_i(int n);
void		ft_print_s(char *s);
void		ft_pre_c(int n, int *i, int *len);
void		ft_pre_p(size_t n, int *i, int *len);
void		ft_pre_x_lower(unsigned int n, int *i, int *len);
void		ft_pre_x_upper(unsigned int n, int *i, int *len);
void		ft_pre_u(unsigned int n, int *i, int *len);
void		ft_pre_d_i(int n, int *i, int *len);
void		ft_pre_s(char *s, int *i, int *len);

#endif