/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:08:04 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/29 20:08:04 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

int		ft_add_in_final(t_lem *lem)
{
	int i;
	int j;

	i = 0;
	while (i < lem->another_one_count)
	{
		j = 0;
		while (lem->another_one[i][j] != -1)
		{
			lem->final[i][j] = lem->another_one[i][j];
			j++;
		}
		lem->final[i][j] = -1;
		i++;
	}
	lem->final_count = i;
	return (0);
}
