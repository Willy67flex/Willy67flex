/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:29:03 by whollebe          #+#    #+#             */
/*   Updated: 2026/03/27 13:22:27 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_INPUT_H
# define CHECK_INPUT_H

//check input
void	check_input(char *str, t_game *game, int argc);
void	check_syntax(char *str);
void	check_file(t_game *game, char *str);
//check input utils
void	msg_error(char *msg);
int		is_empty_line(char *line);
void	clean_newline(char *str);
char	*extract_path(char *line, int skip);
//check input utils1
int		get_rgb(int r, int g, int b);
int		check_texture_exists(char *path);
int		count_char(char *str, char c);
int		char_table_len(char **str);
int		is_valid_number_format(char *str);
//check input utils2
void	set_player_setting(t_game *game, int dir, int x, int y);
void	scan_arg_map(t_game *game, int i, int  j);
int		atocolor(char **str, t_game *game, int flag);
char	get_val(t_game *game, int y, int x);
int		is_playable_space(char c);
//check file
int		assign_param(t_game *game, char *line, char *id, char **param);
int		map_description(char *line, t_game *game);
int		check_map_description(t_game *game, char *str);
void	fill_map(t_game *game, char *str, int start);
//scan map
void	scan_map(t_game *game);
void	scan_description(t_game *game);
int		check_description_color(char *color, t_game *game, int flag);
int		check_surrounded(t_game *game);
void	xpm_to_image(t_game *game, t_imgb *tex, char *path);

#endif
