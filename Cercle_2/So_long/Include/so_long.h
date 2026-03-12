/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:44:09 by whollebe          #+#    #+#             */
/*   Updated: 2025/12/18 10:57:54 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <sys/time.h>

# define IMG_SIZE 32
# define DIR_DOWN	0
# define DIR_UP		1
# define DIR_LEFT	2
# define DIR_RIGHT	3

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

//DIFFICULTY : [1 2 3 4 5 6 7 8 9 10]
//             ^                  ^
//             |                  |
//         Impossible         very easy
# define DIFFICULTY 2

//SPEED OF SPRITES

//The speed depends on the PC's environment
//pc 42 : ~16000
//pc perso : ~1500/2000

# define SPEED 16000

typedef struct s_map
{
	void	*wall[4];
	void	*wall_right[3];
	void	*wall_left[3];
	void	*wall_up[2];
	void	*wall_inter[5];
	void	*corner_u_r[3];
	void	*corner_u_l[3];
	void	*corner_d_r[3];
	void	*corner_d_l[3];
	void	*grass[3];
	void	*exit[2];
}	t_map;

typedef struct s_sprites
{
	void	*idle_down[8];
	void	*idle_up[8];
	void	*idle_left[8];
	void	*idle_right[8];

	int		current_frame;
	int		direction;

	void	*b_heart[5];
	void	*heart[5];

	int		frame_heart;
	int		pos_first_heart;
	int		pos_second_heart;
	int		pos_third_heart;
	int		current_state_first_heart;
	int		current_state_second_heart;
	int		current_state_third_heart;
	int		break_cnt_1;
	int		break_cnt_2;
	int		break_cnt_3;

	void	*coin[10];

	int		frame_coin;

	void	*enmy_down[4];
	void	*enmy_up[4];
	void	*enmy_left[4];
	void	*enmy_right[4];

	int		current_frame_enmy;
}	t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_width;
	int			map_height;
	int			player_life;
	int			start_x;
	int			start_y;
	int			x;
	int			y;
	int			*x_enemy;
	int			*y_enemy;
	int			*start_x_enemy;
	int			*start_y_enemy;
	int			nb_enemy;
	int			*enemy_dir;
	int			img_width;
	int			img_height;
	void		*img_wall;
	void		*img_floor;
	void		*img_player;
	void		*img_collect;
	void		*img_exit;
	int			collectibles;
	int			total_collectibles;
	int			moves_count;
	t_sprites	sprites;
	t_map		texture;
	int			game_over;
}	t_game;

typedef struct s_char
{
	int	o;
	int	wall;
	int	c;
	int	e;
	int	p;
	int	m;
}	t_char;

void			check_input(int argc, char **argv);
void			msg_error(char *msg);
void			check_map(char *ber, t_game *game, t_char *character);
void			free_map(char **map, int height);
void			define_length_and_width(t_game *game, char *ber);
void			define_map(t_game *game, char *ber);
void			scan_map(t_game *game, t_char *character);
void			verif_char(t_game *game, t_char *character);
void			check_map(char *ber, t_game *game, t_char *character);
void			verif_map(t_game *game);
void			msg_error(char *msg);
void			init_window(t_game *game);
void			render_map(t_game *game);
void			init_images(t_game *game);
int				close_window(t_game *game);
int				animation_loop(t_game *game);
void			run_game(t_game *game);
void			verif_enemy(t_char *character);
void			get_enemies_pos(t_game *game, t_char *character);
void			player_move(t_game *game, int new_y, int new_x);
void			init_images(t_game *game);
void			init_image_player(t_game *game);
void			init_image_heart(t_game *game);
void			init_image_heart(t_game *game);
void			init_image_wall_and_grass(t_game *game);
void			init_image_coin_and_exit(t_game *game);
void			init_image_ennemy(t_game *game);
void			*xpm_to_image(t_game *game, char *path);
void			put_perimeter_wall(t_game *game, int x, int y);
void			*put_intersection_wall(t_game *game, int x, int y);
void			*put_corner_wall(t_game *game, int x, int y);
void			*put_vertical_wall(t_game *game, int x, int y);
void			*put_horizontal_wall(t_game *game, int x, int y);
void			*put_special_wall(t_game *game, int x, int y, int max_y);
void			put_img(t_game *game, void *img, int x, int y);
void			destroy_all_images(t_game *game);
void			player_take_damage(t_game *game);
void			enemy_move(t_game *game);
void			reset_pos_enemy(t_game *game);
int				get_sign(int target, int current);
int				is_valid_enemy_move(t_game *game, int x, int y);
void			update_single_enemy(t_game *game, int i, int new_x, int new_y);
void			completed_map(t_game *game, int scr_x, int scr_y, void *sprite);
unsigned int	get_pixel_in_img(void *img, int x, int y);
void			put_img(t_game *game, void *img, int x, int y);
void			*xpm_to_image(t_game *game, char *path);
void			update_player(t_game *game, int x, int y, int with_player);
void			put_ennemy_on_map(t_game *game, int map_x, int map_y, int dir);
void			put_player_on_map(t_game *game, int map_x, int map_y);
void			render_map(t_game *game);
void			update_coins(t_game *game);
void			draw_coin_sprite(t_game *game, int x, int y);
void			draw_exit_sprite(t_game *game, int x, int y, int is_open);
void			open_exit_door(t_game *game);
void			draw_heart_sprite(t_game *game, void *img, int x_screen);
void			update_heart(t_game *game, int pos, int is_full, int b_frame);
void			refresh_wall_for_print(t_game *game);
void			print_moovs(t_game *game);
void			draw_ui(t_game *game);
void			display_victory(t_game *game);
void			display_defeat(t_game *game);
void			game_over_loss(t_game *game);
void			reset_positions(t_game *game);

#endif // SO_LONG_H
