/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:41:46 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/23 15:48:15 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_conversion(const char *str, va_list ap);
int	ft_char(char c);
int	ft_str(char *str);
int	ft_putptr(unsigned long ptr, char *hex_chars);
int	ft_putint(int nbr, char *dec_chars);
int	ft_putnbr_hex(unsigned int nbr, char *hex_chars);
int	ft_putnbr_dec(unsigned int nbr, char *dec_chars);
#endif
