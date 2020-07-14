/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_probel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:51:49 by heantoni          #+#    #+#             */
/*   Updated: 2020/07/08 17:51:50 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_prob_zero(t_result *res, int k, int flag)
{
	int		i;
	int		kol;
	int		p;

	i = 0;
	flag = 11;
	if (res->width2 > k)
		kol = res->width2 - k;
	else
		kol = 0;
	p = 0;
	while (p < kol)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		p++;
	}
	return (1);
}

int		print_prob_int(t_result *res, int k, int flag)
{
	int		l;

	if (res->f_plus == 1 && (res)->m == 0)
		res->width -= 1;
	if ((res->width2 > k) && flag == 0)
		l = res->width - res->width2;
	if ((res->width2 > k) && flag != 0)
		l = res->width - res->width2 - 1;
	if (res->width2 <= k)
	{
		if (flag == 0)
			l = res->width - k;
		else
			l = res->width - k - 1;
	}
	if (res->width != 0 && res->width2 == 0 && \
			res->d == 0 && res->point == 1)
		l++;
	while (l > 0)
	{
		if (write(1, &(res->simvol), 1) < 0)
			return (-1);
		l--;
	}
	return (1);
}

int		print_probel(int sizenbr, t_result *res, char c)
{
	int	k;

	k = sizenbr;
	if (res->width2 != 0)
		sizenbr++;
	while (sizenbr < res->width)
	{
		if (write(1, &c, 1) < 0)
			return (-1);
		sizenbr++;
		res->characters++;
	}
	return (0);
}

int		write_inf(t_result *res, int s)
{
	if (s == -1)
	{
		res->ss = "-inf\0";
		res->f_plus = 0;
		res->f_prob = 0;
		res->characters = 1;
	}
	else
		(res)->ss = "inf\0";
	(res)->characters += 3;
	return (res->characters);
}
