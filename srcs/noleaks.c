/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noleaks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 12:15:32 by mpaincha          #+#    #+#             */
/*   Updated: 2016/06/10 12:15:38 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_split(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_lst_ant(t_anthill *anthill)
{
	t_elem	*tmp;

	tmp = anthill->lst_ant->head;
	while (tmp != NULL)
	{
		free(tmp->content);
		tmp->content = NULL;
		free(tmp);
		tmp = tmp->next;
	}
	anthill->lst_ant->tail = NULL;
	anthill->lst_ant->head = NULL;
}

void	free_lst_rooms(t_anthill *anthill)
{
	t_elem	*tmp;

	tmp = anthill->lst_rooms->head;
	while (tmp != NULL)
	{
		ft_strdel(&(ROOM(tmp)->name));
		free(tmp->content);
		tmp->content = NULL;
		free(tmp);
		tmp = tmp->next;
	}
	anthill->lst_rooms->tail = NULL;
	anthill->lst_rooms->head = NULL;
}

void	free_matrix(int nb, int **matrix)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nb)
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
}

void	del_tab_lst(t_dbllist **list)
{
	int			i;

	i = 0;
	while (list[i] != NULL)
	{
		ft_lstdbldel(&list[i]);
		i++;
	}
	free(list);
}
