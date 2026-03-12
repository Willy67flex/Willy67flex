/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:59:43 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/17 13:50:09 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*xpm_to_image(t_game *game, char *path)
{
	void	*img;
	int		width;
	int		heigth;

	width = game->img_width;
	heigth = game->img_height;
	img = mlx_xpm_file_to_image(game->mlx, path, &width, &heigth);
	if (!img)
	{
		ft_printf("Error\nImpossible to load texture: %s\n", path);
		close_window(game);
		exit(1);
	}
	return (img);
}

void	put_img(t_game *game, void *img, int x, int y)
{
	int	width;
	int	heigth;

	width = x * IMG_SIZE;
	heigth = y * IMG_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, img, width, heigth);
}

unsigned int	get_pixel_in_img(void *img, int x, int y)
{
	char	*dst;
	int		bpp;
	int		line_len;
	int		endian;
	char	*addr;

	addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
	dst = addr + (y * line_len + x * (bpp / 8));
	return (*(unsigned int *)dst);
}

void	completed_map(t_game *game, int scr_x, int scr_y, void *sprite)
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
			color = get_pixel_in_img(sprite, x, y);
			if (color != 0xFF000000 && color != 0x000000)
			{
				mlx_pixel_put(game->mlx, game->win,
					scr_x + x, scr_y + y, color);
			}
			x++;
		}
		y++;
	}
}
