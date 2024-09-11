/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:38:05 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/09 18:38:05 by ameechan         ###   ########.ch       */
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
	void	*player_ptr;
	void	*exit_ptr;
	void	*obj_ptr;
	t_map	*node;
	int		width;
	int		height;
}				t_data;

typedef struct s_lst
{
	t_pos			pos;
	struct s_lst	*next;
}				t_lst;

//init game functions
int			init_game(t_map *node);
void		render_map(t_data *var, t_map *node);
void		draw_wall(t_data *var, int i, int j);
void		draw_player(t_data *var, int i, int j);
void		draw_exit(t_data *var, int i, int j);
void		draw_collectible(t_data *var, int i, int j);

//main functions' prototypes
void		arg_check(int argc, char **argv);
void		char_check(t_map *node);
void		check_borders(t_map *node, int map_height, int map_width);
int			count_lines(int *fd, char *map_path);
void		line_len_check(t_map *node);
void		map_check(t_map *node);
void		map_fill(t_map *node);
void		init_node(t_map *node);
void		init_map(t_map *node);
int			valid_char(char c);

//bfs functions
void		bfs(char **visited, t_map *node, t_pos start);
void		find_start(char **map, t_map *node);
int			valid_pos(int row, int column, t_map *node, char **map_copy);


//utility functions
int			array_size(char **array);
void		check_pec(t_map *node);
int			ft_mystrlen(char *str);
void		ft_perror(char *errmsg);
void		free_elements(t_map *node, char *errmsg);
void		free_map(char **map);

//DEFINE KEYCODES WSL2
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
#endif
//DEFINE KEYCODES MAC
/* # define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
#endif */

//DEFINE IMAGE PATHS
# define BGPATH "./assets/Background.xpm"
# define PLAYERPATH "./assets/player/player.xpm"
# define WALLPATH "./assets/walls/walls.xpm"
