/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paumarc2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:32:43 by paumarc2          #+#    #+#             */
/*   Updated: 2023/06/28 15:02:35 by paumarc2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerpush_swap.h"

///////////////////////////////////////////////////////////////////////////////
////////////////FR: Verifie que les nombres sont bien trier////////////////////
///////////////////EN: Tchec if all the number are sorted//////////////////////
///////////////////////////////////////////////////////////////////////////////
int	check_if_is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

///////////////////////////////////////////////////////////////////////////////
///////////FR: Choisis la repartitions par rapport au nombre trier/////////////
//////////EN: Choose a method for sorting depending on the numbers/////////////
///////////////////////////////////////////////////////////////////////////////
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !check_if_is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !check_if_is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

///////////////////////////////////////////////////////////////////////////////
//////////FR: MAIN pour diriger toutes les fonctions de PUSH SWAP//////////////
///////////////EN: MAIN for lauch all the PUSH SWAP function///////////////////
///////////////////////////////////////////////////////////////////////////////
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_tab	tab;
	int		stack_size;

	tab.t = NULL;
	if (ac == 1)
		return (0);
	if (!(ft_main_error(av, &tab)))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(&tab);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
