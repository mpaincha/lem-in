/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:17:34 by mpaincha          #+#    #+#             */
/*   Updated: 2016/06/08 11:17:37 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	move(t_anthill *anthill, t_elem *tmp, int id_nxt, int id)
{
	update_room(anthill, ANT(tmp)->room, id_nxt);
	ANT(tmp)->room = id_nxt;
	ANT(tmp)->moved = 1;
	ANT(tmp)->path = id;
}

int		next_room(t_anthill *anthill, t_elem *tmp_ant, t_dbllist **opti_path)
{
	t_elem	*tmp;

	(void)anthill;
	tmp = opti_path[ANT(tmp_ant)->path]->head;
	while (tmp != NULL)
	{
		if (ANT(tmp_ant)->room == (*(int *)tmp->content))
		{
			if (tmp->next)
				return ((*(int *)tmp->next->content));
			else
				return (-1);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	lead_from_start(t_anthill *anthill, t_dbllist **opti_path, t_var *var,
		t_elem *tmp_ant)
{
	int		id_end;

	id_end = recup_idx(anthill->lst_rooms, anthill->end);
	var->id = 0;
	while (opti_path[var->id] != NULL)
	{
		var->id_nxt = (*(int *)opti_path[var->id]->head->next->content);
		if (empty(anthill, var->id_nxt) || var->id_nxt == id_end)
		{
			move(anthill, tmp_ant, var->id_nxt, var->id);
			var->moved = 1;
			break ;
		}
		var->id++;
	}
}

void	lead_from_room(t_anthill *anthill, t_dbllist **opti_path, t_var *var,
		t_elem *tmp_ant)
{
	var->id_nxt = next_room(anthill, tmp_ant, opti_path);
	move(anthill, tmp_ant, var->id_nxt, ANT(tmp_ant)->path);
	var->moved = 1;
}

void	lead_ant(t_anthill *anthill, t_dbllist **opti_path, t_elem *end)
{
	t_elem	*tmp_ant;
	t_var	var;
	t_ext	ext;

	tmp_ant = NULL;
	ini_var(&var);
	ini_ext(anthill, &ext);
	while (ROOM(end)->nb_ant != anthill->nb_ant)
	{
		ft_printf("\n");
		tmp_ant = anthill->lst_ant->head;
		while (tmp_ant != NULL)
		{
			var.moved = 0;
			if (ANT(tmp_ant)->room == ext.start)
				lead_from_start(anthill, opti_path, &var, tmp_ant);
			else if (ANT(tmp_ant)->room != ext.end)
				lead_from_room(anthill, opti_path, &var, tmp_ant);
			if (var.moved == 0)
				ANT(tmp_ant)->moved = 0;
			tmp_ant = tmp_ant->next;
		}
		show_move(anthill);
	}
	ft_printf("\n");
}
