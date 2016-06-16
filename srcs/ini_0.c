/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:37:03 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/06 15:37:05 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ini_var(t_var *var)
{
	var->id = 0;
	var->id_nxt = -1;
	var->moved = 0;
}

void	ini_lstant(t_dbllist **lst_ant, int nb_ant, int id_start)
{
	t_ant	ant;

	ant.id = 0;
	ant.room = -1;
	ant.moved = 0;
	ant.path = -1;
	while (nb_ant > 0)
	{
		ant.id = nb_ant;
		ant.room = id_start;
		ft_lstdbladd_head(*lst_ant, &ant, sizeof(t_ant));
		ant.id = -1;
		ant.room = -1;
		nb_ant--;
	}
}

void	ini_tanthill(t_anthill *anthill)
{
	anthill->nb_ant = 0;
	anthill->start = NULL;
	anthill->end = NULL;
	anthill->lst_rooms = ft_lstdblnew();
	anthill->lst_ant = NULL;
	anthill->tubes = NULL;
}

void	ini_room(t_room *room, const char *line, int *type_room, int idx)
{
	char		**info_room;

	info_room = ft_strsplit(line, ' ');
	room->index = idx;
	room->name = ft_strdup(info_room[0]);
	room->type = *type_room;
	room->coord_x = ft_atoi(info_room[1]);
	room->coord_y = ft_atoi(info_room[2]);
	room->nb_ant = 0;
	free_split(info_room);
}

void	ini_path_struct(t_path *paths)
{
	paths->tb_path = NULL;
	paths->match_paths = NULL;
	paths->matrix = NULL;
}
