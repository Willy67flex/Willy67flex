/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:01:18 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 13:52:11 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_ui(t_game *game)
{
	print_moovs(game);
	update_heart(game, game->sprites.pos_first_heart,
		game->sprites.current_state_first_heart, game->sprites.break_cnt_1);
	update_heart(game, game->sprites.pos_second_heart,
		game->sprites.current_state_second_heart, game->sprites.break_cnt_2);
	update_heart(game, game->sprites.pos_third_heart,
		game->sprites.current_state_third_heart, game->sprites.break_cnt_3);
}

void	print_moovs(t_game *game)
{
	char	*str_moves;
	char	*str_tmp;
	char	*str_coins;
	char	*str_final;
	char	*str_total;

	refresh_wall_for_print(game);
	str_moves = ft_itoa(game->moves_count);
	str_tmp = ft_strjoin("Moves: ", str_moves);
	free(str_moves);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, str_tmp);
	free(str_tmp);
	str_tmp = ft_itoa(game->total_collectibles - game->collectibles);
	str_coins = ft_strjoin("Coins: ", str_tmp);
	free(str_tmp);
	str_tmp = ft_strjoin(str_coins, "/");
	free(str_coins);
	str_total = ft_itoa(game->total_collectibles);
	str_final = ft_strjoin(str_tmp, str_total);
	free(str_tmp);
	free(str_total);
	mlx_string_put(game->mlx, game->win, 100, 20, 0xFFD700, str_final);
	free(str_final);
}

void	refresh_wall_for_print(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		put_perimeter_wall(game, i, 0);
		i++;
	}
}

void	update_heart(t_game *game, int pos, int is_full, int b_frame)
{
	void	*sprite;

	put_perimeter_wall(game, pos / IMG_SIZE, 0);
	if (is_full)
		sprite = game->sprites.heart[game->sprites.frame_heart];
	else
		sprite = game->sprites.b_heart[b_frame];
	draw_heart_sprite(game, sprite, pos);
}

void	draw_heart_sprite(t_game *game, void *img, int x_screen)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < IMG_SIZE)
	{
		x = 0;
		while (x < IMG_SIZE)
		{
			color = get_pixel_in_img(img, x, y);
			if (color != 0xFF000000 && color != 0x000000)
				mlx_pixel_put(game->mlx, game->win, x_screen + x, y, color);
			x++;
		}
		y++;
	}
}
