/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:44:03 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/11 16:44:04 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		finish_tb_path(t_dbllist ***tb_path)
{
	new_path(tb_path);
}

t_dbllist	**ft_realloc_tb_path(t_dbllist **tb_path)
{
	t_dbllist	**new_tb;
	int			i;
	static int	size_tb = 10;

	new_tb = (t_dbllist **)malloc(sizeof(t_dbllist *) * (size_tb * 2));
	if (new_tb == NULL)
		return (NULL);
	i = 0;
	while (tb_path[i] != NULL)
	{
		new_tb[i] = tb_path[i];
		i++;
	}
	new_tb[i] = NULL;
	new_tb[i + 1] = NULL;
	size_tb *= 2;
	free(tb_path);
	tb_path = NULL;
	return (new_tb);
}

int			new_path(t_dbllist ***tb_path)
{
	static	int		j = 10;
	int				i;

	i = 0;
	while ((*tb_path)[i] != NULL)
		i++;
	if (i == (j - 2))
	{
		(*tb_path) = ft_realloc_tb_path(*tb_path);
		j = j * 2;
	}
	(*tb_path)[i] = NULL;
	return (i);
}
