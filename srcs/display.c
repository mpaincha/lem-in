/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 11:55:18 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/07 11:55:20 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*give_room_name(t_dbllist *lst_rooms, int index)
{
	t_elem	*tmp;

	tmp = lst_rooms->head;
	while (tmp != NULL)
	{
		if (index == ROOM(tmp)->index)
			return (ft_strdup(ROOM(tmp)->name));
		tmp = tmp->next;
	}
	return (NULL);
}

void	show_move(t_anthill *anthill)
{
	t_elem	*tmp;
	char	*name;
	int		space;

	tmp = anthill->lst_ant->head;
	name = NULL;
	space = 0;
	while (tmp != NULL)
	{
		if (ANT(tmp)->moved == 1)
		{
			if (space == 1)
				ft_printf(" ");
			name = give_room_name(anthill->lst_rooms, ANT(tmp)->room);
			ft_printf("L%d-%s", ANT(tmp)->id, name);
			ft_strdel(&name);
			space = 1;
		}
		tmp = tmp->next;
	}
}
