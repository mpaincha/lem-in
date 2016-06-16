/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_path_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 15:01:34 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/15 15:01:35 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		opti_counter(t_dbllist *match_paths)
{
	t_elem	*tmp;
	int		nb;

	tmp = match_paths->head;
	nb = 0;
	while (tmp != NULL)
	{
		nb++;
		tmp = tmp->next;
	}
	return (nb);
}

void	just_opti_path(t_anthill *anthill, t_path *paths,
		t_dbllist ***opti_path)
{
	int		nb_opti;
	int		i;
	t_elem	*tmp;

	(void)anthill;
	(void)opti_path;
	nb_opti = opti_counter(paths->match_paths[0]);
	i = 0;
	tmp = paths->match_paths[0]->head;
	(*opti_path) = (t_dbllist **)malloc(sizeof(t_dbllist *) * (nb_opti + 1));
	if ((*opti_path) == NULL)
		return ;
	(*opti_path)[nb_opti] = NULL;
	while (i < nb_opti && tmp != NULL)
	{
		(*opti_path)[i] = paths->tb_path[(*((int *)tmp->content))];
		i++;
		tmp = tmp->next;
	}
}
