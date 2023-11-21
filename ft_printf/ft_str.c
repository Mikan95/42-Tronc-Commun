/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:34:18 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/21 15:09:55 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str(char *str)
{
	int	print_len;

	print_len = 0;
	if (!str)
		exit (0);
	while (str[print_len])
	{
		write(1, &str[print_len], 1);
		print_len++;
	}
	return (print_len);
}
