/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bellman_ford.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:02:17 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/11 21:02:17 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

void	ft_add_new_num_in_mass_weight(t_lem *lem, int i, int to_put)
{
	int weight;

	weight = lem->weight[i][0] + ft_weight(i, to_put, lem);
	if (weight < lem->weight[to_put][0])
	{
		lem->weight[to_put][0] = weight;
		lem->way[to_put][0] = i;
		lem->weight_count = 1;
		if (to_put == lem->finish)
		{
			lem->pretend_count = 1;
		}
	}
}

void	ft_run(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	while (lem->updated_links[lem->start][i] != -1)
	{
		j = lem->updated_links[lem->start][i];
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
}

int		check_weight_count(t_lem *lem)
{
	if (lem->stack_walking >= lem->stack_added)
	{
		if (lem->add_stack == 0)
		{
			if (lem->weight_count == 1)
			{
				lem->weight_count = 0;
				return (0);
			}
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

void	bellman_helper(t_lem *lem, int i)
{
	if (lem->updated_links[lem->stack[lem->round]][i] != lem->start)
	{
		if (ft_memory_of_stack(lem,
				lem->updated_links[lem->stack[lem->round]][i]) == 1
				&& lem->updated_links[lem->stack[lem->round]][i] != lem->finish)
		{
			ft_add_in_stack(lem,
					lem->updated_links[lem->stack[lem->round]][i]);
			lem->add_stack++;
		}
		ft_add_new_num_in_mass_weight(lem, lem->stack[lem->round],
				lem->updated_links[lem->stack[lem->round]][i]);
	}
}

int		bellman_ford(t_lem *lem)
{
	int i;

	lem->add_stack = 0;
	ft_run(lem);
	while (lem->check < lem->peak_count + lem->peak_added - 1)
	{
		i = 0;
		if (lem->passed[lem->stack[lem->round]][0] == 0)
		{
			lem->passed[lem->stack[lem->round]][0] = 1;
			while (lem->updated_links[lem->stack[lem->round]][i] != -1)
			{
				bellman_helper(lem, i);
				i++;
			}
		}
		lem->stack_walking++;
		lem->round++;
		if (check_weight_count(lem) != 2)
			return (ft_look_weight_count(lem));
	}
	return (ft_look_weight_count(lem));
}
