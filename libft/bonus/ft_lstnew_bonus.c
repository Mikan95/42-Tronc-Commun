/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ameechan <ameechan@student.42.ch>           +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:37:27 by ameechan          #+#    #+#             */
/*   Updated: 2023/11/08 17:37:27 by ameechan         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	struct s_list	*newlst;

	newlst = (struct s_list *)malloc(sizeof(struct s_list));
	newlst->content = content;
	newlst->next = NULL;
	return (newlst);
}
