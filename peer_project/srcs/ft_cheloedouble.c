/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheloedouble.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 13:53:03 by heantoni          #+#    #+#             */
/*   Updated: 2020/07/08 18:12:31 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	expo_not(t_double_l *new)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	while (i < -(new->expo))
	{
		j = 1;
		while (j < 800)
		{
			b = new->mass1[j] % 2;
			new->mass1[j] = new->mass1[j] / 2;
			if (b == 1)
				new->mass1[j - 1] += 50000000;
			j++;
		}
		i++;
	}
}

void	expo_tru(t_double_l *new)
{
	if (new->expo < 64)
	{
		new->ch = new->mant >> (64 - new->expo);
		zap2(new);
	}
	else
	{
		new->ch = new->mant;
		zap2(new);
		while ((new->expo - 64) > 0)
		{
			zap22(new);
			new->expo--;
		}
	}
}

void	zap(t_double_l *new)
{
	int	i;

	i = 0;
	new->ch1[799] = 54775808;
	new->ch1[798] = 33720368;
	new->ch1[797] = 922;
	while (i < 800)
	{
		new->mass1[i] = 0;
		new->mass2[i] = 0;
		new->ch2[i] = 0;
		if (i < 797)
			new->ch1[i] = 0;
		i++;
	}
	new->mass1[799] = 50000000;
}

int		ft_cheloedouble1(t_result *res, t_double_l *new, int k)
{
	if (res->f_plus == 1 && new->sign == 0 && write(1, "+", 1) < 0)
		return (-1);
	if (res->f_min == 0 && res->f_zero == 1 && new->sign == 0)
		if (print_probel(res->m + res->width2, res, res->simvol) < 0)
			return (-1);
	if (new->sign == -1 && k == 0)
		if (write(1, "-", 1) < 0)
			return (-1);
	if (res->f_min == 0 && res->f_zero == 1 && new->sign == -1)
		if (print_probel(res->m + res->width2, res, res->simvol) < 0)
			return (-1);
	if (k == 0)
	{
		if (write_drob(new, res) < 0)
			return (-1);
		if (res->width2 == 0 && res->f_hash == 1)
			if (write(1, ".", 1) < 0)
				return (-1);
	}
	else
	{
		if (ft_putstr_check(res->ss) < 0)
			return (-1);
	}
	return (1);
}

int		ft_cheloedouble(t_result *res, t_double_l *new, int k)
{
	if (res->f_min == 1 && res->f_zero == 1)
		res->simvol = ' ';
	if (res->flag_lf == 0 && res->f < 0 && k == 0)
		res->f *= -1;
	if (res->flag_lf == 1 && res->ff < 0 && k == 0)
		res->ff *= -1;
	if (res->f_plus == 1 && new->sign == 0)
		res->width -= 1;
	if (k == 0)
		double_cel1(res, new);
	if (res->f_prob == 1 && new->sign == 0 && res->f_plus == 0 && new->v == 0)
	{
		res->width -= 1;
		if (write(1, " ", 1) < 0)
			return (-1);
	}
	if (res->f_min == 0 && res->f_zero != 1)
		if (print_probel(res->m + res->width2, res, res->simvol) < 0)
			return (-1);
	if (ft_cheloedouble1(res, new, k) < 0)
		return (-1);
	if (res->f_min == 1)
		print_probel(res->m + res->width2, res, res->simvol);
	return (1);
}
