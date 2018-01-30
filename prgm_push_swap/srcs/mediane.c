/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:20:17 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/30 15:08:18 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		biggestvalue(t_lst *begin)
{
	int		value;
	t_lst	*sauv;

	sauv = begin;
	value = begin->number;
	while (begin)
	{
		if (value < begin->number)
			value = begin->number;
		begin = begin->next;
	}
	begin = sauv;
	return (value);
}

t_lst	*supprmaillon(t_lst *begin, int value)
{
	t_lst	*sauv;
	t_lst	*tmp;

	if (begin->number != value)
	{
		sauv = begin;
		while (begin->next && begin->next->number != value)
			begin = begin->next;
		if (begin->next)
		{
			tmp = begin->next;
			begin->next = begin->next->next;
			free(tmp);
		}
		return (sauv);
	}
	else
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
		return (begin);
	}
}

int		returne_mediane(t_lst *mediane, int size)
{
	t_lst	*tmp;

	while (mediane && size-- > 0)
	{
		tmp = mediane;
		mediane = mediane->next;
		free(tmp);
	}
	size = mediane->number;
	while (mediane)
	{
		tmp = mediane;
		mediane = mediane->next;
		free(tmp);
	}
	return (size);
}

int		mediane(t_lst *begin, int size)
{
	t_lst	*next;
	t_lst	*copy;
	t_lst	*mediane;

	copy = newmaillon(begin->number);
	next = copy;
	begin = begin->next;
	while (begin)
	{
		next->next = newmaillon(begin->number);
		next = next->next;
		begin = begin->next;
	}
	mediane = newmaillon(biggestvalue(copy));
	next = mediane;
	copy = supprmaillon(copy, next->number);
	while (next && copy)
	{
		next->next = newmaillon(biggestvalue(copy));
		copy = supprmaillon(copy, next->next->number);
		next = next->next;
	}
	return (returne_mediane(mediane, size));
}
