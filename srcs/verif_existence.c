/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_existence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:37:43 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/07 11:37:44 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		name_exist(t_dbllist *lst_rooms, char *name)
{
	t_elem	*tmp;

	tmp = lst_rooms->head;
	while (tmp != NULL)
	{
		if (ft_strequ(name, ROOM(tmp)->name))
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
}

int		pos_taking(t_dbllist *lst_rooms, t_room room)
{
	t_elem	*tmp;

	tmp = lst_rooms->head;
	while (tmp != NULL)
	{
		if (room.coord_x == ROOM(tmp)->coord_x
			&& room.coord_y == ROOM(tmp)->coord_y)
			return (0);
		else
			tmp = tmp->next;
	}
	return (1);
}

int		verif_exist(t_dbllist *lst_rooms, t_room room)
{
	if (name_exist(lst_rooms, room.name) == 1)
		return (0);
	if (!(pos_taking(lst_rooms, room)))
		return (0);
	return (1);
}
