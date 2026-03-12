/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:54:07 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 12:33:51 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_take_damage(t_game *game)
{
	int	i;

	game->player_life--;
	ft_printf("Ouch! Lives left: %d\n", game->player_life);
	if (game->player_life == 2)
		game->sprites.current_state_third_heart = 0;
	else if (game->player_life == 1)
		game->sprites.current_state_second_heart = 0;
	if (game->player_life <= 0)
	{
		game->sprites.current_state_first_heart = 0;
		i = -1;
		while (++i <= 3)
		{
			game->sprites.break_cnt_1 = i;
			draw_ui(game);
			mlx_do_sync(game->mlx);
			usleep(100000);
		}
		game_over_loss(game);
	}
	else
		reset_positions(game);
}

void	process_victory(t_game *game, int new_x, int new_y, int noise)
{
	noise = (game->x * 7) + (game->y * 13);
	put_img(game, game->texture.grass[noise % 3], game->x, game->y);
	game->x = new_x;
	game->y = new_y;
	noise = (new_x * 7) + (new_y * 13);
	put_img(game, game->texture.grass[noise % 3], new_x, new_y);
	draw_exit_sprite(game, new_x, new_y, 1);
	put_player_on_map(game, new_x, new_y);
	game->moves_count++;
	print_moovs(game);
	game->game_over = 1;
	display_victory(game);
}

void	update_player_position(t_game *game, int new_x, int new_y, int noise)
{
	if (game->map[game->y][game->x] == 'E')
	{
		noise = (game->x * 7) + (game->y * 13);
		put_img(game, game->texture.grass[noise % 3], game->x, game->y);
		draw_exit_sprite(game, game->x, game->y, 0);
	}
	else
	{
		game->map[game->y][game->x] = '0';
		update_player(game, game->x, game->y, 0);
	}
	game->x = new_x;
	game->y = new_y;
	if (game->map[new_y][new_x] == 'E')
	{
		noise = (new_x * 7) + (new_y * 13);
		put_img(game, game->texture.grass[noise % 3], new_x, new_y);
		draw_exit_sprite(game, new_x, new_y, 0);
		put_player_on_map(game, new_x, new_y);
	}
	else
	{
		game->map[new_y][new_x] = 'P';
		update_player(game, new_x, new_y, 1);
	}
}

void	player_move(t_game *game, int new_y, int new_x)
{
	int	noise;

	noise = 0;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'M')
	{
		player_take_damage(game);
		return ;
	}
	if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
	{
		process_victory(game, new_x, new_y, noise);
		return ;
	}
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles--;
		if (game->collectibles == 0)
			open_exit_door(game);
	}
	update_player_position(game, new_x, new_y, noise);
	game->moves_count++;
	ft_printf("Moves: %d\n", game->moves_count);
	print_moovs(game);
}
