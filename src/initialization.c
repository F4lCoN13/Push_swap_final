/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paumarc2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:21:55 by paumarc2          #+#    #+#             */
/*   Updated: 2023/06/28 12:41:20 by paumarc2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerpush_swap.h"

///////////////////////////////////////////////////////////////////////////////
//////////////////FR: remplis la stack a avec les bonnes valeurs///////////////
/////////////////////EN: feed the pile a with the right number/////////////////
///////////////////////////////////////////////////////////////////////////////
t_stack	*fill_stack_values(t_tab *tab)
{
	t_stack		*stack_a;
	int			i;

	stack_a = NULL;
	i = 0;
	while (i < tab->size)
	{
		if (i == 0)
			stack_a = stack_new((int)tab->t[i]);
		else
			stack_add_bottom(&stack_a, stack_new((int)tab->t[i]));
		i++;
	}
	return (stack_a);
}

////////////////////////////////////////////////////////////////////////////////
///////////////////////FR: Indexer toute les nodes//////////////////////////////
////////////////////////////EN: index all node//////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
