/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paumarc2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:34:42 by paumarc2          #+#    #+#             */
/*   Updated: 2023/06/27 09:34:45 by paumarc2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerpush_swap.h"

//////////////////////////////////////////////////////////////////
///////////////FR: Trouver le plus grand nombre///////////////////
/////////////////EN: Find the greatest number/////////////////////
//////////////////////////////////////////////////////////////////
static int	find_highest_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

//////////////////////////////////////////////////////////////////
//FR: Trouve le plus grand nombre et le met a la fin et sa si besoin
//EN: Find the largest number and put it at the end and its if necessary
//////////////////////////////////////////////////////////////////
void	tiny_sort(t_stack **stack)
{
	int		highest;

	if (check_if_is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
