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
			write(1, "sa\n", 3);
		if (map.beginop->number == 2)
			write(1, "sb\n", 3);
		if (map.beginop->number == 4)
			write(1, "pa\n", 3);
		if (map.beginop->number == 5)
			write(1, "pb\n", 3);
		if (map.beginop->number == 7)
			write(1, "ra\n", 3);
		if (map.beginop->number == 8)
			write(1, "rb\n", 3);
		if (map.beginop->number == 10)
			write(1, "rra\n", 4);
		if (map.beginop->number == 11)
			write(1, "rrb\n", 4);
		map.beginop = map.beginop->next;
	}
}
