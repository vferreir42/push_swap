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

void display_operation(t_map map)
{

	map.counter = -1;
	while(map.beginop)
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
		map.counter++;
	}

	printf("\033[1mNumber of operation %d\n", map.counter);

	if (verifordre(map) == 0)
		printf("\n\033[31mWRONG\n");
	else
		printf("\n\033[32mRIGHT\n");
	printf("\033[0m\n");
	//display(map, sizepile(map.beginA));

}


void 	display(t_map map, int size)
{
	char *line;

	//	printf("\033[H\033[2J");
	printf ("\033[36m================%5d     ================\033[0m\n", size);
	while (map.beginA || map.beginB)
	{
		if (map.beginA)
		{
			printf("PILE A : \033[36m%10d\033[0m ||", map.beginA->number);
			map.beginA = map.beginA->next;
		}
		else
			printf("                    ||");
		if (map.beginB)
		{
			printf(" PILE B : \033[36m%10d\033[0m\n", map.beginB->number);
			map.beginB = map.beginB->next;
		}
		else
			printf("\n");
	}
}
