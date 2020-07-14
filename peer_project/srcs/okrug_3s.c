/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   okrug_3s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:22:42 by heantoni          #+#    #+#             */
/*   Updated: 2020/07/06 15:25:39 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		us1(t_double_l *new, t_result *res)
{
	int k;

	k = new->mass2[799 - (res->width2 / 8)] % \
				ft_pow(10, (8 - (res->width2 % 8))) \
				/ ft_pow(10, (7 - (res->width2 % 8)));
	return (k);
}

int		pred(t_double_l *new, t_result *res)
{
	int k;

	k = 0;
	if (res->width2 % 8 != 1)
		k = new->mass2[799 - (res->width2 / 8)] % \
				ft_pow(10, (8 - (res->width2 % 8))) \
				/ ft_pow(10, (7 - (res->width2 % 8)));
	else
	{
		if ((799 - res->width2 / 8) != 799)
			k = new->mass2[799 - (res->width2 / 8) + 1] % 10;
	}
	return (k);
}

int		not_one(t_double_l *new, t_result *res)
{
	int k;
	int i;

	k = 0;
	i = 0;
	if ((new->mass2[799 - (res->width2 / 8)] % \
				ft_pow(10, 8 - res->width2 % 8)) != 0)
		k = 1;
	while (i < 799 - (res->width2 / 8) && k == 0)
	{
		if (new->mass2[i] != 0)
			k = 1;
		i++;
	}
	return (k);
}

int		okrug_3s(t_double_l *new, t_result *res)
{
	int i;

	i = 0;
	if (us1(new, res) > 5 || (us1(new, res) == 5 && \
	((pred(new, res) % 2 != 0) || (not_one(new, res) == 1))))
	{
		new->mass2[799 - (res->width2 / 8)] += \
			ft_pow(10, 8 - (res->width2 % 8));
		if (new->mass2[799 - (res->width2 / 8)] > 99999999)
		{
			new->mass2[799 - (res->width2 / 8)] %= 100000000;
			new->v = 1;
			i = 1;
		}
	}
	return (i);
}
