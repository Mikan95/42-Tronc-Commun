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

#include "minitalk.h"

/*
decodes signals from client by assigning the result of (signal == SIGUSR1)
to the right most (least significant bit) bit of current_char.
Then, sends read receipt to client
*/
void	ft_decode_send_receipt(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_index;

	(void)context;
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
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}
/*
finds PID of server and prints it to stdout
then waits for and decodes signals from client.
*/
int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_decode_send_receipt;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
