/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:07:11 by ftadeu-d          #+#    #+#             */
/*   Updated: 2022/03/06 15:49:40 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_bits(t_list **stack)
{
	t_list	*element;
	int		max;
	int		bits;

	element = *stack;
	max = element->index;
	bits = 0;
	while (element)
	{
		if (element->index > max)
			max = element->index;
		element = element->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	normal_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	bits = get_bits(stack_a);
	while (i < bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
