/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:32:53 by ameechan          #+#    #+#             */
/*   Updated: 2024/01/31 02:02:04 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	void			*buffer;
	t_list	*line_stash;

	line_stash = NULL;
	buffer = (void *)malloc(BUFFER_SIZE);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (found_nl_or_eof(buffer) == 1)
			return(clear_stache(buffer, &line_stash));
		else
			line_stash = *fill_stash(buffer, &line_stash);
	}
	return (buffer);
}

int		found_nl_or_eof(char *buffer)
{
	while (*buffer != '\n' | !buffer)
		buffer++;
	if (*buffer == '\n')
		return (1);
	else
		return(0);
}

t_list	**fill_stash(char *buffer, t_list **line_stash)
{
	t_list	*current;
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->stash = buffer;
	new_node->next = NULL;
	if (*line_stash == NULL)
		*line_stash = new_node;
	else
	{
		current = *line_stash;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	return (line_stash);
}

char	*clear_stash(char *nl_str, t_list **line_stash)
{
/*  this function will find the new line, copy every character up to nl (including nl)
	copy evrything from line_stash to "line"
	clear line_stash and copy everything after nl to the new head node of line_stash
	and finally return "line"*/
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	char	*filename = "test.txt";
	int	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	get_next_line(fd);
}

/* char *copy_list_data(t_list *head)
{
	size_t total_length;
	t_list *current;

	total_length = 0;
	current = head;
	while (current)
	{
		total_length += strlen(current->stash);
		current = current->next;
	}
	char *concatenated_str = (char *)malloc(total_length + 1);
	if (!concatenated_str)
		return (NULL);
	char *ptr = concatenated_str;
	current = head;
	while (current)
	{
		strcpy(ptr, current->stash);
		ptr += strlen(current->stash);
		current = current->next;
	}
	*ptr = '\0';
	return (concatenated_str);
} */

