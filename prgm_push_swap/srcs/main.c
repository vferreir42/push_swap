/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:09:56 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/27 19:25:43 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reduct_operation(t_map *map)
{
	t_lst	*next;

	next = map->beginop;
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
}

void	put_argv_in_list(t_map *map, char **argv, int i)
{
	t_lst	*next;

	parcing_size_int(ft_atoi(argv[i]));
	next = newmaillon(ft_atoi(argv[i]));
	next->gris = 0;
	map->begin_a = next;
	while (argv[++i])
	{
		next->next = newmaillon(ft_atoi(argv[i]));
		next = next->next;
		next->gris = 0;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	t_map	map;

	if (argc == 1)
		exit(0);
	i = 1;
	if (ft_strchr(argv[1], ' ') != NULL && argv[2] == NULL)
	{
		i = 0;
		argv = ft_strsplit(argv[1], ' ');
	}
	parcing_argv(argv);
	put_argv_in_list(&map, argv, i);
	parcing_not_same_number(map);
	if (verifordre(map) == 1)
		exit(0);
	map.operation = newmaillon(0);
	map.beginop = map.operation;
	recursive_a(&map, sizepile(map.begin_a));
	reduct_operation(&map);
	display_operation(map);

	/*while (map.begin_a)
	{
		printf("%d\n", map.begin_a->number);
		map.begin_a = map.begin_a->next;
	}*/
	return (0);
}
