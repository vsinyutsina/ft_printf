/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 01:43:26 by spalmer           #+#    #+#             */
/*   Updated: 2020/07/08 18:13:11 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_tochnost1(t_result **res)
{
	if (((*res)->data_type != 'o' && ((*res)->point == 1)
		&& ((*res)->width2 == 0) && (ft_strcmp((*res)->s, "0") == 0)) ||
		((*res)->data_type == 'o' && ((*res)->point == 1)
		&& ((*res)->width2 == 0) && (ft_strcmp((*res)->s, "0") == 0) &&
		(*res)->f_hash == 0))
		return (0);
	return (1);
}

int		print_tochnost(int sizenbr, t_result **res)
{
	int	i;

	i = 0;
	if (print_tochnost1(res) == 0)
		return (0);
	if ((ft_strcmp((*res)->s, "0") != 0) && (*res)->f_hash == 1)
	{
		if (ft_putstr_check((*res)->spesial_symbols) == -1)
			return (-1);
		(*res)->characters += ft_strlen((*res)->spesial_symbols);
		i += ft_strlen((*res)->spesial_symbols);
	}
	if ((*res)->width2 != 0)
	{
		while (((*res)->wid_pres - i++) > sizenbr)
		{
			if (write(1, "0", 1) < 0)
				return (-1);
			(*res)->characters++;
		}
	}
	if (ft_putstr_check((*res)->s) == -1)
		return (-1);
	(*res)->characters += sizenbr;
	return (0);
}

int		print_probel_str(t_result **res, char c)
{
	int	i;

	i = 0;
	while (((*res)->width - i) > (*res)->wid_pres)
	{
		if (write(1, &c, 1) < 0)
			return (-1);
		(*res)->characters++;
		i++;
	}
	return (0);
}

int		zero_check(t_result **res)
{
	if ((*res)->data_type != 'o' && ((*res)->point == 1) &&
		((*res)->width2 == 0) && (ft_strcmp((*res)->s, "0") == 0))
		return (0);
	if ((*res)->data_type == 'o' && ((*res)->point == 1) &&
		((*res)->width2 == 0) && (ft_strcmp((*res)->s, "0") == 0) &&
		(*res)->f_hash == 0)
		return (0);
	if ((*res)->data_type == 'o' && ((*res)->point == 1) &&
		((*res)->width2 == 0) && (ft_strcmp((*res)->s, "0") == 0) &&
		(*res)->f_hash == 1)
		return (1);
	if ((*res)->data_type == 'o' && ((*res)->point == 0) &&
		(ft_strcmp((*res)->s, "0") == 0) && (*res)->f_hash == 1)
		return (1);
	return (2);
}

int		check_width(t_result **res)
{
	int	cnt;
	int	check;

	cnt = 0;
	check = zero_check(res);
	if ((*res)->data_type == 'p' && ft_strcmp((*res)->s, "0") == 0 && \
			((*res)->width2 == 0) && ((*res)->point == 1))
		return (2);
	if (check == 0)
		return (0);
	if (check == 1)
		return (1);
	if ((*res)->width2 != 0)
		cnt = (*res)->width2;
	if (ft_strlen((*res)->s) > (size_t)(*res)->width2)
		cnt = ft_strlen((*res)->s);
	if ((*res)->f_hash == 1)
	{
		if ((*res)->data_type != 'o')
			cnt += (ft_strlen((*res)->spesial_symbols));
		else if (ft_strlen((*res)->s) + 1 > (size_t)(*res)->width2)
			cnt += 1;
	}
	return (cnt);
}
