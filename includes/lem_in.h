/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 14:54:19 by mpaincha          #+#    #+#             */
/*   Updated: 2016/03/31 14:54:21 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libftprintf/includes/ft_printf.h"

# define ROOM(X)			((t_room *)((X)->content))
# define ALT(X)				((t_alt *)((X)->content))
# define FDPATH(X)			((t_path *)((X)->content))
# define ANT(X)				((t_ant *)((X)->content))

/*
**********************  Structures  **********************
*/

typedef struct				s_anthill
{
	int						nb_ant;
	char					*start;
	char					*end;
	t_dbllist				*lst_rooms;
	t_dbllist				*lst_ant;
	int						**tubes;
}							t_anthill;

typedef	struct				s_room
{
	int						index;
	char					*name;
	int						type;
	int						coord_x;
	int						coord_y;
	int						nb_ant;
}							t_room;

typedef	struct				s_path
{
	t_dbllist				**tb_path;
	t_dbllist				**match_paths;
	int						**matrix;
}							t_path;

typedef	struct				s_ant
{
	int						id;
	int						room;
	int						moved;
	int						path;
}							t_ant;

typedef	struct				s_var
{
	int						id;
	int						id_nxt;
	int						moved;
}							t_var;

typedef	struct				s_ext
{
	int						start;
	int						end;
}							t_ext;

/*
*********************** Recovery ************************
*/

int							parsing(t_anthill *anthill);
int							nb_ant(char *line, t_anthill *anthill,
							int *recup_ant);
int							is_room(char *line);
int							save_room(int *type_room, char *line,
							t_anthill *anthill);
int							verif_syntax_room(char *line);
int							check_name(char *data);
int							check_coord(char *data);
int							verif_exist(t_dbllist *lst_rooms, t_room room);
int							name_exist(t_dbllist *lst_rooms, char *name);
int							pos_taking(t_dbllist *lst_rooms, t_room room);
int							comment(char *line, t_anthill *anthill,
							int *type_room);
int							recover_scom(char *line, t_anthill *anthill,
							int *type_room);
int							already_define(char *scom, t_anthill *anthill,
							int *type_room);
void						room_type(char *scom, int *type_room);
int							verif_nb_tube(char **rooms);
int							is_tube(t_anthill *anthill, char *line);
int							save_tube(t_anthill *anthill, char *line,
							int *less_one);
void						alloc_matrix_tubes(t_anthill *anthill);
int							recup_idx(t_dbllist *lst_rooms, char *name);
int							verif_limits(char *av);
int							verif_digit(char *line);
int							is_conforme(t_anthill *anthill);
int							start_end_ok(t_anthill *anthill);
int							nb_space(char *line);
int							nb_dash(char *line);

/*
*********************** Initialisation ********************
*/

void						ini_tanthill(t_anthill *anthill);
void						ini_room(t_room *room, const char *line,
							int *type_room, int idx);
void						ini_path(t_dbllist ***tb_path, int id_s);
void						ini_matrix(int nb, int ***matrix);
void						finish_tb_path(t_dbllist ***tb_path);
void						ini_path_struct(t_path *paths);
void						ini_matrix_sum(int nb, int ***matrix);
void						ini_to_verif(int **matrix, int k, int nb_path,
							t_dbllist *to_verif);
void						ini_var(t_var *var);
void						ini_ext(t_anthill *anthill, t_ext *ext);

/*
*********************** Algorithme ********************
*/

int							resolution(t_anthill *anthill, t_path *paths,
							t_dbllist ***opti_path);
int							find_path(t_anthill *anthill, t_dbllist ***tb_path,
							int id);
void						junction_matrix(t_anthill *anthill, t_path *paths);
void						fill_matrix(t_anthill *anthill, int nb_path,
							t_path *paths);
int							crossing(t_anthill *anthill, t_path *paths, int id1,
							int id2);
t_dbllist					**tb_path_reduce(t_anthill *anthill,
							t_dbllist **tb_path);
int							nb_link(t_anthill *anthill, t_dbllist **tb_path);
void						deduce_opti_path(t_anthill *anthill, t_path *paths,
							t_dbllist ***opti_path);
int							path_number(t_dbllist **tb_path);
void						sum_cross(int **matrix, int nb_path, int **sum);
void						check_match_paths(t_path *paths, int nb_path,
							int **sum);
int							smallest(t_path *paths, int to_comp, int tmp);
t_elem						*pos_to_del(int to_comp, t_dbllist *to_verif);
int							comp_in_matrix(int **matrix, int i, int j);
int							check_to_verif(t_dbllist *to_verif, t_path *paths,
							int id);

/*
*********************** Lst ********************
*/
t_dbllist					*dup_lst(t_dbllist *lst);
int							new_path(t_dbllist ***tb_path);
t_dbllist					**ft_realloc_tb_path(t_dbllist **tb_path);
void						del_tb_path_reduce(t_anthill *anthill,
							t_dbllist **tb_path);
void						just_opti_path(t_anthill *anthill, t_path *paths,
							t_dbllist ***opti_path);

/*
*********************** Ants moving ********************
*/

void						move_ant(t_anthill *anthill, t_dbllist **opti_path);
void						ini_lstant(t_dbllist **lst_ant, int nb_ant,
							int id_start);
void						fill_room(t_anthill *anthill, int num_ant,
							int id_room);
t_elem						*elem_end(t_anthill *anthill, int id);
void						lead_ant(t_anthill *anthill, t_dbllist **opti_path,
							t_elem *end);
int							empty(t_anthill *anthill, int id_nxt);
void						update_room(t_anthill *anthill, int r_less,
							int r_up);

/*
*********************** Display ********************
*/

void						convert_room_name(t_dbllist *lst_rooms, int index,
							char **name);
void						show_lst_ant(t_dbllist *lst_ant);
void						show_move(t_anthill *anthill);

/*
*********************** Display debug ********************
*/

void						show_lst_rooms(t_dbllist *lst);
void						show_altvs(t_anthill *anthill, t_dbllist *altvs);
void						show_path(t_anthill *anthill, t_path *paths);
void						show_path_name(t_dbllist *lst_rooms,
							t_dbllist *path);
void						show_path_idx(t_dbllist *path);
void						show_finding_path(t_dbllist *finding_path);
void						show_junction_matrix(int nb_path, int **matrix);
void						show_matrix(int nb, int **matrix);
void						show_matrix_sum(int nb, int **matrix);
void						show_to_verif(t_dbllist *lst);
void						show_match_paths(t_dbllist *lst);
void						show_opti_path(t_anthill *anthill, t_path *paths);
void						show_tbpath(t_anthill *anthill,
							t_dbllist **tb_path);

/*
*********************** No leaks  ********************
*/

void						free_split(char **str);
void						del_tab_lst(t_dbllist **list);

#endif
