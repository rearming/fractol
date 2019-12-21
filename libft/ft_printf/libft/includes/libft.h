/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:58:41 by sselusa           #+#    #+#             */
/*   Updated: 2019/10/23 12:24:17 by sleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
**	[Includes]
*/
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# include "ft_defines.h"
# include "ft_structs.h"
# include "ft_btrees.h"

/*
**	[Defines]
*/
# define OVERFLOW_FT 922337203685477580L

/*
**	Fills (src) with (len) bytes of (chr). Returns a pointer to the
**	filled memory.
*/
void				*ft_memset(void *src, int chr, size_t len);

/*
**	Fills (src) with (len) zero bytes.
*/
void				ft_bzero(void *src, size_t len);

/*
**	Copies into (dst) from (src) for (len) bytes. Return a pointer
**	to (dst) start.
*/
void				*ft_memcpy(void *dst, const void *src, size_t len);

/*
**	Copies into (dst) from (src) for (len) bytes or until (chr)
**	is reached. If (chr) is reached, return pointer to (dst) after the
**	copy of (chr). Else, a NULL is returned.
*/
void				*ft_memccpy(void *dst, const void *src,
	int chr, size_t len);

/*
**	Non-destructively copies into (dst) from (src) for (len) bytes.
**	Returns a pointer to (dst).
*/
void				*ft_memmove(void *dst, const void *src, size_t len);

/*
**	Finds in (src) the first occurence of (chr) until (len) bytes.
**	Return a pointer to the found symbol in (src), or NULL if not found.
*/
void				*ft_memchr(const void *src, int chr, size_t len);

/*
**	Compares (mem1) and (mem2) for (len) symbols. Returns (*mem1 - *mem2)
**	of the first difference or 0, if areas are identical.
*/
int					ft_memcmp(const void *mem1, const void *mem2, size_t len);

/*
**	Returns the amount of symbols in (str) string, excluding '\0'.
*/
size_t				ft_strlen(const char *src);

/*
**	Creates a new string, with content of (src). Returns a pointer to the
**	new string.
*/
char				*ft_strdup(const char *src);

/*
**	Copies into (dst) string from (src) string. Returns a pointer to (dst).
*/
char				*ft_strcpy(char *dst, const char *src);

/*
**	Copies into (dst) string from (src) string at most (len) symbols.
**	If (src) is less than (len) characters long, the remainders
**	of (dst) is filled with \0.
*/
char				*ft_strncpy(char *dst, const char *src, size_t len);

/*
** Adds to (str1) string a copy of (str2) string, explicitly adding a \0.
** Returns a pointer to (str1).
*/
char				*ft_strcat(char *str1, const char *str2);

/*
**	Adds to (str1) string a copy of (str2) string, not more than (len)
**	characters, explicitly adding a \0. Returns a pointer to (str1).
*/
char				*ft_strncat(char *str1, const char *str2, size_t len);

/*
**	Adds to (dst) string a copy of (src) string, not more than (len)
**	characters, size of target included, explicitly adding a \0.
**	You really don't want to know what it returns.
*/
size_t				ft_strlcat(char *dst, const char *src, size_t len);

/*
**	Finds in the (src) string the first occurence of (chr), including \0.
**	Returns a pointer to the symbol in (src).
*/
char				*ft_strchr(const char *src, int chr);

/*
**	Finds in the (src) string the last occurence of (chr), including \0.
**	Returns a pointer to the symbol in (src).
*/
char				*ft_strrchr(const char *src, int chr);

/*
**	Looks in the (haystack) string for the first occurence of (needle) string.
**	Returns a pointer to the (needle) in (string), or NULL if none found.
*/
char				*ft_strstr(const char *haystack, const char *needle);

/*
**	Looks in the (haystack) string for the first occurence of (needle) string,
**	not more than (len) symbols. Returns a pointer to the (needle) in
**	(haystack), or NULL if none found.
*/
char				*ft_strnstr(const char *haystack, const char *needle,
	size_t len);

/*
**	Compares (str1) string with (str2) string. Returns (*str1 - *str2)
**	of the first difference or 0, if strings are identical.
*/
int					ft_strcmp(const char *str1, const char *str2);

/*
**	Compares (str1) string with (str2) string, not more than (len) symbols.
**	Returns (*str1 - *str2) of the first difference or 0,
**	if strins are identical.
*/
int					ft_strncmp(const char *str1, const char *str2, size_t len);

/*
**	Converts (str) into an integer. Trims leading space characters,
**	supports +- symbols and leading zeros. Returns an int, an
**	overflow int or 0/-1 if a long overflow happens.
*/
int					ft_atoi(const char *str);

/*
**	Checks whether (chr) is in the 'a' - 'z' or 'A' - 'Z' range.
*/
int					ft_isalpha(int chr);

/*
**	Checks whether (chr) is in the '0' - '9' range.
*/
int					ft_isdigit(int chr);

/*
**	Checks whether (chr) is in the 'a' - 'z' / 'A' - 'Z' / '0' - '9' range.
*/
int					ft_isalnum(int chr);

/*
**	Checks whether (chr) is in the 0 - 127 range.
*/
int					ft_isascii(int chr);

/*
**	Checks whether (chr) is in the 32 - 126 range.
*/
int					ft_isprint(int chr);

/*
**	Converts 'A' - 'Z' to 'a' - 'z'
*/
int					ft_tolower(int chr);

/*
**	Converts 'a' - 'z' to 'A' - 'Z'
*/
int					ft_toupper(int chr);

/*
**	Allocates a memory area of (size) bytes and fills it with zeroes.
**	Returns a pointer to the new string.
*/
void				*ft_memalloc(size_t size);

/*
**	Frees *(ap) and sets it to NULL.
*/
void				ft_memdel(void **ap);

/*
**	Creates a \0 initialized string of (size) + 1.
*/
char				*ft_strnew(size_t size);

/*
**	Frees *(as) and sets it to NULL
*/
void				ft_strdel(char **as);

/*
**	Sets all symbols of (s) to 0
*/
void				ft_strclr(char *s);

/*
**	For every symbol in (s) applies the function (*f).
*/
void				ft_striter(char *s, void (*f)(char *));

/*
**	For every symbol in (s) applies the function (*f)
**	with given index.
*/
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
**	Creates a new string, of symbols (s), to which (*f) has been applied.
*/
char				*ft_strmap(char const *s, char (*f)(char));

/*
**	Creates a new string, of symbols (s), to which (*f) has been applied.
*/
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
**	Checks whether (s1) string and (s2) string are identical.
*/
int					ft_strequ(char const *s1, char const *s2);

/*
**	Checks whether (s1) string and (s2) string are identical
**	for (n) symbols.
*/
int					ft_strnequ(char const *s1, char const *s2, size_t n);

/*
**	Creates a new string, cut from (s), starting
**	from (start) position, (length) symbols in length.
*/
char				*ft_strsub(char const *s, unsigned int start, size_t len);

/*
**	Creates a new string, that is a combination of (s1) string and (s2) string.
*/
char				*ft_strjoin(char const *s1, char const *s2);

/*
**	Creates a new string from (s), that is trimmed of whitespaces, newlines
**	and tabs.
*/
char				*ft_strtrim(char const *s);

/*
**	Splits (s) divided by (c) into an array of new strings.
**	Return array is \0 terminated.
*/
char				**ft_strsplit(char const *s, char c);

/*
**	Converts (n) int to a string. Returns a pointer to the new string.
*/
char				*ft_itoa(int n);

/*
**	Writes char (c) to console.
*/
void				ft_putchar(char c);

/*
**	Writes (s) to console.
*/
void				ft_putstr(char const *s);

/*
**	Writes (s) to console and adds a '\n'.
*/
void				ft_putendl(char const *s);

/*
**	Writes int (n) to console.
*/
void				ft_putnbr(int n);

/*
**	Writes char (c) to (fd) file.
*/
void				ft_putchar_fd(char c, int fd);

/*
**	Writes (s) to console to (fd) file.
*/
void				ft_putstr_fd(const char *s, int fd);

/*
**	Writes (s) to console to (fd) followed by newline.
*/
void				ft_putendl_fd(char const *s, int fd);

/*
**	Writes int (n) to console to (fd) file.
*/
void				ft_putnbr_fd(int n, int fd);

/*
**	Creates a new t_list with a copy of (content), copied by (content_size).
**	Returns a pointer to the item.
*/
t_list				*ft_lstnew(void const *content, size_t content_size);

/*
**	Applies (*del) to t_list's contents, then frees *(alst) and sets
**	it to NULL.
*/
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

/*
**	Applies (*del) to every t_list in the stack, then frees *(alst) and
**	sets them to NULL.
*/
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

/*
**	Prepends stack (alst) with (new_elem), without creating an item.
*/
void				ft_lstadd(t_list **alst, t_list *new_elem);

/*
**	For every item in (alst), appies (*f).
*/
void				ft_lstiter(t_list *alst, void (*f)(t_list *elem));

/*
**	Creates a new list, of items (alst), to which (*f) has been applied.
*/
t_list				*ft_lstmap(t_list *alst, t_list *(*f)(t_list *elem));

/*
**	Obviously gets next line from (fd),
**	returns -1 on error, 1 on success and 0 on EOF.
*/
int					get_next_line(const int fd, char **line);

/*
**	Same as atoi (str) but returns number in (base).
*/
long long			ft_atoll_base(char *str, int base);

/*
**	Returns count of digits in (nb).
*/
int					ft_count_digits(int nb);

/*
**	Returns count of digits in (nb) with (base).
*/
int					ft_count_digits_base(char *str, int base);

/*
**	Returns (nbr) in (power).
*/
long				ft_power(long nbr, int power);

/*
**	Adds node with (content) and (content_size) to the end of (list).
*/
void				ft_lstaddback(t_list **list,
						void *content, size_t content_size);

/*
**	Converts (n) unsigned long to a string. Returns a pointer to the new string.
*/
char				*ft_ultoa(unsigned long n);

/*
**	Converts (n) long to a string. Returns a pointer to the new string.
*/
char				*ft_lltoa(long long n);

/*
**	Same as ft_lltoa, but works with unsigned long long.
*/
char				*ft_ulltoa(unsigned long long n);

/*
**	Converts (n) long long to a string in selected base.
**	Returns a pointer to the new string.
**	Set value "capital" to 1 to get result with capital
**	charachers (FF), to zero (ff)
**	Set value "format" to 1 to get base specifier
** (0 prefix for octal), (0x for hex)
*/
char				*ft_lltoa_base(long long nbr,
						int base, char capital, char format);

/*
**	Same as atoi (str) but working with long long integers
*/
long long			ft_atoll(char *str);

/*
**	Same as atoi (str) but working with unsigned long long integers
*/
unsigned long long	ft_atoull(const char *str);

/*
**	Same as lltoa_base (str) but working with unsigned long long integers
*/
char				*ft_ulltoa_base(unsigned long long nbr,
								int base, char capital, char format);

/*
**	Returns absolute value of int (num).
*/
int					ft_abs(int num);

/*
**	Returns 1 if nbr is even, zero if not
*/
int					is_even(int num);

/*
**	Swaps value of two integers.
*/
void				ft_swap(int *a, int *b);

/*
**	Same as ft_strjoin, but takes as parameter size of resulting string
**	(for optimisation purposes, instead of two ft_strlen calls).
*/
char				*ft_strljoin(const char *s1, const char *s2, size_t size);

/*
**	Cleans double array of chars (string array).
*/
char				**clean_chr_mtrx(char **str);

/*
**	Same as ft_strlen, but returns length of string before specific char.
*/
size_t				ft_strlen_char(char *str, char breaker);

/*
**	Returns string trimmed by 'breaker' symbol.
**
** 	Used functions:
**	1. malloc
**	2. ft_strlen
**	3. ft_strchr
**	4. ft_memcpy
*/

char				*ft_trim_c(const char *str, char breaker);

/*
**	Takes begin of t_list and function that prints node of the list.
**	It uses fflush() function to generate correct output even if print function
** 	doing buffer management. This function is SLOW. Use only for debug purposes.
*/
void				ft_lstprint(t_list *begin, void (*print_function)(t_list*));

/*
**	lst_p functions family works the same as lst functions,
**	but inside using raw pointers, passed to them, instead of malloc like
**	lst functions do.
*/

t_list				*ft_lstnew_p(void *content, size_t content_size);
void				ft_lstaddback_p(t_list **begin, void *content,
						size_t content_size);
void				ft_lstdel_p(t_list **begin);

int					ft_max(int a, int b);

/*
**	Same usage as standard library printf.
*/

int					ft_printf(const char *format, ...);

#endif
