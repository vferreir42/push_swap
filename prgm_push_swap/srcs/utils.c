/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 19:21:46 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/27 19:21:47 by vferreir         ###   ########.fr       */
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

	while (map.begin_a)
	{
		number = map.begin_a->number;
		map.begin_a = map.begin_a->next;
		if (map.begin_a && number > map.begin_a->number)
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
