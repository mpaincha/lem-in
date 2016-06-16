/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_comments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 12:21:16 by mpaincha          #+#    #+#             */
/*   Updated: 2016/04/05 12:21:17 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	room_type(char *scom, int *type_room)
{
	if (ft_strequ(scom, "start") == 1)
		*type_room = 1;
	else if (ft_strequ(scom, "end") == 1)
		*type_room = 2;
}

int		already_define(char *scom, t_anthill *anthill, int *type_room)
{
	room_type(scom, type_room);
	if ((anthill->start && *type_room == 1)
		|| (anthill->end && *type_room == 2))
		return (0);
	else
		return (1);
}

int		recover_scom(char *line, t_anthill *anthill, int *type_room)
{
	int		i;
	int		j;
	char	*scom;

	i = 2;
	j = 0;
	scom = NULL;
	if (line[2])
	{
		scom = (char *)malloc(sizeof(char) * ft_strlen(line) - 2);
		if (scom == NULL)
			return (0);
		while (line[i] != '\0')
			scom[j++] = line[i++];
		scom[j] = '\0';
	}
	else
		return (0);
	if (!(already_define(scom, anthill, type_room)))
	{
		ft_strdel(&scom);
		return (-1);
	}
	ft_strdel(&scom);
	return (1);
}

int		comment(char *line, t_anthill *anthill, int *type_room)
{
	if (recover_scom(line, anthill, type_room) == -1)
		return (-1);
	return (1);
}
