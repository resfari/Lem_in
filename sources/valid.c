/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:19:24 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/23 16:19:24 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

int		ft_check_ants(char *s, t_lem *lem)
{
	int			i;
	long int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			lem->valid_count = 2;
		j = j * 10 + (s[i] - 48);
		i++;
	}
	if (j > 2147483647 || j < -2147483648 || j <= 0 || i > 10 || i == 0)
	{
		lem->valid_count = 2;
		return (1);
	}
	else
		lem->ants = (int)j;
	return (1);
}

int		ft_no_name(char *str, t_name **name)
{
	t_name *node;

	node = *name;
	while (node != NULL)
	{
		if (ft_strcmp(node->name, str) == 0)
			return (1);
		node = node->next;
	}
	return (0);
}
