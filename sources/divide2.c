/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:21:36 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/29 19:21:36 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

int		check_way_links(int a, int b, t_lem *lem)
{
	int i;

	i = 0;
	while (lem->way_links[b][i] != -1)
	{
		if (lem->way_links[b][i] == a)
			return (0);
		i++;
	}
	return (1);
}

int		going_on_lks(t_lem *lem, int j, int i)
{
	int k;
	int next;
	int in_mass;

	in_mass = 2;
	while (j != lem->finish)
	{
		k = 0;
		while (lem->way_links[j][k] != -1)
		{
			next = lem->way_links[j][k];
			if (check_way_links(j, next, lem) == 1)
			{
				j = lem->way_links[j][k];
				lem->another_one[i][in_mass] = j;
				in_mass++;
				break ;
			}
			k++;
		}
	}
	return (in_mass);
}

void	going_on_links(t_lem *lem, int i)
{
	int j;
	int in_mass;

	while (lem->way_links[lem->start][i] != -1)
	{
		j = lem->way_links[lem->start][i];
		lem->another_one[i][0] = lem->start;
		lem->another_one[i][1] = j;
		in_mass = going_on_lks(lem, j, i);
		lem->another_one[i][in_mass] = -1;
		i++;
	}
	lem->another_one_count = i;
}
