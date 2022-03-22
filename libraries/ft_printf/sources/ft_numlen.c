/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nervin <nervin@student.42adel.org.au >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:19:58 by nervin            #+#    #+#             */
/*   Updated: 2021/11/29 12:57:13 by nervin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
ft_numlen
	Calculates the length of a number using a number and the initial length
	Appends the null terminating character to the end of the string
*/
char	*ft_numlen(unsigned long num, int *len)
{
	char	*str;

	while (num > 15)
	{
		num = num / 16;
		*len += 1;
	}
	str = malloc(sizeof(char) * (*len + 1));
	if (str == NULL)
		return (NULL);
	str[*len] = '\0';
	return (str);
}
