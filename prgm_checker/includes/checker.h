/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:08:42 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/29 19:36:48 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "get_next_line.h"

typedef struct	s_lst
{
	int				number;
	int				gris;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_map
{
	t_lst			*begin_a;
	t_lst			*begin_b;
	int				med;
}				t_map;

void			parcing_argv(char **argv);
void			parcing_not_same_number(t_map map);
void			parcing_size_int(long int nb);
t_lst			*newmaillon(int receipt);
void			verification(t_map map);
void			del_tab(char ***map);
void			free_list(t_map *map);
t_lst			*newmaillon(int receipt);
void			swap_a(t_map *map);
void			swap_b(t_map *map);
void			swap_ss(t_map *map);
void			push_a (t_map *map);
void			push_b (t_map *map);
void			rotate_a(t_map *map);
void			rotate_b(t_map *map);
void			rotate_ss(t_map *map);
void			reverse_a(t_map *map);
void			reverse_b(t_map *map);
void			reverse_ss(t_map *map);

#endif
