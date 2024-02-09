/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:32:59 by ameechan          #+#    #+#             */
/*   Updated: 2024/02/04 11:51:46 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Looks for a newline character in the given linked list. */
int        found_newline(t_list *stash)
{
}

/* Returns a pointer to the last node in our stash */
t_list        *ft_lst_get_last(t_list *stash)
{
}

/* Calculates the number of chars in the current line, including the trailing
 * \n if there is one, and allocates memory accordingly. */
void        generate_line(char **line, t_list *stash)
{
}

/* Frees the entire stash. */
void        free_stash(t_list *stash)
{
}



int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
