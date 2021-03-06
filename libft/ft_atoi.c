/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:44:24 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/29 19:37:35 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *nptr)
{
	long int	i;
	long int	nb;
	int			neg;

	i = 0;
	neg = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v'
	|| nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	if (nptr[i] == '+')
		i++;
	nb = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	if (neg == -1)
		nb = -nb;
	return (nb);
}
