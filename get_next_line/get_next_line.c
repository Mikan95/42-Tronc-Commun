/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:32:53 by ameechan          #+#    #+#             */
/*   Updated: 2024/02/09 17:31:38 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static t_list	*line_stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	// 1. read from fd and add to linked list
	read_and_stash(fd, &line_stash);
	if (line_stash == NULL)
		return (NULL);
	// 2. extract from stash to line
generate_line(line, line_stash);	
	// 3. clean up stash
	return (line);
}

// uses read() to add characters to the stash
void	read_and_stash(int fd, t_list **line_stash)
{
	char	*buffer;
	int		readed;

	readed = 1;
	while (!found_newline(*line_stash) && readed != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return ;
		readed = (int)read(fd, buffer, BUFFER_SIZE);
		if ((*line_stash == NULL && readed == 0) || readed == -1)
		{
			free(buffer);
			return ;
		}
		buffer[readed] = '\0';
		add_to_stash(&line_stash, buffer, readed);
		free(buffer);
	}
}

// adds the content of buffer to the end of linked list
void	add_to_stash(t_list **line_stash, char *buffer, int readed)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof (t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = malloc(sizeof (char) * (readed + 1));
	if (new_node->data == NULL)
		return;
	while (buffer[i] && i < readed)
	{
		new_node->data[i] = buffer[i];
		i++;
	}
	new_node->data[i] = '\0';

	if (*line_stash == NULL)
	{
		*line_stash = new_node;
		return ;
	}
	last = get_last_node(*line_stash);
	last->next = new_node;
}

// extracts all characters from our stash and stores them in line
// stopping after the first \n it encounters
void	extract_line(t_list *line_stash, char **line)
{
}

/* After extracting the line that was read, we don't need those characters
 * anymore. This function clears the stash so only the characters that have
 * not been returned at the end of get_next_line remain in our static stash. */
void	clean_stash(t_list **line_stash)
{
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf ("%s", line);
		free (line);
	}
	return (0);
}
