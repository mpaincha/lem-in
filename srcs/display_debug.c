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

void	show_lst_ant(t_dbllist *lst_ant)
{
	t_elem *tmp;

	tmp = lst_ant->head;
	ft_printf("Listes de fourmis :\n");
	while (tmp != NULL)
	{
		ft_printf("id : %d \n", ((t_ant *)(tmp->content))->id);
		ft_printf("room : %d\n", ((t_ant *)(tmp->content))->room);
		tmp = tmp->next;
	}
}

void	show_match_paths(t_dbllist *lst)
{
	t_elem	*tmp;

	tmp = lst->tail;
	ft_printf("Match paths :\n");
	while (tmp != NULL)
	{
		ft_printf("paths %d\n", (*((int *)tmp->content)));
		tmp = tmp->prev;
	}
	ft_printf("\n");
}

void	show_to_verif(t_dbllist *lst)
{
	t_elem	*tmp;

	tmp = lst->tail;
	while (tmp != NULL)
	{
		ft_printf("ID %d\n", (*((int *)tmp->content)));
		tmp = tmp->prev;
	}
}

void	show_tbpath(t_anthill *anthill, t_dbllist **tb_path)
{
	int	id;

	id = 0;
	ft_printf("Chemins intermediairesqq :\n");
	while (tb_path[id] != NULL)
	{
		show_path_name(anthill->lst_rooms, tb_path[id]);
		id++;
	}
}

void	show_path(t_anthill *anthill, t_path *paths)
{
	int	id;
	int	num;

	id = 0;
	num = 0;
	ft_printf("Les differents chemins sont :\n");
	while (paths->tb_path[id] != NULL)
	{
		ft_printf("%d  ", num);
		show_path_name(anthill->lst_rooms, paths->tb_path[id]);
		id++;
		num++;
	}
}

void	show_specific_path(t_anthill *anthill, t_path *paths, int to_show)
{
	int		id;

	id = 0;
	while (paths->tb_path[id] != NULL)
	{
		if (to_show == id)
			show_path_name(anthill->lst_rooms, paths->tb_path[id]);
		id++;
	}
}

void	show_opti_path(t_anthill *anthill, t_path *paths)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	(void)anthill;
	tmp  = paths->match_paths[0]->head;
	ft_printf("Les chemins optimaux sont :\n");
	while (tmp != NULL)
	{
		ft_printf("Numero : %d\n", (*(int *)tmp->content));
		show_specific_path(anthill, paths, (*(int *)tmp->content));
		tmp = tmp->next;
	}
}

void	show_lst_rooms(t_dbllist *lst)
{
	t_elem	*tmp;

	tmp = lst->tail;
	while (tmp != NULL)
	{
		ft_printf("\n==ROOM===\n");
		ft_printf("Name :%s\nType :%d\n", ROOM(tmp)->name, ROOM(tmp)->type);
		ft_printf("CoordX: %d\n", ROOM(tmp)->coord_x);
		ft_printf("CoordY : %d\n", ROOM(tmp)->coord_y);
		ft_printf("Index : %d\n", ROOM(tmp)->index);
		ft_printf("nb_ant : %d\n", ROOM(tmp)->nb_ant);
		tmp = tmp->prev;
	}
}

void	show_matrix(int nb, int **matrix)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nb)
	{
		while (j < nb)
		{
			if (j == (nb - 1))
				ft_printf("|%2d|\n", matrix[i][j]);
			else
				ft_printf("|%2d|", matrix[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
}

void	show_matrix_sum(int nb, int **matrix)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nb)
	{
		while (j < 3)
		{
			if (j == 2)
				ft_printf("|%2d|\n", matrix[i][j]);
			else
				ft_printf("|%2d|", matrix[i][j]);
			j++;
		}
		i++;
		j = 0;
	}
}

void	convert_room_name(t_dbllist *lst_rooms, int index, char **name)
{
	t_elem	*tmp;

	tmp = lst_rooms->head;
	while (tmp != NULL)
	{
		if (index == ROOM(tmp)->index)
		{
			*name = ft_strdup(ROOM(tmp)->name);
			return ;
		}
		tmp = tmp->next;
	}
}

void	show_altvs(t_anthill *anthill, t_dbllist *altvs)
{
	t_elem	*tmp;
	char	*name;

	tmp = altvs->tail;
	name = NULL;
	ft_printf("\nAlternatives : ");
	while (tmp != NULL)
	{
		convert_room_name(anthill->lst_rooms, (*(int *)(tmp->content)), &name);
		ft_printf("%s", name);
		if (tmp->prev != NULL)
			ft_printf(", ");
		tmp = tmp->prev;
	}
	ft_printf("\n");
}

void	show_path_idx(t_dbllist *path)
{
	t_elem	*tmp;
	char	*name;

	ft_printf("Path : ");
	tmp = NULL;
	name = NULL;
	if (path)
	{
		tmp = path->head;
		if (tmp != NULL)
		{
			ft_printf("%d", (*((int *)(tmp->content))));
			if (tmp->next != NULL)
				ft_printf(", ");
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
}

void	show_path_name(t_dbllist *lst_rooms, t_dbllist *path)
{
	t_elem	*tmp;
	char	*name;

	ft_printf("Path : ");
	tmp = NULL;
	name = NULL;
	if (path)
	{
		tmp = path->head;
		while (tmp != NULL)
		{
			convert_room_name(lst_rooms, (*((int *)tmp->content)), &name);
			ft_printf("%s", name);
			if (tmp->next != NULL)
				ft_printf(", ");
			free(name);
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
}
