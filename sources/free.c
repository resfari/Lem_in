/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:16:47 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/23 20:16:47 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

void	ft_error_message(int n_err)
{
	if (n_err == 1)
		write(1, "ERROR : NO WAY\n", 14);
	else if (n_err == 2)
		write(1, "ERROR : -->Check Ants<--\n", 24);
	else if (n_err == 3)
		write(1, "ERROR :\n", 8);
	else if (n_err == 4)
		write(1, "ERROR : -->Check Start and End Peaks<--\n", 39);
	else if (n_err == 5)
		write(1, "ERROR : -->Check Peaks<--\n", 25);
	else if (n_err == 6)
		write(1, "ERROR : -->Check Links<--\n", 25);
	else if (n_err == 7)
		write(1, "ERROR : -->Check Coordinates<--\n", 31);
	else if (n_err == 8)
		write(1, "ERROR : -->Peaks have same names<--\n", 35);
	else if (n_err == 9)
		write(1, "ERROR : -->Check ##Start or ##End<--\n", 36);
}

void	ft_free_name(t_name **name)
{
	t_name *name_help;

	name_help = (*name);
	if (*name)
	{
		while (*name)
		{
			name_help = (*name)->next;
			free((*name)->name);
			ft_memdel((void **)name);
			*name = name_help;
		}
		free(name);
	}
}

void	ft_free_xy(t_xy **xy)
{
	t_xy *help;

	help = (*xy);
	if (*xy)
	{
		while (*xy)
		{
			help = (*xy)->next;
			ft_memdel((void **)xy);
			*xy = help;
		}
		free(xy);
	}
}

void	ft_free_lem(t_lem *lem, t_xy **xy, t_name **name)
{
	ft_free_name(name);
	ft_free_xy(xy);
	if (lem->valid_count > 0)
		ft_error_message(lem->valid_count);
	free(lem);
	exit(1);
}
