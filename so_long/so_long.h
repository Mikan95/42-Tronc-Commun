/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:11:43 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/04 17:11:43 by ameechan         ###   ########.ch       */
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
	char	**map;
	char	**visited;
	int		fd;
	int		height;
	int		width;
	int		p_total;
	int		e_total;
	int		c_total;
	int		c_bfs;
	t_pos	*start;
	t_pos	*exit;
}				t_map;

//main functions' prototypes
int			arg_check(int argc, char **argv);
void		char_check(char **map, t_map *node);
void		check_borders(char **map, int map_height, int map_width);
int			count_lines(int *fd, char *map_path);
int			line_len_check(char **map);
void		map_check(t_map *node);
void		map_fill(t_map *node);
void		map_malloc(char ***map, t_map *node);
int			valid_char(char c);

//bfs functions
//void		bfs(char **map_copy, t_map *node, t_pos start);
void		bfs_prep(t_map *node);
void		copy_map(char **map_src, char **map_copy);
void		copy_malloc(char ***map_copy, t_map *node);
void		find_start(char **map, t_map *node);
int			valid_pos(int row, int column, t_map *node, char **map_copy);

//utility functions
int			array_size(char **array);
void		check_pec(t_map *node);
int			ft_mystrlen(char *str);
void		ft_perror(char *errmsg);
void		free_map(char **map);

//define struct for mlx
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	int		width;
	int		height;
}				t_data;


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

