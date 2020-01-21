/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_result2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:52:51 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/29 18:52:51 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

void	ft_collect_len2(t_lem *lem, int i)
{
	int mem;
	int mem2;

	lem->len_way[i][0] = -1;
	i = 0;
	while (lem->len_way[i + 1][0] != -1 && lem->len_way[i][0] != -1)
	{
		if (lem->len_way[i][0] > lem->len_way[i + 1][0])
		{
			mem = lem->len_way[i + 1][0];
			mem2 = lem->len_way[i + 1][1];
			lem->len_way[i + 1][0] = lem->len_way[i][0];
			lem->len_way[i + 1][1] = lem->len_way[i][1];
			lem->len_way[i][0] = mem;
			lem->len_way[i][1] = mem2;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_collect_lenght(t_lem *lem)
{
	int i;
	int k;
	int j;

	i = 0;
	while (i < lem->final_count)
	{
		k = 0;
		lem->len_way[i][0] = ft_lenght(lem->final[i]);
		lem->len_way[i][1] = i;
		while (lem->final[i][k] != -1)
		{
			j = lem->final[i][k];
			if (j == lem->start)
				lem->ants_in_room[j][0] = 0;
			else if (j == lem->finish)
				lem->ants_in_room[j][0] = 0;
			else
				lem->ants_in_room[j][0] = -1;
			k++;
		}
		i++;
	}
	ft_collect_len2(lem, i);
}

int		ft_check_prev_step2(t_lem *lem, int i, int k)
{
	int j;
	int j2;

	j = lem->final[i][k - 1];
	j2 = lem->final[i][k];
	if (lem->ants_in_room[j][0] > 0)
	{
		write(1, "L", 1);
		ft_putnbr_fd(lem->ants_in_room[j][0], 1);
		write(1, "-", 1);
		ft_putstr_fd(lem->peaks[j2], 1);
		write(1, " ", 1);
		lem->ants_in_room[j2][0] = lem->ants_in_room[j][0];
		lem->ants_in_room[j][0] = -1;
		return (1);
	}
	return (0);
}

int		ft_check_previous_step(t_lem *lem, int cnt)
{
	int i;
	int k;
	int count;

	i = 0;
	count = 0;
	while (i < lem->final_count)
	{
		k = 0;
		while (lem->final[i][k] != lem->finish && lem->final[i][k] != -1)
			k++;
		while (k - 1 > 0)
		{
			if (ft_check_prev_step2(lem, i, k) == 1)
				count++;
			k--;
		}
		i++;
	}
	if (count > 0 || cnt == 0)
		return (1);
	return (0);
}
