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
	while (map.beginA)
	{
		number = map.beginA->number;
		map.beginA = map.beginA->next;
		if (map.beginA && number > map.beginA->number)
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	if (map.beginB)
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
		if (ft_strcmp(line, "sb") == 0)
			swap_b(map);
		if (ft_strcmp(line, "ss") == 0)
			swap_ss(map);
		if (ft_strcmp(line, "pa") == 0)
			push_a(map);
		if (ft_strcmp(line, "pb") == 0)
			push_b(map);
		if (ft_strcmp(line, "ra") == 0)
			rotate_a(map);
		if (ft_strcmp(line, "rb") == 0)
			rotate_b(map);
		if (ft_strcmp(line, "rr") == 0)
			rotate_ss(map);
		if (ft_strcmp(line, "rra") == 0)
			reverse_a(map);
		if (ft_strcmp(line, "rrb") == 0)
			reverse_b(map);
		if (ft_strcmp(line, "rrr") == 0)
			reverse_ss(map);
	}
}

int main(int argc, char **argv)
{
	int i;
	t_lst *next;
	t_map map;

	if (argc == 1)
		return (0);
	i = 1;
	next = newmaillon(ft_atoi(argv[1]));
	map.beginA = next;
	while (argv[++i])
	{
		next->next = newmaillon(ft_atoi(argv[i]));
		next = next->next;
	}
	read_operation(&map);
	verification(map);
}
