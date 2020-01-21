/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_and_fill_weight.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:36:02 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/29 20:36:02 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

void	ft_add_in_stack(t_lem *lem, int numb)
{
	lem->stack[lem->stack_count] = numb;
	lem->stack_count++;
	lem->stack[lem->stack_count] = -1;
}

int		ft_memory_of_stack(t_lem *lem, int num)
{
	int i;

	i = 0;
	while (lem->memory_stack[i] != -1)
	{
		if (lem->memory_stack[i] == num)
			return (0);
		i++;
	}
	lem->memory_stack[i] = num;
	lem->memory_stack[i + 1] = -1;
	return (1);
}

void	ft_add_new_num_in_mass_weight_first(t_lem *lem, int i, int to_put)
{
	int weight;

	weight = lem->weight[i][0] + 1;
	if (weight < lem->weight[to_put][0])
	{
		lem->weight[to_put][0] = weight;
		lem->way[to_put][0] = i;
		if (to_put == lem->finish)
		{
			lem->pretend_count = 1;
		}
	}
}
