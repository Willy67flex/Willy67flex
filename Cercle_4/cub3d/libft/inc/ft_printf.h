/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-moig <ele-moig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:46:38 by ele-moig          #+#    #+#             */
/*   Updated: 2025/10/30 15:12:49 by ele-moig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>

# define LOW_HEX_BASE "0123456789abcdef"
# define UPP_HEX_BASE "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
void	ft_handle_type(char flag, va_list args, int *count);
void	ft_printchar(char c, int *count);
void	ft_printstr(char *str, int *count);
void	ft_printnbr_base(int nbr, char *base, int *count);
void	ft_printnbr_hexa(unsigned int nbr, char *base, int *count);
void	ft_printnbr_u(unsigned int nbr, char *base, int *count);
void	ft_print_ptr(void *ptr, int *count);
int		ft_intsize(int nbr);
size_t	ft_strlen(const char *str);

#endif