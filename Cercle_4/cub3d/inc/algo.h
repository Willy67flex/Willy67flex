/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:13:47 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/27 13:16:24 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

void	draw_wall_line(t_game *game, int x, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	raycasting(t_game *game);
void	draw_floor_and_ceiling(t_game *game);
t_imgb	*get_wall_texture(t_game *game, t_ray *ray);
void	text_calc(t_game *game, t_ray *ray);

#endif