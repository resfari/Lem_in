/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_std.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:59:43 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/30 13:59:43 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

int		ft_read_std2(t_lem *lem, char *line, t_xy **xy, t_name **name)
{
	if (lem->cnt_read_ants == 0)
		return (ft_reading_ants(lem, line) == 0 ? 0 : 1);
	else if (ft_strnstr(line, "##start", 7) != NULL)
		return (ft_read_start(lem, line) == 0 ? 0 : 1);
	else if (ft_strnstr(line, "##end", 5) != NULL)
		return (ft_read_end(lem, line) == 0 ? 0 : 1);
	else if (ft_strchr(line, '#') != NULL)
	{
		ft_putstr_fd(line, 1);
		write(1, "\n", 1);
		ft_strdel(&line);
		return (2);
	}
	else if (ft_strchr(line, ' ') != NULL)
		return (ft_read_peak(lem, xy, name, line) == 0 ? 0 : 1);
	else if (ft_strchr(line, '-') != NULL)
		return (ft_read_tunnel(lem, name, line) == 0 ? 0 : 1);
	else
	{
		lem->valid_count = 3;
		ft_strdel(&line);
		return (0);
	}
}

int		ft_read_std(int file, t_lem *lem, t_xy **xy, t_name **name)
{
	char	*line;
	int		i;

	lem->cnt_read_ants = 0;
	while (get_next_line(file, &line) > 0)
	{
		i = ft_read_std2(lem, line, xy, name);
		if (i == 2)
			continue ;
		if (i == 0)
			return (0);
		if (lem->count_end >= 1)
			lem->count_end++;
		if (lem->count_start >= 1)
			lem->count_start++;
		ft_putstr_fd(line, 1);
		write(1, "\n", 1);
		ft_strdel(&line);
	}
	return (1);
}
