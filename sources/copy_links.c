/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:41:45 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/03 18:41:45 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

void	ft_add_pts(int *mass, int a, int b, t_lem *lem)
{
	int i;

	i = -1;
	if (a == lem->start)
	{
		lem->updated_links[b][0] = a;
		lem->updated_links[b][1] = -1;
		while (mass[++i] != -1)
			lem->updated_links[b + 10000][i] = mass[i];
		lem->updated_links[b + 10000][i] = b;
		lem->updated_links[b + 10000][i + 1] = -1;
		lem->peak_added++;
	}
	else
	{
		lem->updated_links[b][0] = a + 10000;
		lem->updated_links[b][1] = -1;
		while (mass[++i] != -1)
			lem->updated_links[b + 10000][i] = mass[i];
		lem->updated_links[b + 10000][i] = b;
		lem->updated_links[b + 10000][i + 1] = -1;
		lem->peak_added++;
	}
}

void	ft_add_new_points(int a, int b, t_lem *lem)
{
	int mass[1000];
	int i;
	int j;

	i = 0;
	j = 0;
	if (b == lem->finish)
		return ;
	while (lem->updated_links[b][i] != -1)
	{
		if (lem->updated_links[b][i] != a)
		{
			mass[j] = lem->updated_links[b][i];
			j++;
		}
		i++;
	}
	mass[j] = -1;
	ft_add_pts(mass, a, b, lem);
}

void	ft_delete_lnks(int a, int b, t_lem *lem)
{
	int mass[1000];
	int i;
	int j;

	i = 0;
	j = 0;
	while (lem->updated_links[a][i] != -1)
	{
		if (lem->updated_links[a][i] != b)
		{
			mass[j] = lem->updated_links[a][i];
			j++;
		}
		i++;
	}
	mass[j] = -1;
	i = 0;
	while (mass[i] != -1)
	{
		lem->updated_links[a][i] = mass[i];
		i++;
	}
	lem->updated_links[a][i] = -1;
}

void	ft_delete_links(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	while (i < lem->final_count)
	{
		j = 0;
		while (lem->final[i][j] != lem->finish && lem->final[i][j] != -1)
		{
			ft_delete_lnks(lem->final[i][j], lem->final[i][j + 1], lem);
			ft_add_new_points(lem->final[i][j], lem->final[i][j + 1], lem);
			j++;
		}
		i++;
	}
}

void	ft_copy_links(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	while (i < lem->peak_count)
	{
		j = 0;
		while (lem->links[i][j] != -1)
		{
			lem->updated_links[i][j] = lem->links[i][j];
			j++;
		}
		if (lem->links[i][j] == -1)
			lem->updated_links[i][j] = -1;
		i++;
	}
	ft_delete_links(lem);
}
