/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:24:44 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/29 19:32:33 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_b(t_map *map)
{
	t_lst	*next;
	t_lst	*tmp;

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
	t_lst	*next;
	t_lst	*tmp;

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

void	rotate_a(t_map *map)
{
	t_lst	*sauv;
	t_lst	*swap;

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

void	rotate_ss(t_map *map)
{
	rotate_a(map);
	rotate_b(map);
}
