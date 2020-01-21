/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:24:01 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/26 18:24:01 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

int	ft_check_valid_xy(t_xy **alst, t_xy *new, int y, int x)
{
	t_xy *node;

	node = *alst;
	if (node == NULL)
		*alst = new;
	else
	{
		while (node->next != NULL)
		{
			if (y == node->y && x == node->x)
				return (0);
			node = node->next;
		}
		if (y == node->y && x == node->x)
			return (0);
		node->next = new;
	}
	return (1);
}

int	ft_check_valid_name(t_name **alst, t_name *new)
{
	t_name *node;

	node = *alst;
	if (node == NULL)
		*alst = new;
	else
	{
		while (node->next != NULL)
		{
			if (ft_strcmp(node->name, new->name) == 0)
				return (0);
			node = node->next;
		}
		if (ft_strcmp(node->name, new->name) == 0)
			return (0);
		node->next = new;
	}
	return (1);
}
