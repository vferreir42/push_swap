/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:34:25 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/11 18:34:26 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_lst	*newmaillon(int receipt)
{
	t_lst	*ptr;

	if (!(ptr = malloc(sizeof(t_lst))))
		return (NULL);
	ptr->number = receipt;
	ptr->next = NULL;
	return (ptr);
}

void verification(t_map map)
{
	int number;
	while (map.begin_a)
	{
		number = map.begin_a->number;
		map.begin_a = map.begin_a->next;
		if (map.begin_a && number > map.begin_a->number)
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	if (map.begin_b)
	{
		write(1, "KO\n", 3);
		return ;
	}
	write (1, "OK\n", 3);
}

void read_operation(t_map *map)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "sa") == 0)
			swap_a(map);
		else if (ft_strcmp(line, "sb") == 0)
			swap_b(map);
		else if (ft_strcmp(line, "ss") == 0)
			swap_ss(map);
		else if (ft_strcmp(line, "pa") == 0)
			push_a(map);
		else if (ft_strcmp(line, "pb") == 0)
			push_b(map);
		else if (ft_strcmp(line, "ra") == 0)
			rotate_a(map);
		else if (ft_strcmp(line, "rb") == 0)
			rotate_b(map);
		else if (ft_strcmp(line, "rr") == 0)
			rotate_ss(map);
		else if (ft_strcmp(line, "rra") == 0)
			reverse_a(map);
		else if (ft_strcmp(line, "rrb") == 0)
			reverse_b(map);
		else if (ft_strcmp(line, "rrr") == 0)
			reverse_ss(map);
		else
		{
			printf("Error\n");
			exit (0);
		}
	}
}

void put_argv_in_list(t_map *map, char **argv, int i)
{
	t_lst *next;

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

int main(int argc, char **argv)
{
	int i;
	t_lst *next;
	t_map map;

	if (argc == 1)
		exit (0);
	i = 1;
	if (ft_strchr(argv[1], ' ') != NULL && argv[2] == NULL)
	{
		i = 0;
		argv = ft_strsplit(argv[1], ' ');
	}
	parcing_argv(argv);
	put_argv_in_list(&map, argv, i);
	parcing_not_same_number(map);
	read_operation(&map);
	verification(map);
}
