/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paumarc2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:31:47 by paumarc2          #+#    #+#             */
/*   Updated: 2023/06/28 12:59:07 by paumarc2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerpush_swap.h"

//////////////////////////////////////////////////////////////////////
/////////////////FR: Remplis toutes la chaine de 0//////////////////// 
//////////////////EN: Feed all the stacks with 0//////////////////////
//////////////////////////////////////////////////////////////////////
void	ft_bzero(void *s, size_t n)
{
	size_t	a;
	char	*t;

	a = 0;
	t = s;
	while (a < n)
	{
		t[a] = '\0';
		a++;
	}
}

//////////////////////////////////////////////////////////////////////
/////////////////FR: Free tous les elements de la stack/////////////// 
//////////////////EN: Free all the element of the pile////////////////
//////////////////////////////////////////////////////////////////////
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

//////////////////////////////////////////////////////////////////////
//////FR: Free les piles et ecris "error" sur la sortis d'erreur//////
/////EN: Free all the pile and write "error" on the right output//////
//////////////////////////////////////////////////////////////////////
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

/*/////////////////////////////////////////////////////////////////////
//////////////////////FR: Atoi mais en long int/////////////////////// 
///////////////////////EN: Atoi but in long int///////////////////////
//////////////////////////////////////////////////////////////////////
long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}*/

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

//////////////////////////////////////////////////////////////////////
//////////////FR: Retourne la valeur absolute de nb///////////////////
///////////////EN: Returns the absolute value of nb///////////////////
//////////////////////////////////////////////////////////////////////
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
