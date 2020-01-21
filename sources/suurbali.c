/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suurbali.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:41:07 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/03 18:41:07 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

int		ft_side(t_lem *lem, int size_count, int *size, int max_size)
{
	int summ;

	summ = 0;
	while (size_count >= 0)
	{
		if (size[size_count] != -1)
			summ += max_size - size[size_count];
		size_count--;
	}
	if (lem->ants <= summ)
		return (1);
	return (0);
}

int		ft_check_side(t_lem *lem)
{
	int i;
	int j;
	int max_size;
	int size[1000];
	int size_count;

	i = 0;
	max_size = 0;
	size_count = 0;
	while (i < lem->another_one_count)
	{
		j = 0;
		while (lem->another_one[i][j] != lem->finish &&
		lem->another_one[i][j] != -1)
			j++;
		size[size_count] = j;
		size[size_count + 1] = -1;
		size_count++;
		if (j > max_size)
			max_size = j;
		i++;
	}
	return (ft_side(lem, size_count, size, max_size));
}

int		ft_after_bellman_ford(t_lem *lem)
{
	if (lem->pretend_count == 0)
		return (1);
	if (ft_way(lem) == 1)
		return (1);
	divide_ways(lem);
	if (ft_check_side(lem) == 1)
		return (1);
	else
	{
		if (ft_add_in_final(lem) == 1)
			return (1);
	}
	return (0);
}

void	ft_suurbali_round(t_lem *lem)
{
	ft_init_ford2(lem);
	lem->passed_count++;
	if (bellman_ford(lem) == 1)
		lem->weight_count = 1;
}

int		ft_suurbali(t_lem *lem)
{
	int i;
	int count;

	if (bfs(lem) == 0)
		return (0);
	else
	{
		lem->passed_count++;
		ft_way_first(lem);
		i = 1;
		while (i < lem->max_links)
		{
			count = -1;
			ft_init_ford(lem);
			ft_copy_links(lem);
			while (++count < lem->peak_added + lem->peak_count - 1
			&& lem->weight_count == 0)
				ft_suurbali_round(lem);
			if (ft_after_bellman_ford(lem) == 1)
				return (1);
			i++;
		}
	}
	return (1);
}
