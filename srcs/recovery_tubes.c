/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_tubes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 12:21:26 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/05 12:21:27 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		recup_idx(t_dbllist *lst_rooms, char *name)
{
	t_elem	*tmp;
	int		i;

	i = 0;
	tmp = lst_rooms->head;
	while (tmp != NULL)
	{
		if (ft_strequ(name, ROOM(tmp)->name))
			return (ROOM(tmp)->index);
		else
			tmp = tmp->next;
		i++;
	}
	return (-1);
}

int		save_tube(t_anthill *anthill, char *line, int *less_one)
{
	char	**rooms;
	int		idx1;
	int		idx2;

	rooms = ft_strsplit(line, '-');
	idx1 = recup_idx(anthill->lst_rooms, rooms[0]);
	idx2 = recup_idx(anthill->lst_rooms, rooms[1]);
	*less_one = 1;
	if (idx1 == -1 || idx2 == -1)
		return (0);
	if (anthill->tubes == NULL)
		ini_matrix(anthill->lst_rooms->length, &anthill->tubes);
	if (idx1 != idx2)
	{
		anthill->tubes[idx1][idx2] = 1;
		anthill->tubes[idx2][idx1] = 1;
	}
	else
		anthill->tubes[idx1][idx2] = 0;
	free_split(rooms);
	return (1);
}

int		verif_nb_tube(char **rooms)
{
	int		i;

	i = 0;
	while (rooms[i] != '\0')
		i++;
	if (i != 2)
		return (0);
	return (1);
}

int		is_tube(t_anthill *anthill, char *line)
{
	int		i;
	int		count;
	char	**rooms;

	i = 0;
	count = 0;
	if (nb_dash(line) != 1)
		return (0);
	rooms = ft_strsplit(line, '-');
	if (!(verif_nb_tube(rooms)) || ft_strcmp(rooms[0], rooms[1]) == 0)
	{
		free_split(rooms);
		return (0);
	}
	if (name_exist(anthill->lst_rooms, rooms[0]) != 1
		|| name_exist(anthill->lst_rooms, rooms[1]) != 1)
	{
		free_split(rooms);
		return (0);
	}
	free_split(rooms);
	return (1);
}
