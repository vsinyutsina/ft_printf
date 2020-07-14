/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 14:25:19 by heantoni          #+#    #+#             */
/*   Updated: 2020/07/08 18:11:58 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	characters_int1(t_result *res)
{
	if (res->width2 >= res->width && res->width2 != 0 && \
	(res->width2 >= (res)->line_length))
		if ((res)->m == 0)
			res->characters += (res)->width2;
		else
			res->characters += (res)->width2 + 1;
	else
	{
		if (res->flag_l == 0 && res->flag_ll == 0 && res->d == 0 && \
				res->width == 0 && res->width2 == 0 && res->f_plus == 0 && \
				res->f_prob == 0 && res->point == 0 && res->line_length == 0)
			res->characters += 1;
		else
		{
			if (res->line_length > res->width2 && res->line_length > res->width)
				res->characters += res->line_length;
			else
			{
				if (res->d == 0 && res->f_plus == 1)
					res->characters += 1;
			}
		}
	}
}

void	characters_int(t_result *res)
{
	if ((res)->d == 0)
		(res)->line_length = 0;
	if ((res)->m == 0 && (res)->f_prob == 1 && (res)->f_plus != 1 \
			&& ((res)->width < (res)->width2 || (res)->width == 0))
		(res)->characters += 1;
	if (((res)->width <= (res)->line_length) && (res)->f_plus == 1 \
			&& (res)->m == 0)
		(res)->characters += 1;
	if (((res)->width > (res)->width2) && \
			((res)->width >= (res)->line_length))
		(res)->characters += (res)->width;
	else
		characters_int1(res);
}
