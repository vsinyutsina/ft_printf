/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forma_chesla.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:11:15 by heantoni          #+#    #+#             */
/*   Updated: 2020/07/08 18:12:26 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							ft_pow(int nbr, int k)
{
	int						i;
	int						n;

	n = 1;
	i = 0;
	while (i < k)
	{
		n = n * nbr;
		i++;
	}
	return (n);
}

int							proverka1(t_result *res, t_double_l new)
{
	if (new.expo == 16385)
	{
		res->characters = 0;
		if ((new.mant >> 63 == 1) && \
				((new.mant << 1) | 0x0000000000000000) == 0)
			res->characters = write_inf(res, new.sign);
		else
		{
			if (((new.mant << 1 << 1) | 0x0000000000000000) != 0)
			{
				res->ss = "nan\0";
				res->characters = 3;
				res->f_plus = 0;
				res->f_prob = 0;
			}
		}
		res->m = (res)->characters;
		res->width2 = 0;
		res->f_zero = 0;
		res->simvol = ' ';
		return (1);
	}
	return (0);
}
