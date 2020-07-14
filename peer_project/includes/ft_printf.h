/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:52:21 by spalmer           #+#    #+#             */
/*   Updated: 2020/07/10 15:30:01 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct			s_result
{
	int					characters;
	int					line_length;
	int					c_length;
	int					cnt;
	long long int		d;
	char				*s;
	unsigned char		c;
	double				f;
	long double			ff;
	int					flag_lf;
	double				e;
	va_list				factor;
	int					width;
	int					width2;
	int					wid_pres;
	int					f_min;
	int					f_plus;
	int					f_prob;
	int					f_zero;
	int					f_hash;
	int					flag_ll;
	int					flag_l;
	int					flag_h;
	int					flag_hh;
	int					flag_j;
	int					flag_star;
	int					flag_star2;
	char				*spesial_symbols;
	char				data_type;
	char				simvol;
	int					point;
	unsigned long		cheloe;
	int					m;
	char				*ss;
	int					color;
	char				*error_str;
}						t_result;

typedef struct			s_newdouble
{
	unsigned long int	mantisa:64;
	unsigned long int	exponenta:15;
	int					sign:1;
}						t_newdouble;

typedef union			u_big_double
{
	long double			var;
	t_newdouble			new;
}						t_big_double;

typedef struct			s_double_l
{
	int					mass1[800];
	int					mass2[800];
	int					ch1[800];
	int					ch2[800];
	unsigned long int	drob;
	long int			expo;
	unsigned long int	mant;
	int					sign;
	unsigned long int	ch;
	int					v;
	int					f;
}						t_double_l;

int						ft_printf(const char *format, ...);
void					analysis(char *c, t_result *res);
void					trait(char *c, t_result *res);
int						print_probel(int sizenbr, t_result *res, char c);
void					print_probeld(int sizenbr, t_result *res, char c);
int						check_data_types(char *c, t_result *res);
int						ft_cheloedouble(t_result *res, t_double_l *new, int k);
int						proverka1(t_result *res, t_double_l new);
void					forma_chesla(t_result **res);
int						ft_pow(int nbr, int k);
int						print_tochnost(int sizenbr, t_result **res);
int						check_width(t_result **res);
int						print_prob_int(t_result *res, int k, int flag);
int						print_prob_zero(t_result *res, int k, int flag);
int						print_probel_str(t_result **res, char c);
int						number_int(t_result *res);
void					characters_int(t_result *res);
int						type_o(t_result *res);
int						type_x(t_result *res);
int						type_xx(t_result *res);
int						type_u(t_result *res);
int						type_c(t_result *res);
int						type_s(t_result *res);
int						type_d(t_result *res);
void					type_d_ll(t_result *res);
void					type_d_l(t_result *res);
int						type_f(t_result *res);
int						type_p(t_result *res);
int						type_pr(t_result *res);
void					flag_star(t_result *res);
int						print_all(t_result *res);
void					zap(t_double_l *new);
void					zap_ch2(t_double_l *new);
void					zap_ch1(t_double_l *new);
void					zap2(t_double_l *new);
void					zap_mass2(t_double_l *new);
void					zap22(t_double_l *new);
int						print_0(int nbr);
int						write_double(t_double_l *new, t_result *res);
int						write_inf(t_result *res, int s);
int						write_drob(t_double_l *new, t_result *res);
void					double_cel1(t_result *res, t_double_l *new);
void					expo_not(t_double_l *new);
void					expo_tru(t_double_l *new);
int						okrug_3s(t_double_l *new, t_result *res);
int						okrug_new(t_double_l *new, t_result *res);
void					check_color(char *c, t_result *res);
void					zero_color(t_result *res);
void					flag_star(t_result *res);
void					check_error(t_result *res, char *c, int error_begin);

# define RED		"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define WHITE	"\033[0m"

#endif
