/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 21:01:27 by spalmer           #+#    #+#             */
/*   Updated: 2020/07/09 00:52:08 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type_p(t_result *res)
{
	if (ft_putstr_check(res->spesial_symbols) == -1)
		return (-1);
	res->wid_pres -= 2;
	res->characters += ft_strlen(res->spesial_symbols);
	res->width -= 2;
	res->f_hash = 0;
	if (print_tochnost(ft_strlen((res)->s), &res) == -1)
		return (-1);
	return (0);
}

int	type_p(t_result *res)
{
	res->s = ft_itoa_base((unsigned long int)(va_arg(res->factor,
		unsigned long int)), 16, 0);
	res->spesial_symbols = "0x";
	res->data_type = 'p';
	res->f_hash = 1;
	res->wid_pres = check_width(&res);
	if (res->point == 1 && res->f_zero == 1)
		res->simvol = ' ';
	if (res->f_min == 1 && check_type_p(res) == -1)
		return (-1);
	if (res->width != 0 && print_probel_str(&res, res->simvol) == -1)
		return (-1);
	if (res->f_min == 0 && check_type_p(res) == -1)
		return (-1);
	free(res->s);
	return (0);
}

int	type_s(t_result *res)
{
	res->s = va_arg(res->factor, char*);
	if (res->width2 < 0)
	{
		res->point = 0;
		res->width2 = 0;
	}
	if (res->s == NULL)
		res->s = "(null)";
	res->wid_pres = ft_strlen(res->s);
	if (res->f_min == 1 && res->f_zero == 1)
		res->simvol = ' ';
	if (res->point == 1 && (ft_strlen(res->s) > (size_t)res->width2))
		res->wid_pres = res->width2;
	if (res->f_min == 1 && ft_putstr_n_check(res->s, res->wid_pres) == -1)
		return (-1);
	if (print_probel_str(&res, res->simvol) == -1)
		return (-1);
	res->characters += res->wid_pres;
	if (res->f_min == 0 && ft_putstr_n_check(res->s, res->wid_pres) == -1)
		return (-1);
	return (0);
}

int	type_c(t_result *res)
{
	res->c = (unsigned char)va_arg(res->factor, unsigned);
	res->wid_pres = 1;
	if (res->f_min == 1 && ft_putchar_check(res->c) == -1)
		return (-1);
	if (print_probel_str(&res, res->simvol) == -1)
		return (-1);
	res->characters += 1;
	if (res->f_min == 0 && ft_putchar_check(res->c) == 1)
		return (-1);
	return (0);
}

int	type_pr(t_result *res)
{
	res->c = '%';
	res->wid_pres = 1;
	if (res->f_min == 1 && res->f_zero == 1)
		res->simvol = ' ';
	if (res->f_min == 1 && ft_putchar_check(res->c) == -1)
		return (-1);
	if (print_probel_str(&res, res->simvol) == -1)
		return (-1);
	res->characters += 1;
	if (res->f_min == 0 && ft_putchar_check(res->c) == -1)
		return (-1);
	return (0);
}
