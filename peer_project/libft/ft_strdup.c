/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svet <svet@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:18:28 by heantoni          #+#    #+#             */
/*   Updated: 2020/07/08 00:11:35 by svet             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*t;
	int		i;

	if (s == NULL)
		return (NULL);
	t = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (t == NULL)
		return (t);
	i = 0;
	while (*s)
	{
		t[i] = *s;
		i++;
		s++;
	}
	t[i] = '\0';
	return (t);
}
