/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischaracter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nervin <nervin@student.42adel.org.au >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:58:56 by nervin            #+#    #+#             */
/*   Updated: 2021/11/29 12:43:06 by nervin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
ft_ischaracter
	Outputs the current character on standard output and increments the counter
*/
void	ft_ischaracter(t_print *argcount)
{
	ft_putchar_fd(va_arg(argcount->args, int), 1);
	argcount->total++;
}
