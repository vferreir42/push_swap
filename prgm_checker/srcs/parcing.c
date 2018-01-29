/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:38:39 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/29 19:34:11 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	parcing_argv(char **argv)
{
	int	i;
	int t;

	i = 1;
	while (argv[i])
	{
		t = 0;
		while (argv[i][t])
		{
			if (ft_isdigit(argv[i][t]) != 1 && argv[i][t] != '-')
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			t++;
		}
		i++;
	}
}

void	parcing_not_same_number(t_map map)
{
	t_lst *begin;
	t_lst *next;

	begin = map.begin_a;
	while (begin)
	{
		begin->gris = 1;
		next = map.begin_a;
		while (next)
		{
			if (begin->number == next->number && next->gris == 0)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			next = next->next;
		}
		begin->gris = 0;
		begin = begin->next;
	}
}

void	parcing_size_int(long int nb)
{
	if (nb > 2147483647 || nb < -2147483648)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}
