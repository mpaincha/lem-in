/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 09:41:34 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/07 09:41:35 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		verif_limits(char *av)
{
	if (INT_MIN > ft_atoi_intmax(av) || ft_atoi_intmax(av) > INT_MAX)
		return (0);
	return (1);
}

int		start_end_ok(t_anthill *anthill)
{
	if (anthill->start == NULL || anthill->end == NULL)
		return (0);
	return (1);
}

int		is_conforme(t_anthill *anthill)
{
	if (!(start_end_ok(anthill)))
		return (0);
	if (!(anthill->tubes))
		return (0);
	return (1);
}

int		nb_space(char *line)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			space++;
		i++;
	}
	if (space != 2)
		return (0);
	return (1);
}

int		nb_dash(char *line)
{
	int		i;
	int		dash;

	i = 0;
	dash = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			dash++;
		i++;
	}
	if (dash != 1)
		return (0);
	return (1);
}
