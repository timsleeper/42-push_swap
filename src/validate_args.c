/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftadeu-d <ftadeu-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:13:31 by ftadeu-d          #+#    #+#             */
/*   Updated: 2022/03/06 15:57:17 by ftadeu-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_repeated(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	is_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	validate_args(char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 1;
	args = argv;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!is_num(args[i]))
			print_error("Error");
		if (is_repeated(tmp, args, i))
			print_error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			print_error("Error");
		i++;
	}		
}
