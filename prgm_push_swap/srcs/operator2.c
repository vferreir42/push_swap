/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 20:28:50 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/30 14:54:27 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_map *map)
{
	t_lst	*swap;

	map->operation->next = newmaillon(1);
	map->operation = map->operation->next;
	if (map->begin_a == NULL || map->begin_a->next == NULL)
		return ;
	swap = map->begin_a;
	map->begin_a = map->begin_a->next;
	swap->next = map->begin_a->next;
	map->begin_a->next = swap;
}

void	swap_b(t_map *map)
{
	t_lst	*swap;

	map->operation->next = newmaillon(2);
	map->operation = map->operation->next;
	if (map->begin_b == NULL || map->begin_b->next == NULL)
		return ;
	swap = map->begin_b;
	map->begin_b = map->begin_b->next;
	swap->next = map->begin_b->next;
	map->begin_b->next = swap;
}

void	push_b(t_map *map)
{
	t_lst	*next;
	t_lst	*tmp;

	map->operation->next = newmaillon(5);
	map->operation = map->operation->next;
	if (map->begin_a == NULL)
		return ;
	if (map->begin_b == NULL)
		map->begin_b = newmaillon(map->begin_a->number);
	else
	{
		next = newmaillon(map->begin_a->number);
		next->next = map->begin_b;
		map->begin_b = next;
	}
	tmp = map->begin_a;
	map->begin_a = map->begin_a->next;
	free(tmp);
}

void	push_a(t_map *map)
{
	t_lst	*tmp;
	t_lst	*next;

	map->operation->next = newmaillon(4);
	map->operation = map->operation->next;
	if (map->begin_b == NULL)
		return ;
	if (map->begin_a == NULL)
		map->begin_a = newmaillon(map->begin_b->number);
	else
	{
		next = newmaillon(map->begin_b->number);
		next->next = map->begin_a;
		map->begin_a = next;
	}
	tmp = map->begin_b;
	map->begin_b = map->begin_b->next;
	free(tmp);
}
