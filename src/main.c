/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:44:39 by ftadeu-d          #+#    #+#             */
/*   Updated: 2022/03/06 17:18:56 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	fill_stack(t_list **stack, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 1;
	args = argv;
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_end(stack, new);
		i++;
	}
	fill_indices(stack);
}

static void	sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) <= 5)
		small_sort(stack_a, stack_b);
	else
		normal_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	validate_args(argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	fill_stack(stack_a, argv);
	if (sorting_ok(stack_a))
	{
		cleanup_stack(stack_b);
		return (0);
	}
	sort(stack_a, stack_b);
	cleanup_stack(stack_a);
	cleanup_stack(stack_b);
	return (0);
}
