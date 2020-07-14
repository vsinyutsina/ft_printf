/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:59:49 by heantoni          #+#    #+#             */
/*   Updated: 2020/07/07 14:02:02 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_0(int nbr)
{
	int	k;

	k = ft_sizenbr(nbr);
	while (k < 8)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		k++;
	}
	return (1);
}

int		write_double(t_double_l *new, t_result *res)
{
	int	i;

	i = 799 - ((res->m + 8 - 1) / 8) + 1;
	if (ft_putnbr_check(new->ch2[i]) < 0)
		return (-1);
	i++;
	while (i < 800)
	{
		if (print_0(new->ch2[i]) < 0)
			return (-1);
		if (ft_putnbr_check(new->ch2[i]) < 0)
			return (-1);
		i++;
	}
	return (1);
}

int		write_drob1(int *k, int kol, t_double_l *new, t_result *res)
{
	int	i;

	i = 0;
	while (i < kol)
	{
		new->v = 0;
		while (new->v < 8 - ft_sizenbr(new->mass2[*k]))
		{
			if (write(1, "0", 1) < 0)
				return (-1);
			new->v++;
		}
		if (ft_putnbr_check(new->mass2[*k]) < 0)
			return (-1);
		i++;
		(*k)--;
	}
	while (res->width2 > 6400)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		res->width2--;
	}
	return (1);
}

int		write_drob2(t_double_l *new, t_result *res, int kol, int k)
{
	new->v = 0;
	if (kol != 800 && ft_sizenbr(new->mass2[k]) < 8)
		while ((new->v < (8 - ft_sizenbr(new->mass2[k])) && \
					new->v + 1 < (res->width2 % 8)))
		{
			if (write(1, "0", 1) < 0)
				return (-1);
			new->v++;
		}
	return (1);
}

int		write_drob(t_double_l *new, t_result *res)
{
	int	k;
	int	kol;

	k = 799;
	if (new->expo <= 0)
		res->m = 1;
	if (write_double(new, res) < 0)
		return (-1);
	if (res->width2 != 0)
		if (write(1, ".", 1) < 0)
			return (-1);
	kol = res->width2 / 8;
	if (kol > 800)
		kol = 800;
	if (write_drob1(&k, kol, new, res) < 0)
		return (-1);
	if (write_drob2(new, res, kol, k) < 0)
		return (-1);
	if (kol != 800 && (kol = res->width2 % 8) != 0)
		if (ft_putnbr_check(new->mass2[k] / ft_pow(10, (8 - kol))) < 0)
			return (-1);
	return (1);
}
