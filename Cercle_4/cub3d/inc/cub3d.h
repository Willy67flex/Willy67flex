
#ifndef CUB3D_H
# define CUB3D_H
# define _GNU_SOURCE

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <limits.h>
# include <math.h>

typedef struct s_game	t_game;
typedef struct s_ray	t_ray;
typedef	struct s_imgb	t_imgb;

# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "check_input.h"
# include "init.h"
# include "my_mlx.h"
# include "algo.h"

# define WIN_HEIGHT 1020
# define WIN_WIDTH 1920
# define TEXT_HEIGHT 32
# define TEXT_WIDTH 32
# define MOUSE_SCRL_UP 4
# define MOUSE_SCRL_DOWN 5

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_SHIFT 65505
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_sprites
{

}	t_sprites;

typedef	struct s_imgb
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_imgb;

typedef struct s_texture
{
	t_imgb	north;//0
	t_imgb	south;//1
	t_imgb	east;//2
	t_imgb	west;//3
	t_imgb	door;//ou door[x]

	int		hex_floor;
	int		hex_ceiling;
}	t_texture;

typedef struct s_map_content
{
	char	*n_txtr;
	char	*s_txtr;
	char	*w_txtr;
	char	*e_txtr;

	char	*floor_color;
	char	*ceiling_color;
}	t_map_content;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_ray
{
	t_vec2	*dir;
	t_vec2	*side_dist;
	t_vec2	*delta_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	double	perp_wall_dist;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	double	step;
	double	text_pos;
}	t_ray;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img;
	char			**map;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				map_width;
	int				map_height;
	int				pos_init_x;
	int				pos_init_y;
	int				win_height;
	int				win_width;
	int				px;
	int				py;
	int				player;//check du nbr de joueur sur la map
	int				p_dir;//check de sa direction de depart
	t_sprites		*sprites;
	t_map_content	*map_content;
	t_texture		*texture;
	t_vec2			*pos;
	t_vec2			*dir;
	t_vec2			*plane;
	t_ray			*ray;
	int				key_w;
	int				key_s;
	int				key_a;
	int				key_left;
	int				key_right;
	int				key_d;
	int				key_shift;
}	t_game;


/*
p_dir:

0 = north
1 = south
2 = west
3 = east
*/
//free_all
void	free_all(t_game *game, char *msg);
void	free_texture(t_game *game);
void	free_map_content(t_game *game);
void	free_tab(char **tab);

int	render_frame(t_game *game);
void	rotation_matrice(t_game *game, double angle);
void move_player(t_game *game, double move_x, double move_y);
void strafe_left(t_game *game);
void move_forward(t_game *game);
void	move_backward(t_game *game);
void	strafe_right(t_game *game);
void	draw_minimap(t_game *game);

#endif // CUB3D_H