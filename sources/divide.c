/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:32:41 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/16 20:32:41 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

void	add_in_way_links(int to_find, int to_add, t_lem *lem)
{
	int i;

	i = 0;
	while (lem->way_links[to_find][i] != -1)
	{
		i++;
	}
	lem->way_links[to_find][i] = to_add;
	lem->way_links[to_find][i + 1] = -1;
}

void	previous_ways(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	while (i < lem->final_count)
	{
		j = 0;
		while (lem->final[i][j] != lem->finish && lem->final[i][j] != -1)
		{
			add_in_way_links(lem->final[i][j], lem->final[i][j + 1], lem);
			j++;
		}
		i++;
	}
}

void	pretend_way(t_lem *lem)
{
	int i;

	i = 0;
	while (lem->pretend[0][i] != lem->finish && lem->pretend[0][i] != -1)
	{
		add_in_way_links(lem->pretend[0][i], lem->pretend[0][i + 1], lem);
		i++;
	}
}

void	divide_ways(t_lem *lem)
{
	int i;

	i = 0;
	previous_ways(lem);
	pretend_way(lem);
	going_on_links(lem, i);
}
