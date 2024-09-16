/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:32:59 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 13:39:40 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// checks for a '\n' in the given linked list.
int	found_newline(t_list *line_stash)
{
	int		i;
	t_list	*last;

	i = 0;
	if (line_stash == NULL)
		return (0);
	last = get_last_node(line_stash);
	while (last->data[i])
	{
		if (last->data[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// Returns a pointer to the last node in 'line_stash'.
t_list	*get_last_node(t_list *line_stash)
{
	t_list	*current;

	if (line_stash == NULL)
		return (NULL);
	current = line_stash;
	while (current->next)
		current = current->next;
	return (current);
}

// Calculates the number of chars in the current line, including the trailing
// \n if there is one, and allocates memory accordingly.
void	generate_line(char **line, t_list *line_stash)
{
	int		i;
	int		count;

	count = 0;
	while (line_stash)
	{
		i = 0;
		while (line_stash->data[i])
		{
			if (line_stash->data[i] == '\n')
			{
				count++;
				break ;
			}
			i++;
			count++;
		}
		line_stash = line_stash->next;
	}
	*line = malloc(sizeof(char) * (count + 1));
}

// Frees the entire stash.
void	free_stash(t_list *line_stash)
{
	t_list	*current;
	t_list	*next;

	current = line_stash;
	while (current)
	{
		next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
}

int	gnl_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
