/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_weight_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:21:54 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/29 20:21:54 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

int		ft_look_weight_count(t_lem *lem)
{
	if (lem->weight_count == 1)
	{
		lem->weight_count = 0;
		return (0);
	}
	return (1);
}

int		ft_look_pretend_count(t_lem *lem)
{
	if (lem->pretend_count == 0)
		return (0);
	return (1);
}
