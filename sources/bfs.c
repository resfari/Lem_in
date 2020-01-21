/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:48:40 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/24 14:48:40 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

int		ft_first_run(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	while (lem->links[lem->start][i] != -1)
	{
		j = lem->links[lem->start][i];
		if (j == lem->finish)
		{
			lem->way[lem->finish][0] = lem->start;
			return (0);
		}
		if (lem->weight[j][0] == 9999999)
		{
			lem->weight[j][0] = 1;
			lem->way[j][0] = lem->start;
		}
		lem->stack[lem->stack_count] = j;
		lem->stack_count++;
		i++;
	}
	lem->stack[lem->stack_count] = -1;
	lem->stack_added = lem->stack_count;
	return (1);
}

int		check_add_stack(t_lem *lem)
{
	if (lem->stack_walking >= lem->stack_added)
	{
		if (lem->add_stack == 0)
		{
			if (lem->pretend_count == 0)
				return (0);
			return (1);
		}
		lem->memory_stack[0] = -1;
		lem->stack_walking = 0;
		lem->stack_added = lem->add_stack;
		lem->add_stack = 0;
		lem->check++;
	}
	return (2);
}

void	bfs_helper(t_lem *lem, int i)
{
	if (lem->links[lem->stack[lem->round]][i] != lem->start)
	{
		if (ft_memory_of_stack(lem,
				lem->links[lem->stack[lem->round]][i]) == 1
				&& lem->links[lem->stack[lem->round]][i] != lem->finish)
		{
			ft_add_in_stack(lem,
					lem->links[lem->stack[lem->round]][i]);
			lem->add_stack++;
		}
		ft_add_new_num_in_mass_weight_first(lem, lem->stack[lem->round],
				lem->links[lem->stack[lem->round]][i]);
	}
}

int		bfs(t_lem *lem)
{
	int i;

	lem->add_stack = 0;
	if (ft_first_run(lem) == 0)
		return (1);
	while (lem->check < lem->peak_count && lem->pretend_count != 1)
	{
		i = 0;
		if (lem->passed[lem->stack[lem->round]][0] == 0)
		{
			lem->passed[lem->stack[lem->round]][0] = 1;
			while (lem->links[lem->stack[lem->round]][i] != -1
			&& lem->pretend_count != 1)
			{
				bfs_helper(lem, i);
				i++;
			}
		}
		lem->stack_walking++;
		lem->round++;
		if (check_add_stack(lem) != 2)
			return (ft_look_pretend_count(lem));
	}
	return (ft_look_pretend_count(lem));
}
