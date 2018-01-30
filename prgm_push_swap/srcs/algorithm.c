/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 13:06:08 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/17 14:07:55 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	recursive_a(t_map *map, int size)
{
	int sauvsize;
	int countpush;
	int countrotate;

	sauvsize = size;
	if (size <= 3)
		return (sort_pile_a(map, map->begin_a));
	map->med = mediane(map->begin_a, size / 2);
	countpush = 0;
	countrotate = 0;
	while (sauvsize-- > 0)
		if (map->begin_a->number <= map->med && ++countpush)
			push_b(map);
		else if (++countrotate)
			rotate_a(map);
	if (verifordre(*map) == 1)
		while (countrotate-- > 0)
			reverse_a(map);
	recursive_a(map, size - countpush);
	recursive_b(map, countpush);
	while (countpush-- > 0)
		push_a(map);
	return (0);
}

int	recursive_b(t_map *map, int size)
{
	int sauvsize;
	int countpush;
	int countrotate;

	sauvsize = size;
	if (size <= 3)
		return (sort_pile_b(map, map->begin_b));
	map->med = mediane(map->begin_b, size / 2);
	countpush = 0;
	countrotate = 0;
	while (sauvsize-- > 0)
		if (map->begin_b->number > map->med && ++countpush)
			push_a(map);
		else if (++countrotate)
			rotate_b(map);
	while (countrotate-- > 0)
		reverse_b(map);
	recursive_b(map, size - countpush);
	recursive_a(map, countpush);
	while (countpush-- > 0)
		push_b(map);
	return (0);
}
