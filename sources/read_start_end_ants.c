/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_start_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:02:03 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/30 14:02:03 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

int		ft_reading_ants(t_lem *lem, char *line)
{
	if (lem->cnt_read_ants == 0)
	{
		lem->cnt_read_ants = ft_check_ants(line, lem);
		if (lem->valid_count == 2)
		{
			ft_strdel(&line);
			return (0);
		}
	}
	return (1);
}

int		ft_read_start(t_lem *lem, char *line)
{
	if (lem->read_queue == 1)
	{
		lem->valid_count = 9;
		ft_strdel(&line);
		return (0);
	}
	if (lem->set_start == 0)
	{
		lem->set_start = 1;
		lem->count_start = 1;
	}
	return (1);
}

int		ft_read_end(t_lem *lem, char *line)
{
	if (lem->read_queue == 1)
	{
		lem->valid_count = 9;
		ft_strdel(&line);
		return (0);
	}
	if (lem->set_finish == 0)
	{
		lem->set_finish = 1;
		lem->count_end = 1;
	}
	return (1);
}
