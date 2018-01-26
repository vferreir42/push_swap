/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:25:24 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/17 13:25:25 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void put_in_tab(t_map *map, t_lst *begin, long int *tab)
{
	int i;

	i = 0;
	while(begin && i < 3)
	{
		tab[i] = begin->number;
		begin = begin->next;
		i++;
	}
	tab[i] = 3000000000;
}

int sort_pile_b(t_map *map, t_lst *begin, int size)
{
	long int tab[4];
	int i;

	put_in_tab(map, begin, tab);
	if (tab[1] == 3000000000)
		return (0);
	if (tab[2] == 3000000000)
	{
		if (tab[0] < tab[1])
			swap_b(map);
		return (0);
	}
	if (tab[0] <= tab[1] && tab[0] <= tab[2])
	{
		if (tab[0] == tab[1] && tab [0] == tab[2])
			return (0);
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
	else if (tab[0] <= tab[1] || tab[0] <= tab[2])
	{
		if (tab[1] == tab[2])
			return (0);
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
	else if (tab[1] < tab[2])
	{
		rotate_b(map);
		swap_b(map);
		reverse_b(map);
	}
	return (0);
}
