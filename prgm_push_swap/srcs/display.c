/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:06:19 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/17 17:10:27 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_operation(t_map map)
{
	while (map.beginop)
	{
		if (map.beginop->number == 1)
			printf("sa\n");
		if (map.beginop->number == 2)
			printf("sb\n");
		if (map.beginop->number == 4)
			printf("pa\n");
		if (map.beginop->number == 5)
			printf("pb\n");
		if (map.beginop->number == 7)
			printf("ra\n");
		if (map.beginop->number == 8)
			printf("rb\n");
		if (map.beginop->number == 10)
			printf("rra\n");
		if (map.beginop->number == 11)
			printf("rrb\n");
		map.beginop = map.beginop->next;
	}
}
