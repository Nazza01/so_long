/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nervin <nervin@student.42adel.org.au >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:58:58 by nervin            #+#    #+#             */
/*   Updated: 2021/11/29 13:13:47 by nervin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
ft_ishex
	Takes in the argcount struct and the character c
	Handles the unsigned integer representation using Ascii Hex (16)
	Appends 0 until the next decimal and represents it using uppercase or 
	lowercase Hex.
*/
void	ft_ishex(t_print *argcount, char c)
{
	unsigned int	num;
	int				len;
	char			*str;

	num = va_arg(argcount->args, unsigned int);
	len = 1;
	str = ft_numlen(num, &len);
	len--;
	while (len >= 0)
	{
		if (num % 16 < 10)
			str[len] = '0' + (num % 16);
		else if (c == 'x')
			str[len] = 'a' - 10 + (num % 16);
		else if (c == 'X')
			str[len] = 'A' - 10 + (num % 16);
		num = num / 16;
		len--;
		argcount->total++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}
