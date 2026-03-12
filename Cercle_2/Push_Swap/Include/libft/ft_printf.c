/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:05:13 by whollebe          #+#    #+#             */
/*   Updated: 2025/11/17 13:37:30 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_char_to_int(char *str, int *j)
// {
// 	int		i;
// 	int		count;
// 	char	*s;
// 	int		result;

// 	i = 0;
// 	count = 0;
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		i++;
// 		count++;
// 		(* j)++;
// 	}
// 	(* j)--;
// 	i = 0;
// 	s = malloc(sizeof(char) * (count + 1));
// 	if (!s)
// 		return (NULL);
// 	while (i < count)
// 	{
// 		s[i] = str[i];
// 		i++;
// 	}
// 	s[i] = '\0';
// 	result = ft_atoi(s);
// 	free(s);
// 	return (result);
// }

// void	ft_point_flag(char *argc, int *count_print, char *str, int *j)
// {
// 	int	size;
// 	int	s;

// 	(* j)++;
// 	size = ft_strlen(str);
// 	// if (str[size - 1] == 'c' || str[size - 1] == 'p')
// 	// 	write (1, "error\n", 6);

// 	s = ft_char_to_int(&str[1], j);
// 	ft_print_str_count(argc, count_print);
// 	ft_printf("'.%d'\n", s);
// 	(* j)++;
// }

// void	ft_sign_flag(char *argc, int *count_print)
// {
// 	(void)argc;
// 	(void)count_print;
// 	ft_printf("+\n");
// }

// void	ft_space_flag(char *argc, int *count_print)
// {
// 	(void)argc;
// 	(void)count_print;
// 	ft_printf("' '\n");
// }

// void	ft_prefix_flag(char *argc, int *count_print)
// {
// 	(void)argc;
// 	(void)count_print;
// 	ft_printf("#\n");
// }

// void	ft_alignement_flag(char *argc, int *count_print)
// {
// 	(void)argc;
// 	(void)count_print;
// 	ft_printf("-\n");
// }

// void	ft_zero_largeur_flag(char *argc, int *count_print)
// {
// 	(void)argc;
// 	(void)count_print;
// 	ft_printf("0\n");
// }
// void	ft_largeur_flag(char *argc, int *count_print, char *str, int *j)
// {
// 	(void)argc;
// 	(void)count_print;
// 	int	s;

// 	s = ft_char_to_int(str, j);
// 	ft_printf("'%d'\n", s);
// }

// int	ft_check_zero_flag(char *str, int pos)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '0' && i != pos)
// 			return (1);
// 		else
// 			return (0);
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_already_print(char *str, char c, int size)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] && i < size)
// 	{
// 		if (str[i] == c && (c > 57 || c < 48))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	strlen_type(const char *main_str)
// {
// 	char	*type;
// 	int		p;
// 	int		j;
// 	int		doublons;

// 	p = 0;
// 	doublons = 0;
// 	type = "cspdiuxX";
// 	while (main_str[p])
// 	{
// 		j = 0;
// 		if (ft_already_print((char *)main_str, main_str[p], p) == 1)
// 			doublons++;
// 		while (type[j])
// 		{
// 			if (main_str[p] == type[j] || main_str[p] == 37)
// 			{
// 				p++;
// 				return (p - doublons);
// 			}
// 			j++;
// 		}
// 		p++;
// 	}
// 	return (0);
// }

// char	*befor_type(const char *str, int *count_print)
// {
// 	(void)count_print;
// 	char	*s;
// 	int		j;
// 	int		i;
// 	int		size;

// 	i = 0;
// 	size = strlen_type(&str[i]);
// 	s = malloc(sizeof(char) * (size + 1));
// 	if (!s)
// 		return (NULL);
// 	j = 0;
// 	while (j < size)
// 	{
// 		while (ft_already_print(s, str[i], i) == 1)
// 			i++;
// 		s[j] = str[i];
// 		j++;
// 		i++;
// 	}
// 	s[j] = '\0';
// 	return (s);
// }

// void	ft_bonus(const char *main_str, int *i, int *count_print, va_list args)
// {
// 	char	*flags;
// 	int	size_flags;
// 	int		j;
// 	int	count;

// 	(*i)++;
// 	flags = befor_type(&main_str[*i], count_print);
// 	ft_printf("'%s'\n", flags);
// 	size_flags = ft_strlen(flags);
// 	j = 0;
// 	count = 0;
// 	while (j < size_flags)
// 	{
// 		if (flags[j] == '.')
// 			ft_point_flag(va_arg(args, char *), count_print, &flags[j], &j);
// 		if (flags[j] == '+')
// 			ft_sign_flag(va_arg(args, char *), count_print);
// 		if (flags[j] == ' ')
// 			ft_space_flag(va_arg(args, char *), count_print);
// 		if (flags[j] == '#')
// 			ft_prefix_flag(va_arg(args, char *), count_print);
// 		if (flags[j] == '-')
// 			ft_alignement_flag(va_arg(args, char *), count_print);
// 		if (flags[j] == '0' && ft_check_zero_flag(flags, j) == 0 && count++ < 1)
// 			ft_zero_largeur_flag(va_arg(args, char *), count_print);
// 		if (flags[j] >= '1' && flags[j] <= '9')
// 			ft_largeur_flag(va_arg(args, char *), count_print, &flags[j], &j);
// 		j++;
// 	}
// 	(* i) += size_flags;
// 	free(flags);
// }

void	ft_is_u(int argi, int *count_print)
{
	if (argi < 0)
		argi += 4294967296;
	ft_put_unsigned_nbr_fd(argi, 1);
	(*count_print) += ft_unsigned_intsize(argi);
}

void	ft_is_d_i(int argi, int *count_print)
{
	ft_putnbr_fd(argi, 1);
	(*count_print) += ft_intsize(argi);
}

void	ft_is_p(void *ptr, int *count_print)
{
	uintptr_t	addr;

	if (!ptr)
	{
		ft_print_str_count("(nil)", count_print);
		return ;
	}
	ft_print_str_count("0x", count_print);
	addr = (uintptr_t)ptr;
	ft_puthex_ptr(addr, count_print);
}

void	ft_percent(const char *main_str, int *i, int *count_print, va_list args)
{
	if (main_str[*i] == '%' && main_str[*i + 1] == 's')
		ft_print_str_count(va_arg(args, char *), count_print);
	else if (main_str[*i] == '%' && main_str[*i + 1] == 'c')
		ft_write_count(va_arg(args, int), count_print);
	else if (main_str[*i] == '%'
		&& (main_str[*i + 1] == 'd' || main_str[*i + 1] == 'i'))
		ft_is_d_i(va_arg(args, int), count_print);
	else if (main_str[*i] == '%' && main_str[*i + 1] == 'u')
		ft_is_u(va_arg(args, int), count_print);
	else if (main_str[*i] == '%' && main_str[*i + 1] == 'x')
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef", count_print);
	else if (main_str[*i] == '%' && main_str[*i + 1] == 'X')
		ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", count_print);
	else if (main_str[*i] == '%' && main_str[*i + 1] == '%')
		ft_write_count('%', count_print);
	else if (main_str[*i] == '%' && main_str[*i + 1] == 'p')
		ft_is_p(va_arg(args, char *), count_print);
	(*i)++;
}

int	ft_printf(const char *main_str, ...)
{
	va_list			args;
	int				count_print;
	int				i;

	va_start(args, main_str);
	i = 0;
	count_print = 0;
	while (main_str[i])
	{
		if (main_str[i] == '%')
			ft_percent(main_str, &i, &count_print, args);
		else
			ft_write_count(main_str[i], &count_print);
		i++;
	}
	va_end(args);
	return (count_print);
}
