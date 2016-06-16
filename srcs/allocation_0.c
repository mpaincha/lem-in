/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:44:03 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/11 16:44:04 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_dbllist	*dup_lst(t_dbllist *lst)
{
	t_dbllist	*dup;
	t_elem		*tmp;

	dup = NULL;
	tmp = NULL;
	if (lst->length == 0)
		return (lst);
	tmp = lst->head;
	dup = ft_lstdblnew();
	while (tmp != NULL)
	{
		ft_lstdbladd_tail(dup, tmp->content, sizeof(int));
		tmp = tmp->next;
	}
	return (dup);
}

int			nb_link(t_anthill *anthill, t_dbllist **tb_path)
{
	int		nb;
	int		id;

	nb = 0;
	id = 0;
	while (tb_path[id] != NULL)
	{
		if (*((int *)(tb_path[id]->tail->content))
			== recup_idx(anthill->lst_rooms, anthill->end))
			nb++;
		id++;
	}
	return (nb);
}

t_dbllist	**tb_path_reduce(t_anthill *anthill, t_dbllist **tb_path)
{
	t_dbllist	**new_tb;
	int			i;
	int			id;

	i = 0;
	id = 0;
	if ((new_tb = (t_dbllist **)malloc(sizeof(t_dbllist *) *
		nb_link(anthill, tb_path) + 1)) == NULL)
		return (NULL);
	while (tb_path[id] != NULL)
	{
		if (*((int *)(tb_path[id]->tail->content))
			== recup_idx(anthill->lst_rooms, anthill->end))
			new_tb[i++] = tb_path[id];
		else
			ft_lstdbldel(&tb_path[id]);
		id++;
	}
	new_tb[i] = NULL;
	free(tb_path);
	return (new_tb);
}
