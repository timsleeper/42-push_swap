/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:23:50 by ftadeu-d          #+#    #+#             */
/*   Updated: 2022/03/06 17:48:25 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_min(t_list **stack, int val)
{
	t_list	*element;
	int		min;

	element = *stack;
	min = element->index;
	while (element->next)
	{
		element = element->next;
		if ((element->index < min) && element->index != val)
			min = element->index;
	}
	return (min);
}

static void	sort_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		second;

	head = *stack_a;
	min = find_min(stack_a, -1);
	second = find_min(stack_a, min);
	if (sorting_ok(stack_a))
		return ;
	if (head->index == min && head->next->index != second)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (head->index == second && head->next->index == min)
		sa(stack_a);
	else if (head->index == second && head->next->index != min)
		rra(stack_a);
	else if (head->next->index == min)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	position;

	position = get_position(stack_a, find_min(stack_a, -1));
	if (position == 1)
		ra(stack_a);
	else if (position == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (position == 3)
		rra(stack_a);
	if (sorting_ok(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	position;

	position = get_position(stack_a, find_min(stack_a, -1));
	if (position == 1)
		ra(stack_a);
	else if (position == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (position == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (position == 4)
		rra(stack_a);
	if (sorting_ok(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	small_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (sorting_ok(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
