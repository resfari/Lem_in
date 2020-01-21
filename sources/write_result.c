/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:18:58 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/11 20:18:58 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

int		ft_lenght(int *mass)
{
	int i;

	i = 0;
	while (mass[i] != -1)
	{
		i++;
	}
	return (i - 1);
}

int		ft_max_effective_way(t_lem *lem, int i, int ant)
{
	int summ;
	int k;

	if (i == 0)
		return (1);
	k = i;
	summ = 0;
	i--;
	while (i >= 0)
	{
		summ += lem->len_way[k][0] - lem->len_way[i][0];
		i--;
	}
	if (lem->ants - ant + 1 > summ)
		return (1);
	return (0);
}

void	ft_display(t_lem *lem, int i, int ant, int count)
{
	int j;

	ft_collect_lenght(lem);
	while (ft_check_previous_step(lem, count) == 1 || ant <= lem->ants)
	{
		i = 0;
		count = 1;
		while (lem->len_way[i][0] != -1 && ant <= lem->ants)
		{
			if (ft_max_effective_way(lem, i, ant) == 1)
			{
				j = lem->len_way[i][1];
				write(1, "L", 1);
				ft_putnbr_fd(ant, 1);
				write(1, "-", 1);
				ft_putstr_fd(lem->peaks[lem->final[j][1]], 1);
				write(1, " ", 1);
				lem->ants_in_room[lem->final[j][1]][0] = ant;
				ant++;
			}
			i++;
		}
		write(1, "\n", 1);
	}
}

void	ft_write_result(t_lem *lem)
{
	int i;
	int ant;
	int count;

	i = 0;
	count = 0;
	ant = 1;
	ft_display(lem, i, ant, count);
}
