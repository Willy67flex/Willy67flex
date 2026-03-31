/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:13:47 by ele-moig          #+#    #+#             */
/*   Updated: 2026/03/31 14:25:02 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

typedef struct s_game	t_game;
typedef struct s_ray	t_ray;
typedef struct s_imgb	t_imgb;
void	draw_wall_line(t_game *game, int x, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	raycasting(t_game *game);
void	draw_floor_and_ceiling(t_game *game);
t_imgb	*get_wall_texture(t_game *game, t_ray *ray);
void	text_calc(t_game *game, t_ray *ray);
void	ft_ray_calc(t_game *game, t_ray *ray, int x);
void	ft_ray_dir_check(t_game *game, t_ray *ray);
void	ft_draw_wall_calc(t_game *game, t_ray *ray);
void	ft_text_calc_init(t_game *game, t_imgb *tex, t_ray *ray, int x);
void	ray_tex_check(t_game *game, t_ray *ray, t_imgb *tex);

#endif