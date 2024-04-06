/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:27:59 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/06 15:54:09 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	long int		value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}					t_stack;

int			is_space(char c);
int			is_digit(char c);
long int	ft_atol(char *str);
int			ft_printf(const char *str, ...);
int			ft_conversion(const char *str, va_list ap);
int			ft_char(char c);
int			ft_str(char *str);
int			ft_putptr(unsigned long ptr, char *hex_chars);
int			ft_putint(int nbr, char *dec_chars);
int			ft_putnbr_hex(unsigned int nbr, char *hex_chars);
int			ft_putnbr_dec(unsigned int nbr, char *dec_chars);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
void		*ft_calloc(size_t count, size_t size);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
int			ft_lstsize(t_stack *lst);
void		init_stack_a(t_stack **stack_a, char **argv);
#endif
