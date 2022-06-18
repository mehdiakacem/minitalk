/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 13:50:56 by makacem           #+#    #+#             */
/*   Updated: 2022/01/06 15:50:20 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putnbrhexa(unsigned long int nb);
int		ft_putnbrhexaup(unsigned long int nb);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putnbr(long int n);
int		ft_putstr(char *s);

#endif
