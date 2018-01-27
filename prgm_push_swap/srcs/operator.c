/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:24:44 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/17 17:59:27 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_map *map)
{
	t_lst	*swap;

	map->operation->next = newmaillon(1);
	map->operation = map->operation->next;
	map->operation->next = NULL;
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
	map->operation->next = NULL;
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

	map->operation->next = newmaillon(5);
	map->operation = map->operation->next;
	map->operation->next = NULL;
	if (map->begin_a == NULL)
		return ;
	if (map->begin_b == NULL)
	{
		map->begin_b = newmaillon(map->begin_a->number);
		map->begin_b->next = NULL;
		map->begin_a = map->begin_a->next;
	}
	else
	{
		next = newmaillon(map->begin_a->number);
		next->next = map->begin_b;
		map->begin_b = next;
		map->begin_a = map->begin_a->next;
	}
}

void	push_a(t_map *map)
{
	t_lst	*next;

	map->operation->next = newmaillon(4);
	map->operation = map->operation->next;
	map->operation->next = NULL;
	if (map->begin_b == NULL)
		return ;
	if (map->begin_a == NULL)
	{
		map->begin_a = newmaillon(map->begin_b->number);
		map->begin_a->next = NULL;
		map->begin_b = map->begin_b->next;
	}
	else
	{
		next = newmaillon(map->begin_b->number);
		next->next = map->begin_a;
		map->begin_a = next;
		map->begin_b = map->begin_b->next;
	}
}

void	rotate_a(t_map *map)
{
	t_lst	*sauv;
	t_lst	*swap;

	map->operation->next = newmaillon(7);
	map->operation = map->operation->next;
	map->operation->next = NULL;
	if (map->begin_a == NULL || map->begin_a->next == NULL)
		return ;
	swap = map->begin_a;
	map->begin_a = map->begin_a->next;
	sauv = map->begin_a;
	while (map->begin_a->next)
		map->begin_a = map->begin_a->next;
	map->begin_a->next = swap;
	map->begin_a = map->begin_a->next;
	map->begin_a->next = NULL;
	map->begin_a = sauv;
}

void	rotate_b(t_map *map)
{
	t_lst	*sauv;
	t_lst	*swap;

	map->operation->next = newmaillon(8);
	map->operation = map->operation->next;
	map->operation->next = NULL;
	if (map->begin_b == NULL || map->begin_b->next == NULL)
		return ;
	swap = map->begin_b;
	map->begin_b = map->begin_b->next;
	sauv = map->begin_b;
	while (map->begin_b->next)
		map->begin_b = map->begin_b->next;
	map->begin_b->next = swap;
	map->begin_b = map->begin_b->next;
	map->begin_b->next = NULL;
	map->begin_b = sauv;
}

void	reverse_a(t_map *map)
{
	t_lst	*sauv;
	t_lst	*next;

	map->operation->next = newmaillon(10);
	map->operation = map->operation->next;
	map->operation->next = NULL;
	if (map->begin_a == NULL || map->begin_a->next == NULL)
		return ;
	sauv = map->begin_a;
	while (map->begin_a->next)
	{
		next = map->begin_a;
		map->begin_a = map->begin_a->next;
	}
	next->next = NULL;
	map->begin_a->next = sauv;
}

void	reverse_b(t_map *map)
{
	t_lst	*sauv;
	t_lst	*next;

	map->operation->next = newmaillon(11);
	map->operation = map->operation->next;
	map->operation->next = NULL;
	if (map->begin_b == NULL || map->begin_b->next == NULL)
		return ;
	sauv = map->begin_b;
	while (map->begin_b->next)
	{
		next = map->begin_b;
		map->begin_b = map->begin_b->next;
	}
	next->next = NULL;
	map->begin_b->next = sauv;
}
