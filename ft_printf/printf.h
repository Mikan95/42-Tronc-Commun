/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:41:46 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/17 16:06:36 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int	ft_printf(const char *str, ...);
int	ft_conversion(const char *str, va_list ap);
int	ft_c(char c);
#endif
