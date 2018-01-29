/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:46:03 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/29 19:35:33 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	del_tab(char ***map)
{
	char	**erase;
	int		i;

	erase = NULL;
	i = 0;
	if (!(*map) || !map)
		return ;
	erase = *map;
	while (erase[i])
	{
		ft_strdel(&erase[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

void	free_list(t_map *map)
{
	t_lst	*tmp;

	while (map->begin_a)
	{
		tmp = map->begin_a;
		map->begin_a = map->begin_a->next;
		free(tmp);
	}
	while (map->begin_b)
	{
		tmp = map->begin_b;
		map->begin_b = map->begin_b->next;
		free(tmp);
	}
}

t_lst	*newmaillon(int receipt)
{
	t_lst	*ptr;

	ptr = NULL;
	if (!(ptr = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	ptr->number = receipt;
	ptr->next = NULL;
	return (ptr);
}

void	verification(t_map map)
{
	int		number;

	number = 0;
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
	write(1, "OK\n", 3);
}
