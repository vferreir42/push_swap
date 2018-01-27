/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:24:44 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/11 15:24:45 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void 	swap_a(t_map *map)
{
	t_lst *swap;

	map->counter++;
	if (map->begin_a == NULL || map->begin_a->next == NULL)
		return ;
	swap = map->begin_a;
	map->begin_a = map->begin_a->next;
	swap->next = map->begin_a->next;
	map->begin_a->next = swap;
}

void 	swap_b(t_map *map)
{
	t_lst *swap;

	map->counter++;
	if (map->begin_b == NULL || map->begin_b->next == NULL)
		return ;
	swap = map->begin_b;
	map->begin_b = map->begin_b->next;
	swap->next = map->begin_b->next;
	map->begin_b->next = swap;
}

void 	swap_ss(t_map *map)
{
	swap_a(map);
	swap_b(map);
}

void push_b (t_map *map)
{
	t_lst *next;

	map->counter++;
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

void push_a (t_map *map)
{
	t_lst *next;

	map->counter++;
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

void push_ss(t_map *map)
{
	push_a(map);
	push_b(map);
}

void rotate_a(t_map *map)
{
	t_lst *sauv;
	t_lst *swap;

	map->counter++;
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

void rotate_b(t_map *map)
{
	t_lst *sauv;
	t_lst *swap;

	map->counter++;
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

void rotate_ss(t_map *map)
{
	rotate_a(map);
	rotate_b(map);
}


void reverse_a(t_map *map)
{
	t_lst *sauv;
	t_lst *next;

	map->counter++;

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

void reverse_b(t_map *map)
{
	t_lst *sauv;
	t_lst *next;

	map->counter++;

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

void reverse_ss(t_map *map)
{
	reverse_a(map);
	reverse_b(map);
}
