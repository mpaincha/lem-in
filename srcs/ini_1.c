/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:37:03 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/06 15:37:05 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ini_path(t_dbllist ***path, int id_s)
{
	(*path)[0] = ft_lstdblnew();
	ft_lstdbladd_head((*path)[0], &id_s, sizeof(int));
	(*path)[1] = NULL;
}

void	ini_matrix(int nb, int ***matrix)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	*matrix = (int **)malloc(sizeof(int *) * nb);
	if (*matrix == NULL)
		return ;
	while (i < nb)
	{
		(*matrix)[i] = (int *)malloc(sizeof(int) * nb);
		if ((*matrix)[i] == NULL)
			return ;
		while (j < nb)
		{
			(*matrix)[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
}

void	ini_matrix_sum(int nb, int ***matrix)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	*matrix = (int **)malloc(sizeof(int *) * nb);
	if (*matrix == NULL)
		return ;
	while (i < nb)
	{
		(*matrix)[i] = (int *)malloc(sizeof(int) * 3);
		if ((*matrix)[i] == NULL)
			return ;
		while (j < 3)
		{
			(*matrix)[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
}

void	ini_to_verif(int **matrix, int k, int nb_path, t_dbllist *to_verif)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nb_path)
	{
		if (matrix[k][i] != 0)
			ft_lstdbladd_head(to_verif, &i, sizeof(int));
		i++;
	}
}

void	ini_ext(t_anthill *anthill, t_ext *ext)
{
	ext->start = recup_idx(anthill->lst_rooms, anthill->start);
	ext->end = recup_idx(anthill->lst_rooms, anthill->end);
}
