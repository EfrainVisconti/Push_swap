/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:30:28 by eviscont          #+#    #+#             */
/*   Updated: 2024/05/01 15:12:52 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(char **argv, int i)
{
	int j;
	
	if (*argv[i] == '\0')
		return (0);
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atoi_push(argv[i], argv) == ft_atoi_push(argv[j], argv))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isvalid(int c)
{
	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42)
		|| (c == 44) || (c == 46) || (c == 47))
		return (0);
	return (1);
}

int	check_args(char **argv, int i, int j)
{
	while (argv[i] != NULL)
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (!ft_isdigit(argv[i][++j]))
					return (0);
			}
			else if (ft_isdigit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if ((!ft_isdigit(argv[i][j])) && argv[i][j] != ' ')
					return (0);
			}
			if (!ft_isvalid(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
