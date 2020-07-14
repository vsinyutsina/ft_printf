/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   okrug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:16:34 by heantoni          #+#    #+#             */
/*   Updated: 2020/07/05 16:22:00 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	okrug1(t_result *res, t_double_l *new, int i)
{
	while (new->v == 1 && (799 - (res->width2 / 8) + i) < 800)
	{
		new->mass2[799 - (res->width2 / 8) + i] += 1;
		if (new->mass2[799 - (res->width2 / 8) + i] == 1000000000)
		{
			new->mass2[799 - (res->width2 / 8) + i] = 0;
			new->v = 11;
		}
		else
			new->v = 0;
		i++;
	}
	if (new->v == 1)
		new->ch2[799] += 1;
}

int		okrug_ch(t_double_l *new)
{
	int	i;
	int k;

	i = 799;
	while (i > 0 && new->ch2[i] > 99999999)
	{
		new->ch2[i] = 0;
		new->ch2[i - 1] += 1;
		i--;
	}
	i = 0;
	k = 799;
	while (i < 800 && k == 799)
	{
		if (new->ch2[i] != 0)
			k = i;
		i++;
	}
	return ((799 - k) * 8 + ft_sizenbr(new->ch2[k]));
}

void	okrug_1s(t_double_l *new)
{
	int i;
	int	k;

	i = 0;
	k = 0;
	while (i < 799 && k == 0)
	{
		if (new->mass2[i] > 0)
			k = 1;
		i++;
	}
	if (new->mass2[799] > 50000000)
		new->ch2[799] += 1;
	else
	{
		if (new->mass2[799] == 50000000 && (new->ch2[799] % 2 != 0 || \
		k == 1))
			new->ch2[799] += 1;
	}
}

int		okrug_2s(t_double_l *new, t_result *res)
{
	int	i;
	int k;

	i = 0;
	k = 0;
	while (i < (799 - (res->width2 / 8)) && k == 0)
	{
		if (new->mass2[i] != 0)
			k = 1;
		i++;
	}
	new->v = 0;
	if ((new->mass2[799 - (res->width2 / 8)] > 50000000) || \
			(new->mass2[799 - (res->width2 / 8)] == 50000000 && \
			((new->mass2[800 - (res->width2 / 8)] % 10 % 2 != 0) || \
			k == 1)))
	{
		new->v = 1;
		i = 1;
	}
	return (i);
}

int		okrug_new(t_double_l *new, t_result *res)
{
	int i;

	i = 0;
	if (res->width2 == 0)
		okrug_1s(new);
	else
	{
		if (res->width2 % 8 == 0)
			i = okrug_2s(new, res);
		else
		{
			if (res->width2 % 8 != 0)
				i = okrug_3s(new, res);
		}
	}
	okrug1(res, new, i);
	return (okrug_ch(new));
}
