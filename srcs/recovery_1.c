/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:53:23 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/31 14:53:25 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			verif_digit(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int			nb_ant(char *line, t_anthill *anthill, int *recup_ant)
{
	if (!(verif_limits(line)))
		return (0);
	else if (verif_digit(line))
	{
		anthill->nb_ant = ft_atoi(line);
		*recup_ant = 1;
		return (1);
	}
	return (0);
}

static	int	check_line(char *line, t_anthill *anthill, int *type_room)
{
	static	int	recup_ant = 0;
	static	int	less_one = 0;

	if (line)
	{
		if (line[0] == '#' && line[1] != '#')
			return (1);
		else if (recup_ant == 0)
			return (nb_ant(line, anthill, &recup_ant) == 0) ? -1 : 1;
		else if (line[0] == '#' && line[1] == '#')
			comment(line, anthill, type_room);
		else if ((*type_room == 1 || *type_room == 2) && !(is_room(line)))
			return (-1);
		else if (is_room(line) && less_one == 0)
			return (save_room(type_room, line, anthill) == 0) ? -1 : 1;
		else if (is_tube(anthill, line))
			return (save_tube(anthill, line, &less_one) == 0) ? -1 : 1;
		else if (is_tube(anthill, line) == 0 && less_one == 1)
			return (2);
		else
			return (-1);
	}
	else
		return (-1);
	return (1);
}

int			parsing(t_anthill *anthill)
{
	char		*line;
	int			ret;
	int			type_room;

	line = NULL;
	ret = 0;
	type_room = 0;
	while (get_next_line(0, &line))
	{
		if ((ret = check_line(line, anthill, &type_room)) == -1)
		{
			ft_strdel(&line);
			return (0);
		}
		if (ret == 2)
		{
			ft_strdel(&line);
			break ;
		}
		ft_putendl(line);
		ft_strdel(&line);
	}
	if (!(is_conforme(anthill)))
		return (0);
	return (1);
}
