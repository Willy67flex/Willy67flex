/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whollebe <whollebe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:24:13 by whollebe          #+#    #+#             */
/*   Updated: 2025/10/22 09:41:41 by whollebe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdint.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);

int		ft_printf(const char *main_str, ...);
void	ft_putnbr_base(unsigned int nbr, char *base, int *count_print);
void	ft_put_unsigned_nbr_fd(unsigned int n, int fd);
void	ft_print_str_count(char *str, int *count_print);
int		ft_unsigned_intsize(unsigned int nbr);
void	ft_write_count(int i, int *count_print);
int		ft_intsize(int nbr);
void	ft_puthex_ptr(uintptr_t n, int *count_print);
void	ft_bonus(const char *main_str, int *i, int *count_print, va_list args);
int		ft_strnlen( int size);

#endif // FT_PRINTF_H
