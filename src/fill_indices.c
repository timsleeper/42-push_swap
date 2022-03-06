/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_indices.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:29:14 by ftadeu-d          #+#    #+#             */
/*   Updated: 2022/03/06 14:36:06 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_list	*find_min(t_list **stack)
{
	t_list	*element;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	element = *stack;
	if (element)
	{
		while (element)
		{
			if ((element->index == -1) && (!has_min
					|| element->value < min->value))
			{
				min = element;
				has_min = 1;
			}
			element = element->next;
		}
	}
	return (min);
}

void	fill_indices(t_list **stack)
{
	t_list	*element;
	int		index;

	index = 0;
	element = find_min(stack);
	while (element)
	{
		element->index = index++;
		element = find_min(stack);
	}
}
