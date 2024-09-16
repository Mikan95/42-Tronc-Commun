/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:28:46 by ameechan          #+#    #+#             */
/*   Updated: 2024/09/16 13:40:31 by ameechan         ###   ########.fr       */
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
}					t_list;
char	*get_next_line(int fd);
void	read_and_stash(int fd, t_list **line_stash);
void	add_to_stash(t_list **line_stash, char *buffer, int readed);
void	extract_line(t_list *line_stash, char **line);
void	clean_stash(t_list **line_stash);
int		found_newline(t_list *line_stash);
t_list	*get_last_node(t_list *line_stash);
void	generate_line(char **line, t_list *line_stash);
void	free_stash(t_list *line_stash);
int		gnl_strlen(const char *str);
#endif
