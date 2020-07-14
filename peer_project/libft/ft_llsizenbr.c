/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llsizenbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 02:16:33 by spalmer           #+#    #+#             */
/*   Updated: 2020/06/14 02:17:55 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_llsizenbr(long long int nbr)
{
	int	n;

	n = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		n++;
	nbr = nbr / 10;
	n++;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		nbr /= 10;
		n++;
	}
	return (n);
}
