/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:39:12 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/16 19:39:12 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

int		price(int a, int b, t_lem *lem)
{
	int i;
	int j;

	i = 0;
	while (i < lem->final_count)
	{
		j = 0;
		while (lem->final[i][j] != lem->finish && lem->final[i][j] != -1)
		{
			if (j > 0)
			{
				if (lem->final[i][j] == b && lem->final[i][j + 1] == a)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	best_cost(t_lem *lem)
{
	int i;
	int j;
	int cost;
	int best_cost;

	i = -1;
	best_cost = 9999999;
	while (++i < lem->pretend_count)
	{
		j = 0;
		cost = 0;
		while (lem->pretend[i][j] != lem->finish && lem->pretend[i][j] != -1)
		{
			if (price(lem->pretend[i][j], lem->pretend[i][j + 1], lem) == 1)
				cost -= 1;
			else
				cost += 1;
			j++;
		}
		if (cost < best_cost)
		{
			lem->best_pretend = i;
			best_cost = cost;
		}
	}
}
