/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathanael <nervin@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:45:03 by nervin            #+#    #+#             */
/*   Updated: 2022/03/21 03:19:04 by Nathanael        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdarg.h>
# include	<unistd.h>
# include	<stdlib.h>

typedef struct s_printf
{
	va_list	args;
	int		total;
}	t_print;

void	ft_check(const char c, t_print *argcount);
void	ft_ischaracter(t_print *argcount);
void	ft_ishex(t_print *argcount, char c);
void	ft_isint(t_print *argcount);
void	ft_isperc(t_print *argcount);
void	ft_ispointer(t_print *argcount);
void	ft_isstring(t_print *argcount);
void	ft_isunsigned(t_print *argcount);
char	*ft_itoa(int n);
char	*ft_numlen(unsigned long num, int *len);
int		ft_printf(const char *formatting, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	pf_strlen(const char *str);

#endif