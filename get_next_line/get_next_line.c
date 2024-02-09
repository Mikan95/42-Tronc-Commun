/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:32:53 by ameechan          #+#    #+#             */
/*   Updated: 2024/02/06 18:24:32 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
	{
		// 1. read from fd and add to linked list
		// 2. extract frok stash to line
		// 3. clean up stash
	}

// uses read() to add characters to tue stash
void	read_and_stash(int fd, t_list **stash)
{
}

// adds the content of buffer to the end of linked list
void	add_to_stash(t_list **stash, char *buffer, int readed)
{
}

// extracts all characters from our stash and stores them in line
// stopping after the first \n it encounters
void	extract_line(t_list *stash, char **line)
{
}

/* After extracting the line that was read, we don't need those characters
 * anymore. This function clears the stash so only the characters that have
 * not been returned at the end of get_next_line remain in our static stash. */
void	clean_stash(t_list **stash)
{
}
