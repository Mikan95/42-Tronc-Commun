/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:55:58 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 12:56:01 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"

# define TILE_SIZE 32

//define struct for storing coordinates
typedef struct s_pos
{
	int	y;
	int	x;
} 				t_pos;

//define struct for all map related data
typedef struct s_map
{
	char	*file_path;
	char	*map_str;
	char	**map;
	char	**visited;
	int		fd;
	int		height;
	int		width;
	int		p_total;
	int		e_total;
	int		c_total;
	int		c_bfs;
	int		e_bfs;
	int		move_count;
	t_pos	*player;
	t_pos	*start;
	t_pos	*exit;
}				t_map;

//define struct for mlx
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	void	*wall_ptr;
	void	*exit_ptr;
	void	*bg_ptr;
	t_map	*node;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	int		pixel;
	int		colour;
	char	*addr;
	char	*bg_addr;
	int		bg_bpp;
	int		bg_size_line;
	int		bg_endian;
}				t_data;

//main.c functions
void		init_node(t_map *node);

//error_checks.c functions
void		arg_check(int argc, char **argv);
void		line_len_check(t_map *node);
void		char_check(t_map *node);
void		check_pec(t_map *node);
void		check_borders(t_map *node, int map_height, int map_width);

//utils.c functions
int			array_size(char **array);
int			ft_mystrlen(char *str);
void		store_exit(t_map *node, int i, int j);
int			valid_char(t_map *node, char c);

//map_utils.c functions
int			count_lines(int *fd, char *map_path);
void		init_map(t_map *node);
void		map_check(t_map *node);
void		find_start(char **map, t_map *node);

//bfs.c functions
void		bfs(char **visited, t_map *node, t_pos start);
int			valid_pos(int row, int column, t_map *node, char **map_copy);

//init.c functions
int			init_game(t_map *node);
void		init_data(t_data *var);
int			key_hook(int keycode, t_data *var);
int			close_window(t_data *data);

//render.c functions
void		check_collectibles(t_map *node, int c_total, t_pos *exit);
void		render_xpm(t_data *var, char *path, int start_x, int start_y);
void		render_map(t_data *var, t_map *node);
void		render_end(t_data *var);

//draw.c functions
void		draw_bg(t_data *va, int i, int j);
void		draw_collectible(t_data *var, int i, int j);
void		draw_exit(t_data *var, int i, int j);
void		draw_player(t_data *var, int i, int j);
void		draw_wall(t_data *var, int i, int j);

//movement.c functions
void		move_up(t_data *var);
void		move_down(t_data *var);
void		move_left(t_data *var);
void		move_right(t_data *var);

//free.c functions
void		free_elements(t_map *node, char *errmsg);
void		free_map(char **map);

//DEFINE KEYCODES WSL2
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
//DEFINE KEYCODES MAC
/* # define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
*/

//DEFINE IMAGE PATHS
# define BGPATH "./assets/bg/Bricks.xpm"
# define PLAYERPATH "./assets/player/space-down.xpm"
# define WALLPATH "./assets/walls/walls.xpm"
# define OBJPATH "./assets/collectibles/obj.xpm"
# define EXITPATH "./assets/exit/exit2.xpm"

#endif
