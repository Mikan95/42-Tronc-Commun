/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:38:31 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/09 18:40:38 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*node;

	arg_check(argc, argv);
	node = malloc(sizeof (t_map));
	if (!node)
		free_elements(node, "Error\nMemory allocation failure\n");
	init_node(node);
	node->file_path = argv[1];
	map_check(node);
	init_game(node);
}
