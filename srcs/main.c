/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:22:19 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/31 11:22:20 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	t_anthill	anthill;
	t_path		paths;
	t_dbllist	**opti_path;

	ini_tanthill(&anthill);
	ini_path_struct(&paths);
	opti_path = NULL;
	if (!(parsing(&anthill)))
	{
		ft_printf("ERROR\n");
		return (-1);
	}
	if (resolution(&anthill, &paths, &opti_path) == -1)
	{
		ft_printf("ERROR\n");
		return (-1);
	}
	return (1);
}
