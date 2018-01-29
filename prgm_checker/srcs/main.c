/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:34:25 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/29 19:30:56 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_operation(t_map *map)
{
	char	*line;

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
			write(1, "Error\n", 6);
			free(line);
			exit(0);
		}
		free(line);
	}
	free(line);
}

void	put_argv_in_list(t_map *map, char **argv, int i)
{
	t_lst	*next;

	next = NULL;
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
	char	**new;
	t_map	map;

	new = NULL;
	if (argc == 1)
		exit(0);
	if (ft_strchr(argv[1], ' ') != NULL && argv[2] == NULL)
	{
		new = ft_strsplit(argv[1], ' ');
		parcing_argv(new);
		put_argv_in_list(&map, new, 0);
	}
	else
	{
		parcing_argv(argv);
		put_argv_in_list(&map, argv, 1);
	}
	parcing_not_same_number(map);
	read_operation(&map);
	verification(map);
	free_list(&map);
	if (new)
		del_tab(&new);
}
