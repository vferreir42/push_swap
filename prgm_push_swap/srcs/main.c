/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:09:56 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/17 17:12:31 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*newmaillon(int receipt)
{
	t_lst	*ptr;

	if (!(ptr = malloc(sizeof(t_lst))))
		return (NULL);
	ptr->number = receipt;
	ptr->next = NULL;
	return (ptr);
}

int		verifordre(t_map map)
{
	int		number;

	while (map.beginA)
	{
		number = map.beginA->number;
		map.beginA = map.beginA->next;
		if (map.beginA && number > map.beginA->number)
			return (0);
	}
	return (1);
}

int		sizepile(t_lst *begin)
{
	int		i;

	i = 0;
	while (begin)
	{
		begin = begin->next;
		i++;
	}
	return (i);
}

void	reduct_operation(t_map *map)
{
	int		i;
	t_lst	*next;

	i = 0;
	next = map->beginop;
	while (i == 0)
	{
		while (next)
		{
			if (next->next && next->next->next &&
					((next->next->number == 7 && next->next->next->number == 10)
					 || (next->next->number == 10 && next->next->next->number == 7)
					 || (next->next->number == 8 && next->next->next->number == 11)
					 || (next->next->number == 11 && next->next->next->number == 8)
					 || (next->next->number == 4 && next->next->next->number == 5)
					 || (next->next->number == 5 && next->next->next->number == 4)))
			{
				if (next->next->next->next)
					next->next = next->next->next->next;
				next = map->beginop;
			}
			next = next->next;
		}
		break ;
	}
}

int		main(int argc, char const **argv)
{
	int		i;
	t_lst	*next;
	t_map	map;

	if (argc == 1)
		return (0);
	i = 1;
	map.beginA = newmaillon(ft_atoi(argv[1]));
	next = map.beginA;
	i = 1;
	while (argv[++i])
	{
		next->next = newmaillon(ft_atoi(argv[i]));
		next = next->next;
	}
	map.operation = newmaillon(0);
	map.beginop = map.operation;
	recursive_a(&map, sizepile(map.beginA));
	reduct_operation(&map);
	display_operation(map);
	return (0);
}
