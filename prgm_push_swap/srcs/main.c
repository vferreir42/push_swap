/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:09:56 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/30 15:01:08 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reduct_operation(t_map *map)
{
	t_lst	*next;
	t_lst	*tmp;

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
			{
				tmp = next->next;
				next->next = next->next->next->next;
				free(tmp->next);
				free(tmp);
			}
			next = map->beginop;
		}
		next = next->next;
	}
}

void	put_argv_in_list(t_map *map, char **argv, int i)
{
	t_lst	*next;

	parcing_argv(argv);
	parcing_size_int(ft_atoi(argv[i]));
	next = newmaillon(ft_atoi(argv[i]));
	next->gris = 0;
	map->begin_a = next;
	while (argv[++i])
	{
		parcing_size_int(ft_atoi(argv[i]));
		next->next = newmaillon(ft_atoi(argv[i]));
		next = next->next;
		next->gris = 0;
	}
}

int		main(int argc, char **argv)
{
	char	**new;
	t_map	map;

	new = NULL;
	if (argc == 1)
		exit(0);
	if (ft_strchr(argv[1], ' ') != NULL && argv[2] == NULL)
	{
		new = ft_strsplit(argv[1], ' ');
		put_argv_in_list(&map, new, 0);
	}
	else
		put_argv_in_list(&map, argv, 1);
	parcing_not_same_number(map);
	if (verifordre(map) == 1)
		exit(0);
	map.operation = newmaillon(0);
	map.beginop = map.operation;
	recursive_a(&map, sizepile(map.begin_a));
	reduct_operation(&map);
	display_operation(map);
	free_list(&map);
	if (new)
		del_tab(&new);
	return (0);
}
