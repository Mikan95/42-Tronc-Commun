/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:03:16 by ameechan          #+#    #+#             */
/*   Updated: 2024/08/28 20:03:16 by ameechan         ###   ########.ch       */
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

//define struct for BFS starting position
typedef struct pos_data
{
	int	row;
	int column;
} 				s_pos;

//main functions' prototypes
int		arg_check(int argc, char **argv);
void	char_check(char **map);
void	check_borders(char **map, int map_height, int map_width);
int		count_lines(int *fd, char *map_path);
int		line_len_check(char **map);
void	map_check(int fd, char *map_path);
void	map_fill(int fd, char **map, int map_height);
int		map_malloc(int fd, char ***map, char *map_path);
int		valid_char(char c);

//bfs functions
void	bfs_prep(char **map, int map_height, int map_width);
void	find_start(char **map, s_pos *start_pos);
void	copy_map(char **map_src, char **map_copy);
void	copy_malloc(char ***map_copy, int height, int width);

//utility functions
int		array_size(char **array);
void	check_pec(int P_count, int E_count, int C_count);
int		ft_mystrlen(char *str);
void	ft_perror(char *errmsg);
void	free_map(char **map);

//define struct for map
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	int		width;
	int		height;
}				t_data;


//DEFINE KEYCODES WSL2
/* # define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
#endif */
//DEFINE KEYCODES MAC
# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
#endif

