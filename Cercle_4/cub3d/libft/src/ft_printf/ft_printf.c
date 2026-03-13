/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:36:25 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/14 12:35:34 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_handle_type((char)format[i], args, &count);
		}
		else if (format[i] == '\\' && format[i + 1] == 'n')
		{
			i++;
			ft_printchar('\n', &count);
		}
		else
			ft_printchar((char)format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
// int main(void)
// {
// 	// int result = ft_printf(" NULL %s NULL ", NULL);
// 	// printf("My functions result : %d\n", result);
// 	// int expected_result = printf(" NULL %s NULL ", NULL);
// 	// printf("The expected result : %d\n", expected_result);
// 	int min = -2147483648;
// 	int max = 2147483647;
// 	int *long_min = &min;
// 	int *long_max = &max;
// 	int ptr_test = ft_printf(" %p %p\n ", long_min, long_max);
// 	printf("My functions result : %d\n", ptr_test);
// 	int ptr_real = printf(" %p %p\n ", long_min, long_max);
// 	printf("My functions result : %d\n", ptr_real);
// }