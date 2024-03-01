/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:27:59 by ameechan          #+#    #+#             */
/*   Updated: 2024/03/01 16:32:03 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		is_space(char c);
int		is_digit(char c);
int		ft_atoi(const char *str);
int		ft_printf(const char *str, ...);
int		ft_conversion(const char *str, va_list ap);
int		ft_char(char c);
int		ft_str(char *str);
int		ft_putptr(unsigned long ptr, char *hex_chars);
int		ft_putint(int nbr, char *dec_chars);
int		ft_putnbr_hex(unsigned int nbr, char *hex_chars);
int		ft_putnbr_dec(unsigned int nbr, char *dec_chars);
#endif
