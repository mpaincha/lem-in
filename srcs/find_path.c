/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:38 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/11 15:13:40 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		previous_room(t_dbllist **tb_path, int id, int index)
{
	t_elem	*tmp;

	tmp = tb_path[id]->head;
	while (tmp != NULL)
	{
		if ((*(int *)(tmp->content)) == index)
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
}

int		find_alternativ(t_anthill *anthill, t_dbllist *altvs,
		t_dbllist **tb_path, int id)
{
	int		i;
	int		nb;
	int		prev;
	int		id_room;

	i = 0;
	nb = 0;
	prev = -1;
	id_room = (*(int *)tb_path[id]->tail->content);
	if (tb_path[id]->length != 0)
		prev = *((int *)(tb_path[id]->tail->content));
	while (i < (int)(anthill->lst_rooms->length))
	{
		if (i != id_room && anthill->tubes[id_room][i] != 0)
		{
			if (!(previous_room(tb_path, id, i)))
			{
				ft_lstdbladd_head(altvs, &i, sizeof(int));
				nb++;
			}
		}
		i++;
	}
	return (nb);
}

int		lead(t_anthill *anthill, t_dbllist ***tb_path, int id, t_dbllist *altvs)
{
	int		nb_alt;
	t_elem	*tmp;
	int		j;

	j = 0;
	nb_alt = altvs->length;
	tmp = altvs->head;
	if (nb_alt == 1)
		ft_lstdbladd_tail((*tb_path)[id], tmp->content, sizeof(int));
	else
	{
		while (nb_alt > 1)
		{
			j = new_path(tb_path);
			(*tb_path)[j] = dup_lst((*tb_path)[id]);
			(*tb_path)[j + 1] = NULL;
			ft_lstdbladd_tail((*tb_path)[j], tmp->content, sizeof(int));
			find_path(anthill, tb_path, j);
			nb_alt--;
			tmp = tmp->next;
		}
		ft_lstdbladd_tail((*tb_path)[id], tmp->content, sizeof(int));
		find_path(anthill, tb_path, id);
	}
	return (1);
}

int		find_path(t_anthill *anthill, t_dbllist ***tb_path, int id)
{
	t_dbllist	*altvs;
	int			id_ed;
	t_elem		*tmp;

	id_ed = recup_idx(anthill->lst_rooms, anthill->end);
	tmp = (*tb_path)[id]->tail;
	while (tmp != NULL && (*((int *)tmp->content)) != id_ed)
	{
		altvs = ft_lstdblnew();
		if (find_alternativ(anthill, altvs, (*tb_path), id))
		{
			lead(anthill, tb_path, id, altvs);
			ft_lstdbldel(&altvs);
			if ((*((int *)(tmp)->content)) == id_ed)
				return (1);
			if (find_path(anthill, tb_path, id) == 1)
				return (1);
		}
		else
		{
			ft_lstdbldel(&altvs);
			return (0);
		}
	}
	return (1);
}
