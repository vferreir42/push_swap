/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:10:10 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/17 17:56:00 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

typedef struct	s_lst
{
	int				number;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_map
{
	t_lst			*beginA;
	t_lst			*beginB;
	t_lst			*beginop;
	t_lst			*operation;
	int				counter;
	int				med;
}				t_map;

int				sort_pile_a(t_map *map, t_lst *begin, int size);
int				sort_pile_b(t_map *map, t_lst *begin, int size);
void			display_operation(t_map map);
void			display(t_map map, int size);
int				recursive_a(t_map *map, int size);
int				recursive_b(t_map *map, int size);
int				sizepile(t_lst *begin);
int				mediane (t_lst *lst, int size);
int				verifordre(t_map map);
t_lst			*newmaillon(int receipt);
void			swap_a(t_map *map);
void			swap_b(t_map *map);
void			push_a (t_map *map);
void			push_b (t_map *map);
void			rotate_a(t_map *map);
void			rotate_b(t_map *map);
void			reverse_a(t_map *map);
void			reverse_b(t_map *map);

#endif
