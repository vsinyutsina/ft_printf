/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizedouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 02:11:39 by spalmer           #+#    #+#             */
/*   Updated: 2020/07/08 00:10:37 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizedouble(double nbr)
{
	int	n;

	n = 0;
	if (nbr == 0)
		return (1);
	nbr = nbr / 10;
	n++;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= 1)
	{
		nbr /= 10;
		n++;
	}
	return (n);
}

int	ft_lsizedouble(long double nbr)
{
	int	n;

	n = 0;
	if (nbr == 0)
		return (1);
	nbr = nbr / 10;
	n++;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr >= 1)
	{
		nbr /= 10;
		n++;
	}
	return (n);
}
