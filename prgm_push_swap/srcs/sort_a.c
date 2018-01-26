/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:13:39 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/17 17:47:34 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_in_tab(t_map *map, t_lst *begin, long int *tab)
{
	int			i;

	i = 0;
	while (begin && i < 3)
	{
		tab[i] = begin->number;
		begin = begin->next;
		i++;
	}
	tab[i] = 3000000000;
}

static int	minimum_op_a(t_map *map, long int *tab)
{
	if (tab[0] <= tab[1] && tab[0] <= tab[2])
		if (tab[1] <= tab[2])
			return (0);
		else
		{
			reverse_a(map);
			swap_a(map);
		}
	else if ((tab[0] >= tab[1] && tab[0] <= tab[2])
			|| (tab[0] >= tab[2] && tab[0] <= tab[1]))
		if (tab[1] < tab[2])
			swap_a(map);
		else
			reverse_a(map);
	else
	{
		if (tab[1] <= tab[2])
			rotate_a(map);
		else
		{
			rotate_a(map);
			swap_a(map);
		}
	}
	return (0);
}

static int	suite_sort_pile_a_1(t_map *map, long int *tab)
{
	if (tab[0] == tab[1] && tab[0] == tab[2])
		return (0);
	else if (tab[0] == tab[2])
		swap_a(map);
	else if (tab[1] > tab[2])
	{
		swap_a(map);
		rotate_a(map);
		swap_a(map);
		reverse_a(map);
		swap_a(map);
	}
	else
	{
		swap_a(map);
		rotate_a(map);
		swap_a(map);
		reverse_a(map);
	}
	return (0);
}

static void	suite_sort_pile_a_2(t_map *map, long int *tab)
{
	if (tab[1] > tab[2])
	{
		rotate_a(map);
		swap_a(map);
		reverse_a(map);
		swap_a(map);
	}
	else
		swap_a(map);
}

int			sort_pile_a(t_map *map, t_lst *begin, int size)
{
	long int	tab[4];

	put_in_tab(map, begin, tab);
	if (tab[1] == 3000000000 || tab[2] == 3000000000)
	{
		if (tab[1] != 3000000000 && tab[0] > tab[1])
			swap_a(map);
		return (0);
	}
	if (sizepile(begin) <= 3)
		return (minimum_op_a(map, tab));
	if (tab[0] >= tab[1] && tab[0] >= tab[2])
		return (suite_sort_pile_a_1(map, tab));
	else if (tab[0] >= tab[1] || tab[0] >= tab[2])
		suite_sort_pile_a_2(map, tab);
	else if (tab[1] > tab[2])
	{
		rotate_a(map);
		swap_a(map);
		reverse_a(map);
	}
	return (0);
}
