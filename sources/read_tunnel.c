/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_peak_tunnel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:02:50 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/30 14:02:50 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

void	ft_read_tunnels2(t_lem *lem, int code1, int code2)
{
	int i;

	i = 0;
	while (i < 5000)
	{
		if (lem->links[lem->codes[code2][0]][i] == -1)
		{
			lem->links[lem->codes[code2][0]][i] = lem->codes[code1][0];
			lem->links[lem->codes[code2][0]][i + 1] = -1;
			i = 5000;
		}
		i++;
	}
}

int		ft_read_tunnels(char *line, t_lem *lem, t_name **name)
{
	int code1;
	int code2;
	int i;

	i = 0;
	lem->i_tunnel = 0;
	code1 = give_tunnel(line, lem, name);
	code2 = give_tunnel(line, lem, name);
	if (lem->valid_count > 0)
		return (0);
	while (i < 5000)
	{
		if (lem->links[lem->codes[code1][0]][i] == -1)
		{
			lem->links[lem->codes[code1][0]][i] = lem->codes[code2][0];
			lem->links[lem->codes[code1][0]][i + 1] = -1;
			i = 5000;
		}
		i++;
	}
	ft_read_tunnels2(lem, code1, code2);
	return (1);
}

int		ft_read_tunnel(t_lem *lem, t_name **name, char *line)
{
	lem->read_queue = 1;
	if (lem->peak_count == 0)
	{
		ft_strdel(&line);
		lem->valid_count = 5;
		return (0);
	}
	if (ft_read_tunnels(line, lem, name) == 0)
	{
		ft_strdel(&line);
		lem->valid_count = 6;
		return (0);
	}
	return (1);
}
