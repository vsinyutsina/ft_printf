/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 02:08:45 by spalmer           #+#    #+#             */
/*   Updated: 2020/06/29 01:59:41 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_n_check(char const *s, int cnt)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (i < cnt)
		{
			if (ft_putchar_check(s[i]) == -1)
				return (-1);
			i++;
		}
	}
	return (0);
}
