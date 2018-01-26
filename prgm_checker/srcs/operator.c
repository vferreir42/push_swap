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
	if (map->beginA == NULL || map->beginA->next == NULL)
		return ;
	swap = map->beginA;
	map->beginA = map->beginA->next;
	swap->next = map->beginA->next;
	map->beginA->next = swap;
}

void 	swap_b(t_map *map)
{
	t_lst *swap;

	map->counter++;
	if (map->beginB == NULL || map->beginB->next == NULL)
		return ;
	swap = map->beginB;
	map->beginB = map->beginB->next;
	swap->next = map->beginB->next;
	map->beginB->next = swap;
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
	if (map->beginA == NULL)
		return ;
	if (map->beginB == NULL)
	{
		map->beginB = newmaillon(map->beginA->number);
		map->beginB->next = NULL;
		map->beginA = map->beginA->next;
	}
	else
	{
		next = newmaillon(map->beginA->number);
		next->next = map->beginB;
		map->beginB = next;
		map->beginA = map->beginA->next;
	}
}

void push_a (t_map *map)
{
	t_lst *next;

	map->counter++;
	if (map->beginB == NULL)
		return ;
	if (map->beginA == NULL)
	{
		map->beginA = newmaillon(map->beginB->number);
		map->beginA->next = NULL;
		map->beginB = map->beginB->next;
	}
	else
	{
		next = newmaillon(map->beginB->number);
		next->next = map->beginA;
		map->beginA = next;
		map->beginB = map->beginB->next;
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
	if (map->beginA == NULL || map->beginA->next == NULL)
		return ;
	swap = map->beginA;
	map->beginA = map->beginA->next;
	sauv = map->beginA;
	while (map->beginA->next)
		map->beginA = map->beginA->next;
	map->beginA->next = swap;
	map->beginA = map->beginA->next;
	map->beginA->next = NULL;

	map->beginA = sauv;
}

void rotate_b(t_map *map)
{
	t_lst *sauv;
	t_lst *swap;

	map->counter++;
	if (map->beginB == NULL || map->beginB->next == NULL)
		return ;
	swap = map->beginB;
	map->beginB = map->beginB->next;
	sauv = map->beginB;
	while (map->beginB->next)
		map->beginB = map->beginB->next;
	map->beginB->next = swap;
	map->beginB = map->beginB->next;
	map->beginB->next = NULL;

	map->beginB = sauv;
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

	if (map->beginA == NULL || map->beginA->next == NULL)
		return ;

	sauv = map->beginA;
	while (map->beginA->next)
	{
		next = map->beginA;
		map->beginA = map->beginA->next;
	}
	next->next = NULL;
	map->beginA->next = sauv;
}

void reverse_b(t_map *map)
{
	t_lst *sauv;
	t_lst *next;

	map->counter++;

	if (map->beginB == NULL || map->beginB->next == NULL)
		return ;

	sauv = map->beginB;
	while (map->beginB->next)
	{
		next = map->beginB;
		map->beginB = map->beginB->next;
	}
	next->next = NULL;
	map->beginB->next = sauv;
}

void reverse_ss(t_map *map)
{
	reverse_a(map);
	reverse_b(map);
}
