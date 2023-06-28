/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paumarc2 <paumarc2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:07:04 by paumarc2          #+#    #+#             */
/*   Updated: 2023/06/28 15:07:20 by paumarc2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerpush_swap.h"

////////////////////////////////////////////////////////////////////////////////
///FR: Fonction pour obtenir les nombre totaux et verifier la taille maximum////
//////EN: Function to obtain the total numbers and check the maximum size///////
////////////////////////////////////////////////////////////////////////////////
int	ft_new_size(char **argv)
{
	t_sct	sct;

	sct.count = 0;
	sct.i = 0;
	while (argv[sct.i])
	{
		sct.ptr = ft_split(argv[sct.i], ' ');
		sct.k = 0;
		while (sct.ptr[sct.k])
		{
			sct.j = 0;
			sct.j = ft_find_nb(sct.ptr[sct.k]);
			if (sct.j == -1)
				return (-1);
			if (sct.j > 0)
				sct.count += 1;
			sct.k += 1;
		}
		sct.i++;
		free(sct.ptr);
	}
	return (sct.count);
}

////////////////////////////////////////////////////////////////////////////////
//////////////////////FR: Remplissage du tableau////////////////////////////////
/////////////////////////EN: Filling the array//////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void	ft_number(char **argv, t_tab *tab)
{
	int		i;
	int		j;
	int		k;
	char	**ptr;

	i = 0;
	j = 0;
	while (argv[i])
	{
		ptr = ft_split(argv[i], ' ');
		k = 0;
		while (ptr[k])
		{
			tab->t[j] = ft_find_and_return_nb(ptr[k]);
			j++;
			k++;
		}
		free(ptr);
		i++;
	}
}

////////////////////////////////////////////////////////////////////////////////
/////////////FR: Fonction qui verifie le format des nombres/////////////////////
///////////EN: Function that verifies the format of the numbers/////////////////
////////////////////////////////////////////////////////////////////////////////
int	ft_just_nb(char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < 48 || argv[i][j] > 58) && argv[i][j] != 32
				&& argv[i][j] != '-' && argv[i][j] != '+')
				return (-1);
			if (((argv[i][j] == '-' || argv[i][j] == '+')
				&& (argv[i][j + 1] < 48 || argv[i][j + 1] > 58)))
				return (-1);
			if (((argv[i][j] == '-' || argv[i][j] == '+') && (argv[i][j -1])
				&& (argv[i][j - 1] != ' ')))
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

////////////////////////////////////////////////////////////////////////////////
/////FR: Commande les fonctions pour remplir le tableau avec les bon nombres////
//////////EN: Command the functions to fill the array with good numbers/////////
////////////////////////////////////////////////////////////////////////////////
int	ft_limit(char **argv, t_tab *tab)
{
	tab->size = ft_new_size(argv);
	tab->t = malloc(sizeof(long int) * (tab->size));
	if (tab->t == NULL)
		return (-1);
	ft_number(argv, tab);
	if (ft_check_double(tab, tab->size) == -1)
		return (-1);
	return (1);
}

////////////////////////////////////////////////////////////////////////////////
//////////////FR: Commande la les tests et retour d'erreur/////////////////////
//////////EN: Command the functions to fill the array with good numbers/////////
////////////////////////////////////////////////////////////////////////////////
void	ft_find_error_and_init_list(char **argv, t_tab *tab)
{
	if (((ft_just_nb(argv)) == -1) || (ft_limit(argv, tab) == -1))
	{
		tab->flag = -1;
		if (tab->t)
			free(tab->t);
		return ;
	}
	tab->flag = 1;
	return ;
}
