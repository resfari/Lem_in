/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:35:32 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/03 18:35:32 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

void	ft_max_links_needed(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (lem->links[lem->start][i] != -1)
		i++;
	while (lem->links[lem->finish][j] != -1)
		j++;
	if (i < j)
		lem->max_links = i;
	else
		lem->max_links = j;
}

void	ft_init_ford2(t_lem *lem)
{
	int j;

	j = 0;
	while (j < 20000)
	{
		lem->passed[j][0] = 0;
		j++;
	}
	lem->stack_added = 0;
	lem->stack_walking = 0;
	lem->check = 0;
	lem->memory_stack[0] = -1;
	lem->stack_count = 0;
	lem->round = 0;
	lem->bell_count = 0;
}

void	ft_init_ford(t_lem *lem)
{
	int j;

	j = 0;
	while (j < 20000)
	{
		if (j < lem->another_one_count)
			lem->another_one[j][0] = -1;
		lem->updated_links[j][0] = -1;
		lem->weight[j][0] = 9999999;
		lem->way_links[j][0] = -1;
		lem->way[j][0] = -1;
		lem->stack[j] = 0;
		j++;
	}
	lem->pretend[0][0] = -1;
	lem->pretend_count = 0;
	lem->stack_added = 0;
	lem->stack_walking = 0;
	lem->memory_stack[0] = -1;
	lem->stack_count = 0;
	lem->round = 0;
	lem->another_one_count = 0;
	lem->peak_added = 0;
	lem->weight_count = 0;
}

void	ft_init_lem2(t_lem *lem)
{
	int j;

	j = 0;
	while (j < 20000)
	{
		lem->updated_links[j][0] = -1;
		lem->weight[j][0] = 9999999;
		lem->way_links[j][0] = -1;
		lem->way[j][0] = -1;
		lem->stack[j] = 0;
		lem->passed[j][0] = 0;
		j++;
	}
}

void	ft_init_lem(t_lem *lem)
{
	lem->count_start = 0;
	lem->count_end = 0;
	lem->round = 0;
	lem->passed_count = 0;
	lem->pretend_count = 0;
	lem->final_count = 0;
	lem->set_finish = 0;
	lem->set_start = 0;
	lem->start = -1;
	lem->finish = -1;
	lem->links_count = 1;
	lem->peak_count = 0;
	lem->max_links = 0;
	lem->final[0][0] = -1;
	lem->read_queue = 0;
	lem->stack_added = 0;
	lem->stack_walking = 0;
	lem->check = 0;
	lem->memory_stack[0] = -1;
	lem->stack_count = 0;
	lem->passed_count = 0;
	lem->valid_count = 0;
	lem->ants = 0;
	lem->another_one_count = 0;
	ft_init_lem2(lem);
}
