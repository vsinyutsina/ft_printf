/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:36:12 by heantoni          #+#    #+#             */
/*   Updated: 2020/06/29 01:55:21 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_check(int n)
{
	if (n == -2147483648 && ft_putstr_check("-2147483648") == -1)
		return (-1);
	else if (n != -2147483648)
	{
		if (n < 0)
		{
			if (ft_putchar_check('-') == -1)
				return (-1);
			n = n * (-1);
		}
		if (n != 0)
		{
			if (n / 10 != 0)
				if (ft_putnbr_check(n / 10) == -1)
					return (-1);
			if (ft_putchar_check(n % 10 + '0') == -1)
				return (-1);
		}
		else if (ft_putchar_check('0') == -1)
			return (-1);
	}
	return (0);
}
