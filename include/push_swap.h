/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:46:54 by ftadeu-d          #+#    #+#             */
/*   Updated: 2022/03/06 16:50:36 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

int		ft_isdigit(int c);
long	ft_atoi(const char *str);
void	ft_putstr(char *str);

void	validate_args(char **argv);

void	fill_indices(t_list **stack);

void	normal_sort(t_list **stack_a, t_list **stack_b);

void	small_sort(t_list **stack_a, t_list **stack_b);

t_list	*ft_lstnew(int value);
void	ft_lstadd_front(t_list **stack, t_list *new);
t_list	*ft_lstlast(t_list *stack);
void	ft_lstadd_end(t_list **stack, t_list *new);
int		ft_lstsize(t_list *head);

int		sorting_ok(t_list **stack);
void	cleanup_stack(t_list **stack);
void	cleanup(char **s);
void	print_error(char *msg);
int		get_position(t_list **stack, int index);

int		push(t_list **to, t_list **from);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);

int		rev_rotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

int		rotate(t_list **stack);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);

int		swap(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);

#endif
