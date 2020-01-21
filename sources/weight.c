/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:24:45 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/20 18:24:45 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

int		ft_weight(int a, int b, t_lem *lem)
{
	int i;
	int j;

	i = 0;
	if (b == lem->finish)
	{
		return (1);
	}
	if (a >= 10000)
	{
		if (a - 10000 == b)
			return (0);
	}
	while (lem->updated_links[b][i] != -1)
	{
		j = lem->updated_links[b][i];
		if (j == a || j + 10000 == a)
			return (1);
		i++;
	}
	return (-1);
}

int		ft_way2(t_lem *lem, int k, int j)
{
	if (k == 10000)
		return (1);
	lem->pretend[1][k] = j;
	lem->pretend[0][0] = lem->start;
	j = 1;
	while (k >= 0)
	{
		lem->pretend[0][j] = lem->pretend[1][k];
		k--;
		j++;
	}
	lem->pretend[0][j] = -1;
	return (0);
}

int		ft_way(t_lem *lem)
{
	int j;
	int k;

	k = 0;
	j = lem->finish;
	while (lem->way[j][0] != lem->start && k < 10000)
	{
		if (j >= 10000)
		{
			lem->pretend[1][k] = j - 10000;
			j = lem->way[j][0];
			k++;
		}
		else
		{
			lem->pretend[1][k] = j;
			j = lem->way[j][0];
			k++;
		}
	}
	return (ft_way2(lem, k, j));
}

int		ft_way_first(t_lem *lem)
{
	int j;
	int k;

	k = 0;
	j = lem->finish;
	while (lem->way[j][0] != lem->start && k < 10000)
	{
		lem->pretend[1][k] = j;
		j = lem->way[j][0];
		k++;
	}
	if (k == 10000)
		return (1);
	lem->pretend[1][k] = j;
	lem->final[0][0] = lem->start;
	j = 1;
	while (k >= 0)
	{
		lem->final[0][j] = lem->pretend[1][k];
		k--;
		j++;
	}
	lem->final[0][j] = -1;
	lem->final_count = 1;
	return (0);
}
