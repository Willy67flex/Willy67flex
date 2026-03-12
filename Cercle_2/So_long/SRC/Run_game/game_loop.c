/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:37:53 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 15:43:26 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_positions(t_game *game)
{
	int	i;
	int	noise;

	if (game->map[game->y][game->x] != 'E')
		game->map[game->y][game->x] = '0';
	noise = (game->x * 7) + (game->y * 13);
	put_img(game, game->texture.grass[noise % 3], game->x, game->y);
	if (game->map[game->y][game->x] == 'E')
		draw_exit_sprite(game, game->x, game->y, (game->collectibles == 0));
	i = 0;
	while (i < game->nb_enemy)
	{
		game->map[game->y_enemy[i]][game->x_enemy[i]] = '0';
		noise = (game->x_enemy[i] * 7) + (game->y_enemy[i] * 13);
		put_img(game, game->texture.grass[noise % 3], game->x_enemy[i],
			game->y_enemy[i]);
		i++;
	}
	game->x = game->start_x;
	game->y = game->start_y;
	game->map[game->y][game->x] = 'P';
	update_player(game, game->x, game->y, 1);
	reset_pos_enemy(game);
	ft_printf("Positions reset!\n");
}

void	game_over_loss(t_game *game)
{
	ft_printf("GAME OVER! You were killed by an enemy.\n");
	display_defeat(game);
	game->game_over = 1;
}

void	render_enemies(t_game *game)
{
	int		i;
	int		x;
	int		y;
	int		noise;

	i = 0;
	while (i < game->nb_enemy)
	{
		x = game->x_enemy[i];
		y = game->y_enemy[i];
		noise = (x * 7) + (y * 13);
		put_img(game, game->texture.grass[noise % 3], x, y);
		put_ennemy_on_map(game, x, y, game->enemy_dir[i]);
		i++;
	}
}

void	check_frame_sprites(t_game *game)
{
	game->sprites.current_frame++;
	if (game->sprites.current_frame >= 8)
		game->sprites.current_frame = 0;
	game->sprites.frame_heart++;
	if (game->sprites.frame_heart >= 5)
		game->sprites.frame_heart = 0;
	game->sprites.frame_coin++;
	if (game->sprites.frame_coin >= 10)
		game->sprites.frame_coin = 0;
	game->sprites.current_frame_enmy++;
	if (game->sprites.current_frame_enmy >= 4)
		game->sprites.current_frame_enmy = 0;
	if (game->sprites.current_state_first_heart == 0
		&& game->sprites.break_cnt_1 < 3)
		game->sprites.break_cnt_1++;
	if (game->sprites.current_state_second_heart == 0
		&& game->sprites.break_cnt_2 < 3)
		game->sprites.break_cnt_2++;
	if (game->sprites.current_state_third_heart == 0
		&& game->sprites.break_cnt_3 < 3)
		game->sprites.break_cnt_3++;
}

int	animation_loop(t_game *game)
{
	static int	counter = 0;
	static int	move_counter = 0;

	if (game->game_over)
		return (0);
	counter++;
	if (counter > SPEED)
	{
		check_frame_sprites(game);
		draw_ui(game);
		counter = 0;
		move_counter++;
		update_player(game, game->x, game->y, 1);
		update_coins(game);
		if (move_counter >= DIFFICULTY)
		{
			enemy_move(game);
			move_counter = 0;
		}
		render_enemies(game);
	}
	return (0);
}
