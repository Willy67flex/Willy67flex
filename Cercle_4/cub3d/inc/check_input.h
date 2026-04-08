/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:29:03 by whollebe          #+#    #+#             */
/*   Updated: 2026/04/08 13:22:37 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_INPUT_H
# define CHECK_INPUT_H

typedef struct s_game	t_game;
typedef struct s_ray	t_ray;
typedef struct s_imgb	t_imgb;
//check input
void	check_input(char *str, t_game *game, int argc);
void	check_syntax(char *str, t_game *game);
void	check_file(t_game *game, char *str);
void	set_vect_plane(t_game *game, double x, double y);
void	set_vect_dir(t_game *game, double x, double y);
//check input utils
void	msg_error(char *msg);
int		is_empty_line(char *line);
void	clean_newline(char *str);
char	*extract_path(char *line, int skip);
void	player_init(t_game *game, int dir, int x, int y);
//check input utils1
int		get_rgb(int r, int g, int b);
int		check_texture_exists(char *path);
int		count_char(char *str, char c);
int		char_table_len(char **str);
int		is_valid_number_format(char *str);
//check input utils2
void	set_player_setting(t_game *game, int dir, int x, int y);
void	scan_arg_map(t_game *game, int i, int j);
int		atocolor(char **str, t_game *game, int flag);
char	get_val(t_game *game, int y, int x);
int		is_playable_space(char c);
//check file
int		map_description(char *line, t_game *game, int fd);
int		check_map_description(t_game *game, char *str);
void	fill_map(t_game *game, char *str, int start);
//check file utils
int		assign_param(char *line, char *id, char **param);
int		check_param(char *line, t_game *game);
void	skipping_lines(int start, int fd);
void	handle_empty_map_line(t_game *game, char *line, int fd);
//scan map
void	scan_map(t_game *game);
void	scan_description(t_game *game);
int		check_description_color(char *color, t_game *game, int flag);
int		check_surrounded(t_game *game);
void	xpm_to_image(t_game *game, t_imgb *tex, char *path);

#endif
