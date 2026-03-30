#include "cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC) close_window(game);
	if (keycode == KEY_W) game->key_w = 1;
	if (keycode == KEY_S) game->key_s = 1;
	if (keycode == KEY_A) game->key_a = 1;
	if (keycode == KEY_D) game->key_d = 1;
	if (keycode == KEY_SHIFT) game->key_shift = 1;
	if (keycode == KEY_LEFT) game->key_left = 1;
	if (keycode == KEY_RIGHT) game->key_right = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W) game->key_w = 0;
	if (keycode == KEY_S) game->key_s = 0;
	if (keycode == KEY_A) game->key_a = 0;
	if (keycode == KEY_D) game->key_d = 0;
	if (keycode == KEY_SHIFT) game->key_shift = 0;
	if (keycode == KEY_LEFT) game->key_left = 0;
	if (keycode == KEY_RIGHT) game->key_right = 0;
	return (0);
}

int mouse_move(int x, int y, t_game *game)
{
	int center_x = game->win_width / 2;
	int center_y = game->win_height / 2;
	int delta_x;

	(void)y;
	delta_x = x - center_x;
	if (delta_x != 0)
	{
		rotation_matrice(game, delta_x * 0.0005);
		mlx_mouse_move(game->mlx, game->win, center_x, center_y);
	}
	return (0);
}

void	run_game(t_game	*game)
{
	game->mlx = mlx_init();
	// mlx_get_screen_size(game->mlx, &game->win_width, &game->win_height);
	game->win_height = 1020;
	game->win_width = 1920;
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "Cub3D");
	game->img = mlx_new_image(game->mlx, game->win_width, game->win_height);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	mlx_mouse_hide(game->mlx, game->win);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_hook(game->win, 6, (1L << 6), mouse_move, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
	mlx_loop(game->mlx);
}

int	render_frame(t_game *game)
{
	double	rot_speed;

	rot_speed = 0.02;
	if (game->key_w) move_forward(game);
	if (game->key_s) move_backward(game);
	if (game->key_a) strafe_left(game);
	if (game->key_d) strafe_right(game);
	if (game->key_left)
		rotation_matrice(game, -rot_speed);
	if (game->key_right)
		rotation_matrice(game, rot_speed);
	draw_floor_and_ceiling(game);
	raycasting(game);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int	close_window(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_all(game, NULL);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < game->win_width && y >= 0 && y < game->win_height)
	{
		dst = game->addr + (y * game->line_length + x
				* (game->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

// void	*xpm_to_image(t_game *game, char *path)
// {
// 	void	*img;
// 	int		width;
// 	int		heigth;

// 	width = 32;
// 	heigth = 32;
// 	img = mlx_xpm_file_to_image(game->mlx, path, &width, &heigth);
// 	if (!img)
// 	{
// 		ft_printf("Error\nImpossible to load texture: %s\n", path);
// 		// close_window(game);
// 		exit(1);
// 	}
// 	return (img);
// }
