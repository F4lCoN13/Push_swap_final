/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paumarc2 <paumarc2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:25:58 by paumarc2          #+#    #+#             */
/*   Updated: 2023/06/28 15:07:58 by paumarc2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerpush_swap.h"

////////////////////////////////////////////////////////////////////////////////
////////////FR: Fonction qui sert a compter la taille des nombres///////////////
///////////////EN: Functions that counts the size of numbers////////////////////
////////////////////////////////////////////////////////////////////////////////
int	ft_find_nb(char *nptr)
{
	unsigned long	i;
	int				n;

	i = 0;
	n = 0;
	if ((nptr[i] == '+' || nptr[i] == '-')
		&& (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
		i++;
	while (nptr[i] == '0' && nptr[i + 1] == '0')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		n++;
		if (n == 12)
			return (-1);
		i++;
	}
	return (n);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////FR: Atoi modifie////////////////////////////////////
////////////////////////////EN: Atoi modifies///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
long int	ft_find_and_return_nb(char *nptr)
{
	int			i;
	int			neg;
	long int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	if ((nptr[i] == '+' || nptr[i] == '-')
		&& (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * neg);
}

////////////////////////////////////////////////////////////////////////////////
/////////FR: Regarder si les nommbres sont bien des int sans doublon////////////
///////EN: Check if the numbers are indeed integers without duplicates//////////
////////////////////////////////////////////////////////////////////////////////
int	ft_check_double(t_tab *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if ((tab->t[i] > INT_MAX) || (tab->t[i] < INT_MIN))
			return (-1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j != size)
		{
			if (tab->t[i] == tab->t[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_main_error(char **argv, t_tab *tab)
{
	ft_find_error_and_init_list(++argv, tab);
	if (tab->flag == -1)
		return (0);
	if (tab->size == 1)
		return (-1);
	return (1);
}
