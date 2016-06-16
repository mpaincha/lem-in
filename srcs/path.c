/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 14:24:51 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/14 14:24:55 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		crossing(t_anthill *anthill, t_path *paths, int id1, int id2)
{
	t_elem	*tmp1;
	t_elem	*tmp2;
	int		start;
	int		end;

	start = recup_idx(anthill->lst_rooms, anthill->start);
	end = recup_idx(anthill->lst_rooms, anthill->end);
	tmp1 = paths->tb_path[id1]->head->next;
	tmp2 = paths->tb_path[id2]->head->next;
	while (tmp1 != NULL)
	{
		if ((*((int *)tmp1->content)) != start
			&& (*((int *)tmp1->content)) != end)
		{
			while (tmp2 != NULL)
			{
				if ((*((int *)tmp2->content)) == (*((int *)tmp1->content)))
					return (1);
				tmp2 = tmp2->next;
			}
		}
		tmp1 = tmp1->next;
		tmp2 = paths->tb_path[id2]->head->next;
	}
	return (0);
}

void	junction_matrix(t_anthill *anthill, t_path *paths)
{
	int		nb_path;

	nb_path = nb_link(anthill, paths->tb_path);
	ini_matrix(nb_path, &paths->matrix);
	fill_matrix(anthill, nb_path, paths);
}

void	fill_matrix(t_anthill *anthill, int nb_path, t_path *paths)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nb_path)
	{
		while (j < nb_path)
		{
			if (i == j)
				paths->matrix[i][j] = 0;
			else if (!(crossing(anthill, paths, i, j)))
			{
				paths->matrix[i][j] = paths->tb_path[i]->length
				+ paths->tb_path[j]->length;
			}
			else
				paths->matrix[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}
