/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:02:21 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/19 17:02:21 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct			s_xy
{
	int					x;
	int					y;
	struct s_xy			*next;
}						t_xy;

typedef struct			s_name
{
	char				*name;
	struct s_name		*next;
}						t_name;

typedef struct			s_lem
{
	int					peak_count;
	int					peak_added;
	int					links[10000][1000];
	int					updated_links[20000][1000];
	int					way_links[50][5000];
	int					codes[100000000][1];
	char				peaks[10000][400];
	int					ants;
	int					start;
	int					finish;
	int					set_start;
	int					set_finish;
	int					max_links;
	int					valid_count;
	int					cnt_read_ants;
	int					stack_walking;
	int					stack_added;
	int					round;
	int					check;
	int					memory_stack[20000];
	int					read_queue;
	int					final_count;
	int					final[1000][10000];
	int					pretend[2][4500];
	int					pretend_count;
	int					stack[1000000];
	int					stack_count;
	int					another_one[1000][1000];
	int					another_one_count;
	int					len_way[10000][2];
	int					ants_in_room[10000][1];
	int					count_start;
	int					count_end;
	int					passed[20000][1];
	int					passed_count;
	int					weight[20000][1];
	int					way[20000][1];
	int					weight_count;
	int					i_tunnel;
	int					links_count;
	int					bell_count;
	int					best_pretend;
	int					i_peak;
	int					add_stack;
}						t_lem;

void					ft_init_lem(t_lem *lem);
void					ft_max_links_needed(t_lem *lem);
int						ft_suurbali(t_lem *lem);
void					ft_write_result(t_lem *lem);
void					ft_init_ford(t_lem *lem);
int						bellman_ford(t_lem *lem);
void					ft_add_in_stack(t_lem *lem, int numb);
int						ft_memory_of_stack(t_lem *lem, int num);
void					divide_ways(t_lem *lem);
void					ft_free_lem(t_lem *lem, t_xy **xy, t_name **name);
void					ft_add_new_num_in_mass_weight(t_lem *lem, int i,
		int to_put);
void					ft_add_new_num_in_mass_weight_first(t_lem *lem, int i,
		int to_put);
int						ft_weight(int a, int b, t_lem *lem);
void					ft_init_ford2(t_lem *lem);
int						ft_way(t_lem *lem);
int						ft_way_first(t_lem *lem);
int						ft_check_ants(char *s, t_lem *lem);
char					*give_peak(char *line, t_lem *lem);
int						give_yx_peak(char *line, t_lem *lem);
int						give_tunnel(char *line, t_lem *lem, t_name **name);
int						bfs(t_lem *lem);
int						ft_check_valid_xy(t_xy **alst, t_xy *new, int y, int x);
int						ft_check_valid_name(t_name **alst, t_name *new);
int						ft_lenght(int *mass);
void					ft_collect_lenght(t_lem *lem);
int						ft_check_previous_step(t_lem *lem, int cnt);
void					going_on_links(t_lem *lem, int i);
void					ft_copy_links(t_lem *lem);
int						ft_add_in_final(t_lem *lem);
int						ft_look_weight_count(t_lem *lem);
int						ft_look_pretend_count(t_lem *lem);
void					ft_add_in_stack(t_lem *lem, int numb);
int						ft_read_tunnel(t_lem *lem, t_name **name, char *line);
int						ft_read_peak(t_lem *lem, t_xy **xy, t_name **name,
		char *line);
int						ft_read_end(t_lem *lem, char *line);
int						ft_read_start(t_lem *lem, char *line);
int						ft_reading_ants(t_lem *lem, char *line);
int						ft_give_code(char *line);
int						ft_read_std(int file, t_lem *lem, t_xy **xy,
		t_name **name);
int						ft_no_name(char *str, t_name **name);

#endif
