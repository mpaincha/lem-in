/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:17:34 by mpaincha          #+#    #+#             */
/*   Updated: 2016/06/08 11:17:37 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		empty(t_anthill *anthill, int id_nxt)
{
	t_elem	*tmp;

	tmp = anthill->lst_rooms->head;
	while (tmp != NULL)
	{
		if (ROOM(tmp)->index == id_nxt)
		{
			if (ROOM(tmp)->nb_ant == 0)
				return (1);
			return (0);
		}
		tmp = tmp->next;
	}
	return (-1);
}

void	update_room(t_anthill *anthill, int r_less, int r_up)
{
	t_elem	*tmp;

	tmp = anthill->lst_rooms->head;
	while (tmp != NULL)
	{
		if (ROOM(tmp)->index == r_less)
			ROOM(tmp)->nb_ant -= 1;
		else if (ROOM(tmp)->index == r_up)
			ROOM(tmp)->nb_ant += 1;
		tmp = tmp->next;
	}
}

t_elem	*elem_end(t_anthill *anthill, int id)
{
	t_elem	*tmp;

	tmp = anthill->lst_rooms->head;
	while (tmp != NULL)
	{
		if (ROOM(tmp)->index == id)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	fill_start(t_anthill *anthill, int num_ant, int id_room)
{
	t_elem	*tmp;

	tmp = anthill->lst_rooms->head;
	while (tmp != NULL)
	{
		if (ROOM(tmp)->index == id_room)
			ROOM(tmp)->nb_ant = num_ant;
		tmp = tmp->next;
	}
}

void	move_ant(t_anthill *anthill, t_dbllist **opti_path)
{
	int		nb_ant;
	int		num_ant;
	t_elem	*end;
	int		id_end;
	int		id_start;

	nb_ant = anthill->nb_ant;
	num_ant = 1;
	id_end = recup_idx(anthill->lst_rooms, anthill->end);
	id_start = recup_idx(anthill->lst_rooms, anthill->start);
	if ((end = elem_end(anthill, id_end)) == NULL)
		return ;
	ini_lstant(&anthill->lst_ant, nb_ant, id_start);
	fill_start(anthill, nb_ant, id_start);
	lead_ant(anthill, opti_path, end);
}
