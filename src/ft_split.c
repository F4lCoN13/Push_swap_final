/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paumarc2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:53:04 by paumarc2          #+#    #+#             */
/*   Updated: 2023/06/28 12:09:13 by paumarc2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerpush_swap.h"

typedef struct s_ct
{
	int		i;
	int		j;
	int		cnt;
	int		n;
	int		k;
}	t_ct;

static int	new_tab(char const *s, char c)
{
	t_ct	ct;

	ct.i = 0;
	ct.j = 0;
	while (s[ct.i])
	{
		if (s[ct.i] != c && (s[ct.i + 1] == c || s[ct.i + 1] == '\0'))
			ct.j++;
		ct.i++;
	}
	return (ct.j);
}

static void	ft_feed_all(char **ptr, int total, char	const *s, char c)
{
	t_ct	ct;

	ct.i = 0;
	ct.j = 0;
	while (ct.i < total)
	{
		ct.cnt = 0;
		ct.k = 0;
		while (s[ct.j] == c)
			ct.j++;
		ct.n = ct.j;
		while (s[ct.j] != c && s[ct.j] != 0)
		{
			ct.j++;
			ct.cnt++;
		}
		ptr[ct.i] = malloc(sizeof(char) * (ct.cnt + 1));
		if (!ptr[ct.i])
			return ;
		while (ct.k < ct.cnt)
			ptr[ct.i][ct.k++] = s[ct.n++];
		ptr[ct.i][ct.cnt] = '\0';
		ct.i++;
	}
}

static void	ft_free(char **ptr, int nb_tab)
{
	t_ct	ct;

	ct.i = 0;
	while (ct.i <= nb_tab)
		free(ptr[ct.i++]);
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	t_ct	ct;
	char	**ptr;

	if (!s)
		return (NULL);
	ct.i = new_tab(s, c);
	ptr = malloc(sizeof(char *) * (ct.i + 1));
	ft_bzero(ptr, ct.i);
	if (ptr == NULL)
		return (NULL);
	ptr[ct.i] = NULL;
	ft_feed_all(ptr, ct.i, s, c);
	ct.j = 0;
	while (ct.j < ct.i)
	{
		if (ptr[ct.j] == NULL)
		{
			ft_free(ptr, ct.i);
			return (NULL);
		}
		ct.j++;
	}
	return (ptr);
}
