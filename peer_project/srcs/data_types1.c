/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_types1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 21:00:56 by spalmer           #+#    #+#             */
/*   Updated: 2020/07/08 18:12:11 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_o(t_result *res)
{
	if (res->flag_ll == 1)
		res->s = ft_itoa_base((unsigned long long int)(va_arg(res->factor,
		unsigned long long int)), 8, 0);
	else if (res->flag_l == 1)
		res->s = ft_itoa_base((unsigned long int)(va_arg(res->factor,
		unsigned long int)), 8, 0);
	else if (res->flag_hh == 1)
		res->s = ft_itoa_base((unsigned char)(va_arg(res->factor,
		unsigned int)), 8, 0);
	else if (res->flag_h == 1)
		res->s = ft_itoa_base((unsigned short int)(va_arg(res->factor,
		unsigned int)), 8, 0);
	else
		res->s = ft_itoa_base((unsigned int)(va_arg(res->factor,
		unsigned int)), 8, 0);
	res->spesial_symbols = "0";
	res->data_type = 'o';
	if (print_all(res) == -1)
		return (-1);
	free(res->s);
	return (0);
}

int	type_x(t_result *res)
{
	if (res->flag_ll == 1)
		res->s = ft_itoa_base((unsigned long long int)(va_arg(res->factor,
		unsigned long long int)), 16, 0);
	else if (res->flag_l == 1)
		res->s = ft_itoa_base((unsigned long int)(va_arg(res->factor,
		unsigned long int)), 16, 0);
	else if (res->flag_hh == 1)
		res->s = ft_itoa_base((unsigned char)(va_arg(res->factor,
		unsigned int)), 16, 0);
	else if (res->flag_h == 1)
		res->s = ft_itoa_base((unsigned short int)(va_arg(res->factor,
		unsigned int)), 16, 0);
	else
		res->s = ft_itoa_base((unsigned int)(va_arg(res->factor,
		unsigned int)), 16, 0);
	if ((ft_strcmp(res->s, "0") == 0))
		res->f_hash = 0;
	res->spesial_symbols = "0x";
	if (print_all(res) == -1)
		return (-1);
	free(res->s);
	return (0);
}

int	type_xx(t_result *res)
{
	if (res->flag_ll == 1)
		res->s = ft_itoa_base((unsigned long long int)(va_arg(res->factor,
		unsigned long long int)), 16, 1);
	else if (res->flag_l == 1)
		res->s = ft_itoa_base((unsigned long int)(va_arg(res->factor,
		unsigned long int)), 16, 1);
	else if (res->flag_hh == 1)
		res->s = ft_itoa_base((unsigned char)(va_arg(res->factor,
		unsigned int)), 16, 1);
	else if (res->flag_h == 1)
		res->s = ft_itoa_base((unsigned short int)(va_arg(res->factor,
		unsigned int)), 16, 1);
	else
		res->s = ft_itoa_base((unsigned int)(va_arg(res->factor,
		unsigned int)), 16, 1);
	if ((ft_strcmp(res->s, "0") == 0))
		res->f_hash = 0;
	res->spesial_symbols = "0X";
	if (print_all(res) == -1)
		return (-1);
	free(res->s);
	return (0);
}

int	type_u(t_result *res)
{
	if (res->flag_ll == 1)
		res->s = ft_itoa_base((unsigned long long int)(va_arg(res->factor,
		unsigned long long int)), 10, 0);
	else if (res->flag_l == 1)
		res->s = ft_itoa_base((unsigned long int)(va_arg(res->factor,
		unsigned long int)), 10, 0);
	else if (res->flag_hh == 1)
		res->s = ft_itoa_base((unsigned char)(va_arg(res->factor,
		unsigned int)), 10, 0);
	else if (res->flag_h == 1)
		res->s = ft_itoa_base((unsigned short int)(va_arg(res->factor,
		unsigned int)), 10, 0);
	else
		res->s = ft_itoa_base((unsigned int)(va_arg(res->factor,
		unsigned int)), 10, 0);
	res->data_type = 'u';
	if (print_all(res) == -1)
		return (-1);
	free(res->s);
	return (0);
}

int	print_all(t_result *res)
{
	res->wid_pres = check_width(&res);
	if (res->point == 1 && res->f_zero == 1)
		res->simvol = ' ';
	if (res->data_type != 'u' && res->f_hash == 1 && res->width != 0 &&
		res->point == 0 && res->f_zero == 1)
	{
		if (ft_putstr_check(res->spesial_symbols) == -1)
			return (-1);
		res->characters += ft_strlen(res->spesial_symbols);
		res->f_hash = 0;
		if (ft_strcmp(res->s, "0") == 0 && res->data_type == 'o')
			res->wid_pres++;
	}
	if (res->f_min == 1 && (print_tochnost(ft_strlen((res)->s), &res)) == -1)
		return (-1);
	if (res->width != 0 && print_probel_str(&res, res->simvol) == -1)
		return (-1);
	if (res->f_min == 0 && print_tochnost(ft_strlen((res)->s), &res) == -1)
		return (-1);
	return (0);
}
