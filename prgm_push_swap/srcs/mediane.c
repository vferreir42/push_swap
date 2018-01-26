/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:20:17 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/17 16:48:53 by vferreir         ###   ########.fr       */
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

	if (begin->number != value)
	{
		sauv = begin;
		while (begin->next && begin->next->number != value)
		{
			begin = begin->next;
		}
		if (begin->next)
			begin->next = begin->next->next;
		return (sauv);
	}
	else
	{
		begin = begin->next;
		return (begin);
	}
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
	while (mediane && size-- > 0)
		mediane = mediane->next;
	return (mediane->number);
}
