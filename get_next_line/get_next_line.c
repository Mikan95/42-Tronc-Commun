/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:32:53 by ameechan          #+#    #+#             */
/*   Updated: 2024/01/24 19:38:34 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	void	*buffer;

	buffer = (void *)malloc(BUFFER_SIZE);
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
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
	printf("read returned:\n%s", get_next_line(fd));
}
