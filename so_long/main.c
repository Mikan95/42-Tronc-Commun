/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:21:41 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 13:21:41 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_node(t_map *node)
{
	node->file_path = NULL;
	node->map_str = NULL;
	node->map = NULL;
	node->visited = NULL;
	node->start = NULL;
	node->exit = NULL;
	node->player = NULL;
	node->c_total = 0;
	node->e_total = 0;
	node->c_bfs = 0;
	node->e_bfs = 0;
}

int	main(int argc, char **argv)
{
	t_map	*node;

	node = NULL;
	arg_check(argc, argv);
	node = malloc(sizeof (t_map));
	if (!node)
		free_elements(node, ERR_111);
	init_node(node);
	node->file_path = argv[1];
	map_check(node);
	init_game(node);
}
