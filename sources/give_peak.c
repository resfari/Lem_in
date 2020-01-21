/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_peak.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 14:13:38 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/09/30 14:51:45 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "lem_in.h"

char		*give_peak(char *line, t_lem *lem)
{
	int		i;
	char	*str;

	i = 0;
	while (line[lem->i_peak] != '\0' && line[lem->i_peak] != ' ')
	{
		if (line[lem->i_peak] == '-' || line[0] == 'L')
			lem->valid_count = 5;
		lem->peaks[lem->peak_count][lem->i_peak] = line[lem->i_peak];
		lem->i_peak++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (lem->i_peak + 1))))
		return (NULL);
	str[lem->i_peak] = '\0';
	while (i < lem->i_peak)
	{
		str[i] = line[i];
		i++;
	}
	if (lem->i_peak == 0)
		lem->valid_count = 5;
	lem->peaks[lem->peak_count][lem->i_peak] = '\0';
	return (str);
}

int			give_yx_peak(char *line, t_lem *lem)
{
	long int	res;
	int			j;

	res = 0;
	if (line[lem->i_peak] == ' ')
		lem->i_peak++;
	else
		lem->valid_count = 7;
	j = lem->i_peak;
	while (line[lem->i_peak] != '\0' && line[lem->i_peak] != ' ')
	{
		if (line[lem->i_peak] > '9' || line[lem->i_peak] < '0')
			lem->valid_count = 7;
		res = res * 10 + (line[lem->i_peak] - 48);
		lem->i_peak++;
	}
	if (res > 2147483647 || res < -2147483648 || lem->i_peak - j > 10)
		lem->valid_count = 6;
	return ((int)res);
}

long int	give_tunnel3(t_lem *lem, char *line)
{
	int			g;
	long int	res;

	res = 0;
	g = 31;
	while (line[lem->i_tunnel] != '\0' && line[lem->i_tunnel] != '-')
	{
		if (res >= 100000000)
			res %= 100000000;
		if (line[lem->i_tunnel] == ' ')
			lem->valid_count = 6;
		res = g * res + line[lem->i_tunnel];
		lem->i_tunnel++;
	}
	return (res);
}

int			give_tunnel2(t_lem *lem, char *line)
{
	if (lem->i_tunnel > 0)
	{
		if (line[lem->i_tunnel] != '-')
			lem->valid_count = 6;
		lem->i_tunnel++;
	}
	return (lem->i_tunnel);
}

int			give_tunnel(char *line, t_lem *lem, t_name **name)
{
	long int	res;
	int			i;
	int			g;
	char		*str;
	int			j;

	i = 0;
	g = 31;
	j = give_tunnel2(lem, line);
	res = give_tunnel3(lem, line);
	if (!(str = (char *)malloc(sizeof(char) * (lem->i_tunnel - j + 1))))
		return (0);
	while (j < lem->i_tunnel)
	{
		str[i] = line[j];
		i++;
		j++;
	}
	str[i] = '\0';
	if (ft_no_name(str, name) == 0)
		lem->valid_count = 6;
	if (res >= 100000000)
		res %= 100000000;
	free(str);
	return ((int)res);
}
