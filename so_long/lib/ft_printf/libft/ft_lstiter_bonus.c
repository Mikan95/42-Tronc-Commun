/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:24:12 by ameechan          #+#    #+#             */
/*   Updated: 2024/08/06 12:01:59 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(f_list *lst, void (*f)(void *))
{
	f_list	*temp;

	while (lst)
	{
		temp = lst->next;
		f(lst->content);
		lst = temp;
	}
}
