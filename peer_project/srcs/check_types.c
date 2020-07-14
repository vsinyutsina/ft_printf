/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 23:39:29 by spalmer           #+#    #+#             */
/*   Updated: 2020/07/10 15:24:41 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_data_types1(t_result *res)
{
	if (res->flag_star == 1)
		flag_star(res);
	if (res->flag_star2 == 1)
		res->width2 = va_arg(res->factor, int);
}

int		check_data_types(char *c, t_result *res)
{
	check_data_types1(res);
	if ((c[(res)->cnt] == 'd' || c[(res)->cnt] == 'i') \
			&& type_d(res) == -1)
		return (-1);
	else if ((c[res->cnt] == 'f' || c[res->cnt] == 'F') \
	&& type_f(res) == -1)
		return (-1);
	else if (c[res->cnt] == 'p' && type_p(res) == -1)
		return (-1);
	else if (c[res->cnt] == 'o' && type_o(res) == -1)
		return (-1);
	else if (c[res->cnt] == 'x' && type_x(res) == -1)
		return (-1);
	else if (c[res->cnt] == 'X' && type_xx(res) == -1)
		return (-1);
	else if (c[res->cnt] == 'u' && type_u(res) == -1)
		return (-1);
	else if (c[res->cnt] == 's' && type_s(res) == -1)
		return (-1);
	else if (c[res->cnt] == 'c' && type_c(res) == -1)
		return (-1);
	else if (c[res->cnt] == '%' && type_pr(res) == -1)
		return (-1);
	return (res->characters);
}
