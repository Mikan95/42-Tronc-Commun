/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:27:59 by ameechan          #+#    #+#             */
/*   Updated: 2024/04/30 14:33:15 by ameechan         ###   ########.fr       */
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
void		ft_lstadd_back(t_stack **lst, long int res);
int			ft_lstsize(t_stack *lst);
void		init_stack_a(t_stack **stack_a, char **argv);
int			ft_error_check(char **argv);
int			ft_check_syntax(char *str);
int			ft_check_dupli(char **argv);
void		ft_freelist(t_stack *stack_a);
int			is_sorted(t_stack *lst);
void		swap(t_stack **lst);
void		push(t_stack **src, t_stack **dest);
void		rotate(t_stack **lst);
void		reverse_rotate(t_stack **lst);
void		rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void		rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void		rr(t_stack **a, t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		sort_three(t_stack **lst);
t_stack		*find_min(t_stack *lst);
t_stack		*find_max(t_stack *lst);
void		min_to_top(t_stack **a);
void		sort_stacks(t_stack **a, t_stack **b);
void		set_index(t_stack *lst);
void		init_nodes_a(t_stack *a, t_stack *b);
void		init_nodes_b(t_stack *a, t_stack *b);
void		set_target_a(t_stack *a, t_stack *b);
void		set_target_b(t_stack *a, t_stack *b);
void		prep_for_push(t_stack **lst, t_stack *top_node, bool is_a);
void		push_a_to_b(t_stack **a, t_stack **b);
void		push_b_to_a(t_stack **a, t_stack **b);
void		find_cheapest(t_stack *a, t_stack *b);
void		set_cheapest(t_stack *lst);
t_stack		*get_cheapest(t_stack *lst);
void		send_cheapest_to_top(t_stack **lst, t_stack *top_node, bool is_a);
void		pa(t_stack **src, t_stack **dest);
void		pb(t_stack **src, t_stack **dest);
void		sa(t_stack **lst);
void		ra(t_stack **lst);
void		rb(t_stack **lst);
void		rra(t_stack **lst);
void		rrb(t_stack **lst);

//TEST FUCNTIONS
void		test_print_elements_lst(t_stack *a, t_stack *b);
void		test_swap(t_stack **a, t_stack **b);
void		test_push(t_stack **a, t_stack **b);
void		test_rotate(t_stack **a, t_stack **b);
void		test_reverse_rotate(t_stack **a, t_stack **b);
void		test_free(t_stack **lst);
#endif
