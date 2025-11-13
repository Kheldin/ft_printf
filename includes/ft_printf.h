/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacherch <kacherch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:13:04 by kacherch          #+#    #+#             */
/*   Updated: 2025/11/13 16:23:15 by kacherch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...)
	__attribute__ ((format (printf, 1, 2)));
int	do_operation(char c, va_list args, int *counter);
int	ft_putchar_printf(char c, int *counter);
int	ft_putstr_printf(char *str, int *counter);
int	ft_putnbr_printf(long nb, int *counter);
int	print_unsigned(unsigned int nb, int *counter);
int	print_hexl(unsigned int nb, int *counter);
int	print_hexu(unsigned int nb, int *counter);
int	t_strlen_printf(const char *str);

#endif