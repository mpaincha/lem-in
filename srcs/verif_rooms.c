/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 09:41:43 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/07 09:41:45 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_name(char *data)
{
	int		i;

	i = 0;
	if (data[0] == 'L' || data[0] == '#')
		return (0);
	if (ft_strlen(data) == 0)
		return (0);
	return (1);
}

int		check_coord(char *data)
{
	int		i;

	i = 0;
	while (data[i] != '\0')
	{
		if (!(ft_isdigit(data[i])))
			return (0);
		i++;
	}
	if (!(verif_limits(data)))
		return (0);
	return (1);
}

int		check_nb_data(char **info_room)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (info_room[i] != '\0')
	{
		i++;
		count++;
	}
	if (count != 3)
		return (0);
	return (1);
}

int		is_room(char *line)
{
	char	**info_room;

	info_room = NULL;
	if (!(ft_strchr(line, ' ')) || nb_space(line) != 1)
		return (0);
	info_room = ft_strsplit(line, ' ');
	if (!(check_nb_data(info_room)))
	{
		free_split(info_room);
		return (0);
	}
	if (!(check_name(info_room[0])))
	{
		free_split(info_room);
		return (0);
	}
	if (!(check_coord(info_room[1])) || !(check_coord(info_room[2])))
	{
		free_split(info_room);
		return (0);
	}
	free_split(info_room);
	return (1);
}
