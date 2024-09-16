/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:47:09 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 13:47:26 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1042
# endif

typedef struct ListNode
{
	char			*data;
	struct ListNode	*next;
}					t_gnllist;
char		*get_next_line(int fd);
void		read_and_stash(int fd, t_gnllist **line_stash);
void		add_to_stash(t_gnllist **line_stash, char *buffer, int readed);
void		extract_line(t_gnllist *line_stash, char **line);
void		clean_stash(t_gnllist **line_stash);
int			found_newline(t_gnllist *line_stash);
t_gnllist	*get_last_node(t_gnllist *line_stash);
void		generate_line(char **line, t_gnllist *line_stash);
void		free_stash(t_gnllist *line_stash);
int			gnl_strlen(const char *str);
#endif
