/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 13:58:10 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/11 13:58:12 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		resolution(t_anthill *anthill, t_path *paths, t_dbllist ***opti_path)
{
	paths->tb_path = (t_dbllist **)malloc(sizeof(t_dbllist *) * 10);
	if (paths->tb_path == NULL)
		return (-1);
	ini_path(&paths->tb_path, recup_idx(anthill->lst_rooms, anthill->start));
	find_path(anthill, &paths->tb_path, 0);
	finish_tb_path(&paths->tb_path);
	paths->tb_path = tb_path_reduce(anthill, paths->tb_path);
	if (paths->tb_path[0] == NULL)
	{
		del_tab_lst(paths->tb_path);
		paths->tb_path = NULL;
		return (-1);
	}
	junction_matrix(anthill, paths);
	deduce_opti_path(anthill, paths, opti_path);
	anthill->lst_ant = ft_lstdblnew();
	move_ant(anthill, *opti_path);
	del_tab_lst(paths->tb_path);
	paths->tb_path = NULL;
	return (1);
}
