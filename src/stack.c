/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paumarc2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:34:23 by paumarc2          #+#    #+#             */
/*   Updated: 2023/06/27 11:05:42 by paumarc2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerpush_swap.h"

///////////////////////////////////////////////////////////////////////////////
////////////////FR: retourne le dernier element de la list/////////////////////
/////////////////EN: returns the last element of the stack/////////////////////
///////////////////////////////////////////////////////////////////////////////
t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

///////////////////////////////////////////////////////////////////////////////
//////////////////////FR: retourne l'avant dernier element/////////////////////
////////////////////EN: returns the element before the last////////////////////
///////////////////////////////////////////////////////////////////////////////
t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////FR: cree une nouvelle pile/////////////////////////////
///////////////////////////EN: creat a new pile////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////FR: cree une nouvelle node/////////////////////////////
////////////////////////////EN: creat a new node////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_bottom(*stack);
	tail->next = new;
}

////////////////////////////////////////////////////////////////////////////////
/////////////FR: retourne le nombre total de node dans la stack/////////////////
////////////EN: returns the total number of the node in the stack///////////////
////////////////////////////////////////////////////////////////////////////////
int	get_stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
