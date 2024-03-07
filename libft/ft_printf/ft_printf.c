/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:49:39 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/19 11:28:44 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_format(va_list *list, char c, int *length)
{
	if (c == 'c')
		ft_print_char(va_arg(*list, int), length);
	else if (c == 's')
		ft_print_str(va_arg(*list, char *), length);
	else if (c == 'p')
		ft_print_pointer(va_arg(*list, size_t), length);
	else if (c == 'i' || c == 'd')
		ft_print_number(va_arg(*list, int), length);
	else if (c == 'u')
		ft_print_unsign(va_arg(*list, long int), length);
	else if (c == 'x')
		ft_print_to_base(va_arg(*list, unsigned int), HEXA_MI, length);
	else if (c == 'X')
		ft_print_to_base(va_arg(*list, unsigned int), HEXA_MA, length);
	else if (c == '%')
		ft_print_char('%', length);
	if (*length == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		length;
	int		i;

	if (!s)
		return (0);
	length = 0;
	va_start(list, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && s[i + 1] != '\0')
		{
			if (ft_get_format(&list, s[++i], &length) == -1)
				return (-1);
			i++;
		}
		else
		{
			ft_print_char(s[i], &length);
			i++;
		}
	}
	va_end(list);
	return (length);
}
