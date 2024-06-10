/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:31:25 by ameechan          #+#    #+#             */
/*   Updated: 2024/05/21 19:31:25 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//converts from ascii to int
int	ft_atol(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}

/*
sends signals to server starting from left most bit (most significant bit)
if bit == 1, sends SIGUSR1, else sends SIGUSR2
*/
void	ft_send_signal(int pid, unsigned char char_to_send)
{
	int	shift_index;
	unsigned char	temp_char;

	shift_index = 8;
	temp_char = char_to_send;
	while (shift_index > 0)
	{
		shift_index--;
		temp_char = char_to_send >> shift_index;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

/*
checks if the number of arguments is correct,
then sends signals to the server letter by letter.
*/
int	main(int argc, char **argv)
{
	pid_t	server_pid;
	const char	*str;
	int		i;

	if (argc != 3)
	{
		ft_printf("Incorrect number of arguments\n");
		exit (0);
	}
	server_pid = ft_atol(argv[1]);
	str = argv[2];
	i = 0;
	while(str[i])
		ft_send_signal(server_pid, str[i++]);
	ft_send_signal(server_pid, '\0');
	return (0);
}
