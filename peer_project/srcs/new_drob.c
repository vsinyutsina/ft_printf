/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_drob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:51:45 by heantoni          #+#    #+#             */
/*   Updated: 2020/07/05 17:52:53 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	drob_double(t_double_l *new)
{
	int	j;
	int	b;

	while (new->drob != 0)
	{
		new->f = (new->drob >> 63) & 1;
		new->drob = new->drob << 1;
		if (new->f == 1)
			zap_mass2(new);
		j = 0;
		while (j < 800)
		{
			b = new->mass1[j] % 2;
			new->mass1[j] = new->mass1[j] / 2;
			if (b == 1)
				new->mass1[j - 1] += 50000000;
			j++;
		}
	}
}

void	double_cel1(t_result *res, t_double_l *new)
{
	zap(new);
	if (new->expo != -16382)
	{
		if (new->expo > 0)
		{
			expo_tru(new);
			if (new->expo < 64)
				new->drob = new->mant << new->expo;
			else
				new->drob = 0;
		}
		else
		{
			if (new->expo <= 0)
			{
				expo_not(new);
				new->drob = new->mant;
			}
		}
		drob_double(new);
		res->m = okrug_new(new, res);
	}
	else
		res->m = 1;
}
