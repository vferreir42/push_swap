/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:44:51 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/29 19:33:25 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a(t_map *map)
{
	t_lst	*swap;

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

	if (map->begin_b == NULL || map->begin_b->next == NULL)
		return ;
	swap = map->begin_b;
	map->begin_b = map->begin_b->next;
	swap->next = map->begin_b->next;
	map->begin_b->next = swap;
}

void	swap_ss(t_map *map)
{
	swap_a(map);
	swap_b(map);
}
