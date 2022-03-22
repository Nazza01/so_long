/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isperc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nervin <nervin@student.42adel.org.au >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:59:05 by nervin            #+#    #+#             */
/*   Updated: 2021/11/29 13:18:19 by nervin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
ft_isperc
	Outputs a percent symbol to the standard output
	Increments the argument counter
*/
void	ft_isperc(t_print *argcount)
{
	ft_putchar_fd('%', 1);
	argcount->total++;
}
