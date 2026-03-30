/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:10:36 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/27 13:28:23 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

void	run_game(t_game	*game);
int		render_frame(t_game *game);
int		close_window(t_game *game);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		key_handler(int keycode, t_game *game);

#endif