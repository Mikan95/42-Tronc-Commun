/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:32:53 by ameechan          #+#    #+#             */
/*   Updated: 2024/08/06 17:19:08 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static f_list	*line_stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		free_stash(line_stash);
		line_stash = NULL;
		return (NULL);
	}
	line = NULL;
	read_and_stash(fd, &line_stash);
	if (line_stash == NULL)
		return (NULL);
	extract_line(line_stash, &line);
	clean_stash(&line_stash);
	if (line[0] == '\0')
	{
		free_stash(line_stash);
		line_stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

// uses read() and adds characters to 'line_stash'.
void	read_and_stash(int fd, f_list **line_stash)
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
		add_to_stash(line_stash, buffer, readed);
		free(buffer);
	}
}

// adds the content of 'buffer' to the end of 'line_stash'.
void	add_to_stash(f_list **line_stash, char *buffer, int readed)
{
	int		i;
	f_list	*last;
	f_list	*new_node;

	new_node = malloc(sizeof (f_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->data = malloc(sizeof (char) * (readed + 1));
	if (new_node->data == NULL)
		return ;
	i = 0;
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

// extracts all characters from 'line_stash' and stores them in 'line'
// stops after first '\n' encountered.
void	extract_line(f_list *line_stash, char **line)
{
	int	i;
	int	j;

	if (line_stash == NULL)
		return ;
	generate_line(line, line_stash);
	if (line == NULL)
		return ;
	j = 0;
	while (line_stash)
	{
		i = 0;
		while (line_stash->data[i])
		{
			if (line_stash->data[i] == '\n')
			{
				(*line)[j++] = line_stash->data[i];
				break ;
			}
			(*line)[j++] = line_stash->data[i++];
		}
		line_stash = line_stash->next;
	}
	(*line)[j] = '\0';
}

// clears 'line_stash' so only the overflow (chars after the \n)
// remains in 'line_stash'.
void	clean_stash(f_list **line_stash)
{
	f_list	*last;
	f_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(f_list));
	if (!clean_node || !line_stash)
		return ;
	clean_node->next = NULL;
	last = get_last_node(*line_stash);
	i = 0;
	while (last->data[i] && last->data[i] != '\n')
		i++;
	if (last->data[i] && last->data[i] == '\n')
		i++;
	clean_node->data = malloc(sizeof(char) * (gnl_strlen(last->data) - i) + 1);
	if (!clean_node)
		return ;
	j = 0;
	while (last->data[i])
		clean_node->data[j++] = last->data[i++];
	clean_node->data[j] = '\0';
	free_stash(*line_stash);
	*line_stash = clean_node;
}
/*
int	main(void)
{
	int		fd;
	char	*path;
	char	*line;
	int		i;

	i = 0;
	path = "test.txt";
	fd = open(path, O_RDONLY);
	while (i < 10)
	{
		line = get_next_line(fd);
		printf ("i: %i\n", i);
		printf ("fd: %i, %s\n", fd, line);
		i++;
	}
	return (0);
}
*/
