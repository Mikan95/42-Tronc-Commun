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

//converts from ascii to long int
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

//sends signals to server
void	ft_send_signal(int pid, unsigned char char_to_send)
{
	int	i;
	unsigned char	temp_char;

	i = 8;
	temp_char = char_to_send;
	while (i > 0)
	{
		i--;
		temp_char = char_to_send >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}

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
