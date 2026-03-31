/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:10:36 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/31 14:24:56 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

typedef struct s_game	t_game;
typedef struct s_ray	t_ray;
typedef struct s_imgb	t_imgb;
void	run_game(t_game	*game);
int		render_frame(t_game *game);
int		close_window(t_game *game);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		key_release(int keycode, t_game *game);
int		key_press(int keycode, t_game *game);
void	move_handler(t_game *game);

#endif