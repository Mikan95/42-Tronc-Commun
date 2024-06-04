/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 23:23:20 by ameechan          #+#    #+#             */
/*   Updated: 2024/06/04 23:23:20 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <signal.h>

int		ft_atol(char *str);
void	ft_send_signal(int pid, unsigned char char_to_send);
void	ft_decode(int signal);

#endif
