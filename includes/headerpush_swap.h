/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headerpush_swap.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paumarc2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:20:52 by paumarc2          #+#    #+#             */
/*   Updated: 2023/06/28 15:00:01 by paumarc2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERPUSH_SWAP_H
# define HEADERPUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

//=========================================================================
typedef struct s_tab
{
	long int	*t;
	int			flag;
	int			ret;
	int			pivot;
	int			size;
	int			save_action;
}	t_tab;

typedef struct s_sct
{
	int		i;
	int		j;
	int		k;
	int		count;
	char	**ptr;
}	t_sct;
//=========================================================================
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;
//=========================================================================
t_stack		*fill_stack_values(t_tab *tab);
void		assign_index(t_stack *stack_a, int ac);
int			check_if_is_sorted(t_stack *stack);
void		tiny_sort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);
//=========================================================================
int			get_lowest_index_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);
//=========================================================================
void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
//=========================================================================
void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
//=========================================================================
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
//=========================================================================
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);
//=========================================================================
void		free_stack(t_stack **stack);
void		ft_putstr(char *str);
int			nb_abs(int nb);
//=========================================================================
void		exit_error(t_stack **stack_a, t_stack **stack_b);
//=========================================================================
int			is_correct_input(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);
//=========================================================================
int			ft_main_error(char **argv, t_tab *tab);
void		ft_find_error_and_init_list(char **argv, t_tab *tab);
int			ft_check_double(t_tab *tab, int size);
int			ft_find_nb(char *nptr);
long int	ft_find_and_return_nb(char *nptr);
char		**ft_split(char const *s, char c);
void		ft_bzero(void *s, size_t n);
//=========================================================================
#endif
