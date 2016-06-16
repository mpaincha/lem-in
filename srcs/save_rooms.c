/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 09:42:04 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/07 09:42:05 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		data_len(char *line)
{
	int		i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	return (i);
}

int		save_startend(t_room *room, t_anthill *anthill)
{
	if (room->type == 1)
	{
		if (anthill->start)
			return (0);
		anthill->start = ft_strdup(room->name);
	}
	else if (room->type == 2)
	{
		if (anthill->end)
			return (0);
		anthill->end = ft_strdup(room->name);
	}
	return (1);
}

int		save_room(int *type_room, char *line, t_anthill *anthill)
{
	t_room		room;
	static	int	idx = 0;

	ini_room(&room, line, type_room, idx);
	if (room.type == 1 || room.type == 2)
	{
		if (!(save_startend(&room, anthill)))
		{
			free(room.name);
			return (0);
		}
	}
	if (!(verif_exist(anthill->lst_rooms, room)))
	{
		free(room.name);
		return (0);
	}
	ft_lstdbladd_head(anthill->lst_rooms, &room, sizeof(t_room));
	*type_room = 0;
	idx++;
	return (1);
}
