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
	if (map->beginA == NULL || map->beginA->next == NULL)
		return ;
	swap = map->beginA;
	map->beginA = map->beginA->next;
	swap->next = map->beginA->next;
	map->beginA->next = swap;
}

void	swap_b(t_map *map)
{
	t_lst	*swap;

	map->operation->next = newmaillon(2);
	map->operation = map->operation->next;
	map->operation->next = NULL;
	if (map->beginB == NULL || map->beginB->next == NULL)
		return ;
	swap = map->beginB;
	map->beginB = map->beginB->next;
	swap->next = map->beginB->next;
	map->beginB->next = swap;
}

void	push_b(t_map *map)
{
	t_lst	*next;

	map->operation->next = newmaillon(5);
	map->operation = map->operation->next;
	map->operation->next = NULL;
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

void	push_a(t_map *map)
{
	t_lst	*next;

	map->operation->next = newmaillon(4);
	map->operation = map->operation->next;
	map->operation->next = NULL;
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

void	rotate_a(t_map *map)
{
	t_lst	*sauv;
	t_lst	*swap;

	map->operation->next = newmaillon(7);
	map->operation = map->operation->next;
	map->operation->next = NULL;
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

void	rotate_b(t_map *map)
{
	t_lst	*sauv;
	t_lst	*swap;

	map->operation->next = newmaillon(8);
	map->operation = map->operation->next;
	map->operation->next = NULL;
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

void	reverse_a(t_map *map)
{
	t_lst	*sauv;
	t_lst	*next;

	map->operation->next = newmaillon(10);
	map->operation = map->operation->next;
	map->operation->next = NULL;
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

void	reverse_b(t_map *map)
{
	t_lst	*sauv;
	t_lst	*next;

	map->operation->next = newmaillon(11);
	map->operation = map->operation->next;
	map->operation->next = NULL;
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
