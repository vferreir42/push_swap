/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:25:24 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/27 19:30:38 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_in_tab(t_lst *begin, long int *tab)
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

static void	suite_sort_pile_b_1(t_map *map, long int *tab)
{
	if (tab[0] == tab[1] && tab[0] == tab[2])
		return ;
	else if (tab[0] == tab[2])
		swap_b(map);
	else if (tab[1] < tab[2])
	{
		swap_b(map);
		rotate_b(map);
		swap_b(map);
		reverse_b(map);
		swap_b(map);
	}
	else
	{
		swap_b(map);
		rotate_b(map);
		swap_b(map);
		reverse_b(map);
	}
}

static void	suite_sort_pile_b_2(t_map *map, long int *tab)
{
	if (tab[1] == tab[2])
		return ;
	else if (tab[1] < tab[2])
	{
		rotate_b(map);
		swap_b(map);
		reverse_b(map);
		swap_b(map);
	}
	else
		swap_b(map);
}

int			sort_pile_b(t_map *map, t_lst *begin)
{
	long int	tab[4];

	put_in_tab(begin, tab);
	if (tab[1] == 3000000000)
		return (0);
	if (tab[2] == 3000000000)
	{
		if (tab[0] < tab[1])
			swap_b(map);
		return (0);
	}
	if (tab[0] <= tab[1] && tab[0] <= tab[2])
		suite_sort_pile_b_1(map, tab);
	else if (tab[0] <= tab[1] || tab[0] <= tab[2])
		suite_sort_pile_b_2(map, tab);
	else if (tab[1] < tab[2])
	{
		rotate_b(map);
		swap_b(map);
		reverse_b(map);
	}
	return (0);
}
