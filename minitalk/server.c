/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:31:40 by ameechan          #+#    #+#             */
/*   Updated: 2024/05/21 19:31:40 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "minitalk.h"

void	ft_decode(int signal)
{
	static unsigned char	current_char;
	static int				bit_index;

	current_char |= (signal == SIGUSR1);
	bit_index++;
	if(bit_index == 8)
	{
		ft_printf("%c", current_char);
		if (current_char == '\0')
			ft_printf("\n");
		current_char = 0;
		bit_index = 0;
	}
	else
		current_char <<= 1;
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, ft_decode);
	signal(SIGUSR2, ft_decode);
	while (1)
		pause();
	return (0);
}
