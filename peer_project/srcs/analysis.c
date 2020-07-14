/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 19:06:27 by spalmer           #+#    #+#             */
/*   Updated: 2020/07/10 15:35:40 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(char *c, t_result *res)
{
	if (c[res->cnt] == '-')
		res->f_min = 1;
	else if (c[res->cnt] == '+')
		res->f_plus = 1;
	else if (c[res->cnt] == ' ')
		res->f_prob = 1;
	else if (c[res->cnt] == '0' && res->f_min == 0)
	{
		res->f_zero = 1;
		res->simvol = '0';
	}
	else if (c[res->cnt] == '#')
		res->f_hash = 1;
	else if (ft_isdigit(c[res->cnt]) && res->point != 1 && c[res->cnt] != '0')
	{
		res->width = ft_atoi(&c[res->cnt]);
		res->cnt += ft_sizenbr(res->width) - 1;
	}
}

void	check_precision(char *c, t_result *res)
{
	if (c[res->cnt] == '.')
	{
		res->point = 1;
		res->cnt++;
		if (ft_isdigit(c[res->cnt]))
		{
			res->width2 = ft_atoi(&c[res->cnt]);
			res->cnt += ft_sizenbr(res->width2) - 1;
		}
		else
			res->cnt--;
	}
}

void	check_sizeflag(char *c, t_result *res)
{
	if (c[res->cnt] == 'l' && (c[res->cnt + 1] == 'l' ||
		c[res->cnt - 1] == 'l'))
		res->flag_ll = 1;
	else if (c[res->cnt] == 'h' && (c[res->cnt + 1] == 'h' ||
		c[res->cnt - 1] == 'h'))
		res->flag_hh = 1;
	else if (c[res->cnt] == 'l' && (c[res->cnt + 1] != 'l' ||
		c[res->cnt - 1] != 'l'))
		res->flag_l = 1;
	else if (c[res->cnt] == 'h' && (c[res->cnt + 1] != 'h' ||
		c[res->cnt - 1] != 'h'))
		res->flag_h = 1;
	else if (c[res->cnt] == 'j')
		res->flag_j = 1;
	else if (c[res->cnt] == '*' && res->point == 0)
		res->flag_star = 1;
	else if (c[res->cnt] == '*' && res->point == 1)
		res->flag_star2 = 1;
	else if (c[res->cnt] == 'L')
		res->flag_lf = 1;
}

int		check_spec(char *c, t_result *res)
{
	if (c[res->cnt] == 'd' || c[res->cnt] == 's' \
			|| c[res->cnt] == 'f' || c[res->cnt] == 'F' \
			|| c[res->cnt] == 'u' || c[res->cnt] == 'p' \
			|| c[res->cnt] == 'o' || c[res->cnt] == 'x' \
			|| c[res->cnt] == 'X' || c[res->cnt] == 'c' \
			|| c[res->cnt] == 'i' || c[res->cnt] == '%')
		return (0);
	else if (c[res->cnt] == 'l' || c[res->cnt] == 'h' \
			|| c[res->cnt] == 'L' || c[res->cnt] == 'j' \
			|| c[res->cnt] == '.' || c[res->cnt] == '#' \
			|| c[res->cnt] == '*' || c[res->cnt] == ' ' \
			|| c[res->cnt] == '-' || c[res->cnt] == '+')
		return (1);
	else if (ft_isdigit(c[res->cnt]))
		return (2);
	else
		return (-1);
}

void	analysis(char *c, t_result *res)
{
	int	check;
	int	error_begin;

	res->cnt++;
	error_begin = res->cnt;
	while (c[res->cnt] != '\0')
	{
		check = check_spec(c, res);
		if (check == -1)
		{
			check_error(res, c, error_begin);
			return ;
		}
		else if (check == 0)
			break ;
		check_color(c, res);
		check_flags(c, res);
		check_precision(c, res);
		check_sizeflag(c, res);
		res->cnt++;
	}
	res->characters = check_data_types(c, res);
	zero_color(res);
}
