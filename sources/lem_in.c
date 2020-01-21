/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:32:10 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/03 18:32:10 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

void	main_help(t_lem *lem, t_name **name, t_xy **xy, int file)
{
	if (ft_read_std(file, lem, xy, name) == 0)
		ft_free_lem(lem, xy, name);
	write(1, "\n", 1);
	if (lem->ants <= 0 || lem->start == -1 ||
	lem->finish == -1 || lem->set_start == 0 || lem->set_finish == 0)
	{
		lem->valid_count = 4;
		ft_free_lem(lem, xy, name);
	}
	ft_max_links_needed(lem);
	if (lem->max_links == 0)
	{
		lem->valid_count = 6;
		ft_free_lem(lem, xy, name);
	}
	lem->links[lem->finish][0] = -1;
	if (ft_suurbali(lem) == 1)
		ft_write_result(lem);
	else
		lem->valid_count = 1;
	ft_free_lem(lem, xy, name);
}

int		main(void)
{
	int		file;
	t_lem	*lem;
	t_xy	**xy;
	t_name	**name;

	file = 0;
	if (!(lem = (t_lem *)malloc(sizeof(t_lem) * 1)))
		return (0);
	if (!(xy = (t_xy **)malloc(sizeof(t_xy *) * 1)))
	{
		free(lem);
		return (0);
	}
	if (!(name = (t_name **)malloc(sizeof(t_name *) * 1)))
	{
		free(lem);
		free(xy);
		return (0);
	}
	(*xy) = NULL;
	(*name) = NULL;
	ft_init_lem(lem);
	main_help(lem, name, xy, file);
	return (0);
}
