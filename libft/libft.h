/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:23:39 by vpalamar          #+#    #+#             */
/*   Updated: 2018/11/18 17:35:53 by vpalamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# define BUFF_SIZE 1

# define ABS(x) ((x<0) ? -(x) : x)

int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_atoi(const char *string);
char			*ft_strncpy(char *destptr, const char *srcptr, size_t num);
char			*ft_strcpy(char *destptr, const char *srcptr);
size_t			ft_strlen(const char *string);
char			*ft_strcat(char *destptr, const char *srcptr);
char			*ft_strncat(char *destptr, char *srcptr, size_t num);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *string, int symbol);
char			*ft_strrchr(const char *string, int symbol);
char			*ft_strdup(const char *str);
char			*ft_strstr(const char *string1, const char *string2);
char			*ft_strnstr(const char *s1, const char *s2, size_t length);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strncmp(const char *str1, const char *str2, size_t num);
void			*ft_memset(void *memptr, int val, size_t num);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *destptr, const void *srcptr, size_t num);
void			*ft_memccpy(void *d, const void *s, int ch, size_t count);
void			*ft_memmove(void *dest, const void *src, size_t num);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void			*ft_memchr(const void *ptr, int c, size_t num);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			**ft_strsplit(char const *s, char c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

int				ft_nbwords(char *s, char c);
char			*ft_strrev(char *s);
char			*ft_swap(char *s1, int c1, int c2);
char			*ft_strskip(char const *s, char c);

char			*ft_strndup(const char *str, int len);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_mlist
{
	char			*content;
	int				fd;
	struct s_mlist	*next;
}				t_mlist;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int				get_next_line(const int fd, char **line);

typedef struct	s_field
{
	int		flags[6];
	size_t	width;
	size_t	precision;
	int		size;
	int		type;
	int		is_null;
	char	*arr;
	size_t	buff_size;
	char	c;
}				t_field;

typedef struct	s_type
{
	size_t			unsign;
	ssize_t			sign;
	char			t_char;
	char			*t_str;
	long double		t_ldouble;
	void			*t_void;
}				t_type;

int				ft_printf(const char *format, ...);
void			print_structure(va_list args, t_field *field);
int				fill_structure(const char *form, va_list args, t_field *f);

int				detection(char c);
void			clear_field(t_field *field);
void			clear_type(t_type *type);
void			increase_arr(size_t len, t_field *field);
void			check_arr(t_field *field);

void			get_value_unsign(va_list args, t_type *v, t_field *f);
void			get_value_sign(va_list args, t_type *v, t_field *f);
void			get_value(va_list args, t_type *v, t_field *f);
void			get(va_list args, t_type *v, t_field *f);

ssize_t			diff_width(t_field *field, t_type *value_type);
void			print_flag_minus(t_type *value_type, t_field *field);
void			print_sign(t_type *v_t, t_field *f);
void			print_precision(t_type *value_type, t_field *field);

void			put_symbol(ssize_t num, char c, t_field *field);
void			str_in_arr(char *s, t_field *field);
void			print_value(t_type *value_type, t_field *field);

int				ft_flags(const char *format, t_field *field);
int				ft_width_precision(const char *form, va_list a, t_field *f);
int				ft_size(const char *format, t_field *field);
void			ft_type(char c, t_field *field);

void			ft_putlonglong(ssize_t n, t_field *f);
void			ft_putulonglong(size_t n, t_field *f);
void			ft_putdouble(long double n, t_field *f);
size_t			ft_llintlen(ssize_t nb);
size_t			ft_ullintlen(size_t nb);

char			*ft_octa(size_t n, t_field *field);
char			*ft_hex(size_t n, t_field *field);

size_t			ft_intlen(ssize_t nb);
size_t			ft_strlen(const char *string);
char			*ft_strnew(size_t size);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strrev(char *s);
char			*ft_swap(char *s, int c1, int c2);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *memptr, int val, size_t num);
char			*ft_strdup(const char *str);
#endif
