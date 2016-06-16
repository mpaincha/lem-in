/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_path_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 15:01:34 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/15 15:01:35 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		path_number(t_dbllist **tb_path)
{
	int		id;

	id = 0;
	while (tb_path[id] != NULL)
		id++;
	return (id);
}

int		min_path(t_dbllist **tb_path)
{
	int		id;
	int		nb_path;
	int		min;

	id = 0;
	nb_path = path_number(tb_path);
	min = 0;
	while (nb_path > 0)
	{
		if (tb_path[id]->length < tb_path[min]->length)
			min = id;
		id++;
		nb_path--;
	}
	return (min);
}

void	maj_matrix(int **matrix, int nb_path, int current, int min)
{
	int		i;

	i = 0;
	matrix[current][min] = 0;
	matrix[min][current] = 0;
	while (nb_path > i)
	{
		if (matrix[current][i] == 0)
		{
			matrix[min][i] = 0;
			matrix[i][min] = 0;
		}
		i++;
	}
}

int		next_min(int **matrix, int nb_path, t_path *paths)
{
	int		current;
	int		i;
	int		min;

	current = (*(int *)paths->match_paths[0]->tail->content);
	i = 0;
	min = -1;
	while (nb_path > i)
	{
		if (matrix[current][i] != 0)
		{
			if (min == -1)
				min = i;
			else if (paths->tb_path[i]->length < paths->tb_path[min]->length)
				min = i;
		}
		i++;
	}
	if (min != -1)
		maj_matrix(matrix, nb_path, current, min);
	return (min);
}

void	deduce_opti_path(t_anthill *anthill, t_path *paths,
		t_dbllist ***opti_path)
{
	int		nb_path;
	int		min;
	int		size;

	nb_path = path_number(paths->tb_path);
	min = min_path(paths->tb_path);
	size = nb_path + 1;
	paths->match_paths = (t_dbllist **)malloc(sizeof(t_dbllist *) * size);
	if (paths->match_paths == NULL)
		return ;
	paths->match_paths[0] = ft_lstdblnew();
	paths->match_paths[1] = NULL;
	ft_lstdbladd_tail(paths->match_paths[0], &min, sizeof(int));
	while (1)
	{
		min = next_min(paths->matrix, nb_path, paths);
		if (min != -1)
			ft_lstdbladd_tail(paths->match_paths[0], &min, sizeof(int));
		else
			break ;
	}
	just_opti_path(anthill, paths, opti_path);
}
