/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:48:58 by ameechan          #+#    #+#             */
/*   Updated: 2024/08/06 12:01:59 by ameechan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(f_list **lst, f_list *new)
{
	struct ListNode	*new_node;

	new_node = new;
	new_node->next = *lst;
	*lst = new_node;
}
