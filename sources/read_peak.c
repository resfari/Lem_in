/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_peak.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:04:01 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/30 14:04:01 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

int		ft_give_code(char *line)
{
	int			i;
	int			g;
	long int	hash;

	i = 0;
	hash = 0;
	g = 31;
	while (line[i] != '\0')
	{
		if (hash >= 100000000)
			hash %= 100000000;
		hash = g * hash + line[i];
		i++;
	}
	if (hash >= 100000000)
		hash %= 100000000;
	return ((int)hash);
}

int		ft_read_peaks2(t_lem *lem, char *line)
{
	int code;

	if (line[lem->i_peak] != '\0')
		lem->valid_count = 5;
	lem->links[lem->peak_count][0] = -1;
	code = ft_give_code(lem->peaks[lem->peak_count]);
	lem->codes[code][0] = lem->peak_count;
	if (lem->set_start == 1)
	{
		lem->start = lem->peak_count;
		lem->set_start = 2;
	}
	if (lem->set_finish == 1)
	{
		lem->finish = lem->peak_count;
		lem->set_finish = 2;
	}
	return (1);
}

int		ft_read_peaks(char *line, t_lem *lem, t_xy **xy, t_name **name)
{
	t_xy	*help;
	t_name	*name_dupl;

	if (!(help = (t_xy*)malloc(sizeof(t_xy) * 1)))
		return (0);
	if (!(name_dupl = (t_name*)malloc(sizeof(t_name) * 1)))
	{
		free(help);
		return (0);
	}
	help->next = NULL;
	name_dupl->next = NULL;
	lem->i_peak = 0;
	name_dupl->name = give_peak(line, lem);
	help->y = give_yx_peak(line, lem);
	help->x = give_yx_peak(line, lem);
	if (ft_check_valid_xy(xy, help, help->y, help->x) == 0
			|| ft_check_valid_name(name, name_dupl) == 0)
	{
		lem->valid_count = 7;
		return (0);
	}
	return (ft_read_peaks2(lem, line));
}

int		ft_read_peak(t_lem *lem, t_xy **xy, t_name **name, char *line)
{
	if ((lem->set_start == 1 && lem->count_start != 2)
			|| (lem->set_finish == 1 && lem->count_end != 2) ||
			lem->read_queue == 1 || ft_read_peaks(line, lem, xy, name) == 0)
	{
		if (lem->valid_count > 0)
		{
			ft_strdel(&line);
			return (0);
		}
		lem->valid_count = 5;
		ft_strdel(&line);
		return (0);
	}
	lem->peak_count++;
	return (1);
}
