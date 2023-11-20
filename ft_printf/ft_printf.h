/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:41:46 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/20 18:59:31 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include "libft.h"

int	ft_printf(const char *str, ...);
int	ft_conversion(const char *str, va_list ap);
int	ft_char(char c);
int	ft_str(char *str);
int	ft_ptr(void *ptr);
#endif
