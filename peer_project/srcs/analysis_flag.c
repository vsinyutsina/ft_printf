/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:23:58 by spalmer           #+#    #+#             */
/*   Updated: 2020/07/10 15:35:05 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_color(char *c, t_result *res)
{
	if (c[res->cnt] == '{' && c[res->cnt + 2] == '}')
	{
		if (c[res->cnt + 1] == 'R')
			write(1, RED, 5);
		else if (c[res->cnt + 1] == 'G')
			write(1, GREEN, 5);
		else if (c[res->cnt + 1] == 'Y')
			write(1, YELLOW, 5);
		else if (c[res->cnt + 1] == 'B')
			write(1, BLUE, 5);
		else if (c[res->cnt + 1] == 'W')
			write(1, WHITE, 4);
		res->color = 1;
	}
}

void	zero_color(t_result *res)
{
	if (res->color == 1)
	{
		write(1, WHITE, 4);
		res->color = 0;
	}
}

void	flag_star(t_result *res)
{
	res->width = va_arg((res)->factor, int);
	if (res->width < 0)
	{
		res->f_min = 1;
		res->width = -res->width;
	}
}

void	check_error(t_result *res, char *c, int error_begin)
{
	res->error_str = ft_strsub(c, error_begin, \
		res->c_length - error_begin);
	if (ft_putstr_check(res->error_str) == -1)
		res->characters = -1;
	res->characters += ft_strlen(res->error_str);
	res->cnt += ft_strlen(res->error_str) - 1;
	free(res->error_str);
}
