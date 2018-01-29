/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:42:56 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/29 19:32:56 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_a(t_map *map)
{
	t_lst	*sauv;
	t_lst	*next;

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

void	reverse_ss(t_map *map)
{
	reverse_a(map);
	reverse_b(map);
}
