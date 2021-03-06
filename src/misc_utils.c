/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:31:17 by ftadeu-d          #+#    #+#             */
/*   Updated: 2022/03/06 18:29:32 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sorting_ok(t_list **stack)
{
	t_list	*element;

	element = *stack;
	while (element && element->next)
	{
		if (element->value > element->next->value)
			return (0);
		element = element->next;
	}
	return (1);
}

void	cleanup_stack(t_list **stack)
{
	t_list	*element;
	t_list	*tmp;

	element = *stack;
	while (element)
	{
		tmp = element;
		element = element->next;
		free(tmp);
	}
	free(stack);
}

void	print_error(char *msg)
{
	ft_putstr(msg);
	exit(1);
}

int	get_position(t_list **stack, int index)
{
	t_list	*element;
	int		position;

	position = 0;
	element = *stack;
	while (element)
	{
		if (element->index == index)
			break ;
		position++;
		element = element->next;
	}
	return (position);
}
