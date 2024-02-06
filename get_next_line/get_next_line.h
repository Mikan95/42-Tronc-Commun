/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:28:46 by ameechan          #+#    #+#             */
/*   Updated: 2024/02/06 18:03:31 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	void			*stash;
	struct	s_list	*next;
}					t_list;
char	*get_next_line(int fd);
unsigned long	found_nl_or_eof(char *buffer);
t_list	**fill_stash(char *buffer, t_list **line_stash);
char	*split_nl(char *nl_str, t_list **line_stash);
size_t	ft_strlen(char *s);
//size_t	ft_strlcpy(char *dest, char *src, size_t dest_size);
#endif
