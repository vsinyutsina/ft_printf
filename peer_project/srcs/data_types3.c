/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 21:09:26 by spalmer           #+#    #+#             */
/*   Updated: 2020/07/08 17:58:01 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				check_float_flags(t_result *res, t_double_l new, int k)
{
	if (res->point == 0 && k == 0)
		res->width2 = 6;
	if (res->f_hash == 1 && res->width2 == 0)
	{
		res->width2 = 0;
		res->characters += 1;
		res->width -= 1;
	}
	if (res->width2 != 0)
		res->characters += res->width2 + 1;
	if (res->f_plus == 1 && res->f >= 0)
		res->characters += 1;
	if (res->f_prob == 1 && res->f >= 0)
		res->characters += 1;
	if (new.sign == -1 && k == 0)
	{
		res->characters += 1;
		res->width -= 1;
	}
}

void				zapolnene_new(t_result *res, t_double_l *new1)
{
	t_big_double	cheslo;

	if (res->flag_lf == 1)
		cheslo.var = res->ff;
	else
		cheslo.var = res->f;
	new1->mant = cheslo.new.mantisa;
	new1->expo = cheslo.new.exponenta - 16382;
	new1->sign = cheslo.new.sign;
	new1->f = 0;
	new1->v = 0;
}

int					type_f(t_result *res)
{
	int			k;
	t_double_l	new;

	if (res->width2 < 0)
		res->width2 = 6;
	if (res->flag_lf == 1)
		res->ff = va_arg((res)->factor, long double);
	else
		res->f = va_arg((res)->factor, double);
	zapolnene_new(res, &new);
	k = proverka1(res, new);
	check_float_flags(res, new, k);
	if (ft_cheloedouble(res, &new, k) < 0)
		return (-1);
	res->characters += res->m;
	return (res->characters);
}

void				type_d1(t_result *res)
{
	if ((res)->flag_h == 1)
		(res)->d = (short int)(va_arg((res)->factor, int));
	else if ((res)->flag_hh == 1)
		(res)->d = (signed char)va_arg((res)->factor, int);
	else if ((res)->flag_ll == 1)
		(res)->d = (long long int)va_arg((res)->factor, long long int);
	else if ((res)->flag_l == 1)
		(res)->d = (long int)va_arg((res)->factor, long int);
	else
		(res)->d = (int)va_arg((res)->factor, int);
}

int					type_d(t_result *res)
{
	type_d1(res);
	if (res->width2 < 0)
	{
		if (res->d < 0)
			res->width2 = ft_sizenbr(res->d) - 1;
		else
			res->width2 = ft_sizenbr(res->d);
	}
	if (-res->d == -2147483648 && res->flag_l == 0 && res->flag_ll == 0)
		res->d = -2147483648;
	if (res->d < 0)
		res->m = 1;
	res->line_length = ft_lsizenbr((res)->d);
	characters_int(res);
	if (number_int(res) < 0)
		return (-1);
	return (res->characters);
}
