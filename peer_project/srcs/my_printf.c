/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:03:42 by heantoni          #+#    #+#             */
/*   Updated: 2020/07/10 15:18:02 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			clean(t_result *res)
{
	if (res->s != NULL)
		free(res->s);
	if (res->spesial_symbols != NULL)
		free(res->spesial_symbols);
}

void			setup(t_result *res)
{
	res->width = 0;
	res->width2 = 0;
	res->wid_pres = 0;
	res->f_min = 0;
	res->f_plus = 0;
	res->f_prob = 0;
	res->f_zero = 0;
	res->f_hash = 0;
	res->simvol = ' ';
	res->point = 0;
	res->line_length = 0;
	res->flag_l = 0;
	res->flag_ll = 0;
	res->flag_j = 0;
	res->flag_h = 0;
	res->flag_hh = 0;
	res->flag_star = 0;
	res->flag_star2 = 0;
	res->flag_lf = 0;
	res->m = 0;
	res->spesial_symbols = "";
	res->data_type = '\0';
	res->color = 0;
}

int				check_symbol(t_result *res, char *c)
{
	if (c[res->cnt] != '%')
	{
		if (write(1, &c[res->cnt], 1) < 0)
			return (-1);
		res->characters++;
	}
	else if (c[res->cnt + 1] &&
	c[res->cnt + 1] == '%')
	{
		if (write(1, &c[res->cnt], 1) < 0)
			return (-1);
		res->cnt++;
		res->characters++;
	}
	else
		return (1);
	return (0);
}

void			setup_first(t_result *res, char *c)
{
	res->line_length = ft_strlen(c);
	res->c_length = res->line_length;
	res->error_str = "";
	res->cnt = 0;
}

int				ft_printf(const char *format, ...)
{
	t_result	res;
	char		*c;
	const char	*temp;
	int			k;

	res.characters = 0;
	va_start(res.factor, format);
	temp = format;
	c = ft_strdup(temp);
	setup_first(&res, c);
	while (c[res.cnt])
	{
		setup(&res);
		k = check_symbol(&res, c);
		if (k < 0)
			return (-1);
		if (k == 1)
			analysis(c, &res);
		res.cnt++;
	}
	free(c);
	va_end(res.factor);
	return (res.characters);
}
