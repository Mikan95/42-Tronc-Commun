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
	void					*buffer;
	static t_list			*line_stash;
	static unsigned long	nl_count;

	printf("assigning memory to buffer\n");
	buffer = (void *)malloc(BUFFER_SIZE);
	printf("assigned successfully\n");
	if (!line_stash || nl_count = 0)
	{
		printf("line stash empty, initialising nl_count to 0\n");
//		while (read(fd, buffer, BUFFER_SIZE) > 0)
		nl_count = 0;
		while (nl_count < 1)
		{
			read(fd, buffer, BUFFER_SIZE);
			nl_count = found_nl_or_eof(buffer);
			if (nl_count = 1)
			{
				nl_count = 0;
				return (split_nl(buffer, &line_stash));
			}
			line_stash = *fill_stash(buffer, line_stash);
		}
	}
	else
	{
		return (split_nl(buffer))
			printf("checking for nl\n");
			nl_count = found_nl_or_eof(buffer);
			if (nl_count > 0)
			{
				printf("nl found!\n");
				return(split_nl(buffer, &line_stash));
			}
			printf("number of new lines in current buffer: %zu\n", nl_count);
			else
				printf("no nl\n");
				line_stash = *fill_stash(buffer, &line_stash);
	}
	return (buffer);
}

unsigned long	found_nl_or_eof(char *buffer)
{
	unsigned long	i;
	unsigned long	count;

	i = 0;
	count = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			count++;
		i++;
	}
	return(count);
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

char	*split_nl(char *nl_str, t_list **line_stash)
{
/*  this function will find the new line, copy every character up to nl (including nl)
	copy evrything from line_stash to "line"
	clear line_stash and copy everything after nl to the new head node of line_stash
	and finally return "line"*/

	size_t	len;
//	t_list	*current;
	char	*temp_str;
	int		i;
	int		j;

	i = 0;
	len = ft_strlen(nl_str);
	printf("len of nl_str: %zu\n", len);
	temp_str = (char *)malloc(len + 1);
	if (temp_str < 0)
		return (NULL);
	while (nl_str[i] && nl_str[i] != '\n')
	{
		temp_str[i] = nl_str[i];
		i++;
	}
	temp_str[i] = '\0';
	printf("chars before nl: %s\n", temp_str);
	fill_stash(temp_str, line_stash);
	printf("filled stash\n");
	j = i;
	i = 0;
	while (nl_str[j])
		temp_str[i++] = nl_str[j++];
	temp_str[i] = '\0';
	printf("chars after nl: %s\n", temp_str);
//remove line below after testing
	return (temp_str);
/* 	while (current)
	{
		len += ft_strlen(current->stash);
		current = current->next;
	} */
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

