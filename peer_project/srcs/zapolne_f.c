/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zapolne_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:53:36 by heantoni          #+#    #+#             */
/*   Updated: 2020/07/05 17:59:21 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zap_ch2(t_double_l *new)
{
	int	i;

	i = 799;
	new->v = 0;
	while (i >= 0)
	{
		new->ch2[i] += new->ch1[i] + new->v;
		if (new->ch2[i] > 99999999)
		{
			new->ch2[i] %= 100000000;
			new->v = 1;
		}
		i--;
	}
}

void	zap_ch1(t_double_l *new)
{
	int	i;

	i = 799;
	new->v = 0;
	while (i > 0)
	{
		new->ch1[i] = new->ch1[i] * 2 + new->v;
		if (new->ch1[i] > 99999999)
		{
			new->ch1[i] %= 100000000;
			new->v = 1;
		}
		else
			new->v = 0;
		i--;
	}
}

void	zap2(t_double_l *new)
{
	int	i;

	i = 799;
	while (new->ch != 0)
	{
		new->ch2[i] = new->ch % 100000000;
		new->ch /= 100000000;
		i--;
	}
}

void	zap_mass2(t_double_l *new)
{
	int	j;

	j = 0;
	new->v = 0;
	while (j < 800)
	{
		new->mass2[j] += new->mass1[j] + new->v;
		if (new->mass2[j] > 99999999)
		{
			new->mass2[j] %= 100000000;
			new->v = 1;
		}
		else
			new->v = 0;
		j++;
	}
}

void	zap22(t_double_l *new)
{
	int	i;

	i = 799;
	new->v = 0;
	while (i >= 0)
	{
		new->ch2[i] = (new->ch2[i]) * 2 + new->v;
		if ((new->ch2[i]) > 99999999)
		{
			new->ch2[i] %= 100000000;
			new->v = 1;
		}
		else
			new->v = 0;
		i--;
	}
}
