/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:45:14 by ameechan          #+#    #+#             */
/*   Updated: 2024/07/28 12:45:14 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
}				t_data;

//DEFINE KEYCODES WSL2
/* # define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100 */
//DEFINE KEYCODES MAC
# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
#endif
