/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:18:29 by heantoni          #+#    #+#             */
/*   Updated: 2020/07/08 18:12:37 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		number_int3(t_result *res, int *k, char **s1)
{
	if ((res)->flag_l == 0 && (res)->flag_ll == 0)
	{
		*s1 = ft_itoa((res)->d);
		*k = ft_lsizenbr((res)->d);
	}
	else
	{
		*s1 = ft_llitoa((res)->d);
		*k = ft_llsizenbr((res)->d);
	}
}

int			number_int1(t_result *res, int *k, char **s1)
{
	number_int3(res, k, s1);
	if ((res)->m == 1 && (res)->f_zero == 1)
		if (write(1, "-", 1) < 0)
			return (-1);
	if (((res)->width > (res)->width2) && ((res)->width > *k) && \
			(res)->f_min != 1)
		if (print_prob_int(res, *k, (res)->m) < 0)
			return (-1);
	if ((res)->m == 1 && (res)->f_zero == 0)
		if (write(1, "-", 1) < 0)
			return (-1);
	if ((res)->width > (res)->line_length && (res)->f_plus == 1 \
			&& (res)->f_zero != 1 && (res)->m == 0)
		if (write(1, "+", 1) < 0)
			return (-1);
	if ((res)->width2 != 0)
		if (print_prob_zero(res, *k, (res)->m) < 0)
			return (-1);
	if (!((res)->d == 0 && (res)->width2 == 0) || (res)->point == 0)
		if (ft_putstr_check(*s1) < 0)
			return (-1);
	free(*s1);
	return (1);
}

int			number_int2(t_result *res)
{
	if ((res)->f_plus == 1 && ((((res)->width <= (res)->width2) && \
					(res)->m == 0) || ((res)->m == 0 && (res)->f_min != 1 \
						&& ((res)->width - 1 <= (res)->width2 \
							|| (res)->f_zero == 1))))
		if (write(1, "+", 1) < 0)
			return (-1);
	if ((res)->m == 1)
	{
		if ((res)->flag_l == 0 && (res)->flag_ll == 0)
			(res)->d = -((res)->d);
		else
		{
			if ((res)->flag_ll == 1)
				(res)->d = -((res)->d);
			else
				(res)->d = -((res)->d);
		}
	}
	return (1);
}

int			number_int(t_result *res)
{
	int		k;
	char	*s1;

	s1 = NULL;
	if (((res)->f_plus == 1 && (res)->f_min == 1 && (res)->f_zero == 1) \
			|| ((res)->f_zero == 1 && \
				((res)->point == 1 || (res)->f_min == 1)))
		(res)->simvol = ' ';
	if ((res)->f_zero == 1 && ((res)->point == 1 || (res)->f_min == 1))
		(res)->f_zero = 0;
	if ((res)->f_prob == 1 && (res)->m == 0 && (res)->f_plus != 1)
	{
		(res)->width -= 1;
		if (write(1, " ", 1) < 0)
			return (-1);
	}
	if (number_int2(res) < 0)
		return (-1);
	if (number_int1(res, &k, &s1) < 0)
		return (-1);
	if (((res)->width > (res)->width2) && ((res)->width > k) && \
			(res)->f_min == 1)
		if (print_prob_int(res, k, (res)->m) < 0)
			return (-1);
	return (1);
}
