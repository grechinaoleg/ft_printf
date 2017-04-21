/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 08:02:13 by ohrechyn          #+#    #+#             */
/*   Updated: 2017/04/21 12:09:30 by ohrechyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stddef.h>
# include <wchar.h>

# define CH_SIZE sizeof(char)

typedef struct		s_hard
{
	int				space;
	int				minus;
	int				plus;
	int				sharp;
	int				dot;
	int				digit;
	int				index;
	int				end;
	int				space_count;
}					t_hard;

long long int		g_space_start;
long long int		g_plus_pl;
int					g_zero;
int					g_tochnost;
int					g_sharp;
int					g_width;
int					g_space;
int					g_minus;
int					g_per;
long double			g_temp_d;
long long			g_left;

void				clean_globals(void);
char				*ft_eightbit(unsigned int n);
char				*ft_charjoin(char *str, char c);
char				base(int n);
char				*ft_itoa_base(unsigned long long value, int base);
int					print_d_i(int print, int set);
int					print_s(char *str, int width);
int					print_only_s(char *s);
int					print_only_c(char c);
int					print_c(char c);
int					print_o(unsigned int n, int *index, int co, int x);
int					print_ld(long n, int *index);
int					print_lo(unsigned long int n, int *index, int co, int x);
int					print_jo(uintmax_t n, int *index, int co, int x);
int					print_llo(unsigned long long int n,
		int *index, int co, int x);
int					print_u(unsigned int n, char **z);
int					print_u_bg(unsigned int n);
int					print_lld(long long n, int *index);
int					print_jd(intmax_t n, int *index);
int					print_llu(unsigned long long int n, char **z);
int					print_llu_bg(unsigned long long int n, int *index);
int					print_lu(unsigned long int n, char **z);
int					print_ju_bg(uintmax_t n, int *index);
int					print_ls(wchar_t *str);
int					print_jx(uintmax_t n, char type, int *index, int co);
int					print_lu_bg(unsigned long int n, int *index);
int					print_x_bg(unsigned int n, char type, char **z);
int					print_lx(unsigned long int n, char type,
		int *index, int co);
int					print_llx(unsigned long long int n,
		char type, int *index, int co);
int					print_x(unsigned int n, char type, int *index, int co);
int					print_x_long(unsigned long n);
int					print_x_long_rt(unsigned long n, char **z);
int					print_p(void *nbr, char b);
int					print_hd(short int n, int *index);
int					print_hu_bg(unsigned short int n, int *index);
int					print_ho(unsigned short int n, int *index, int co, int x);
int					print_hx(unsigned short int n, char type,
		int *index, int co);
int					print_hhd_i(signed char print, int set);
int					print_hhu_bg(unsigned char n, int *index);
int					print_hho(unsigned char n, int *index, int co, int x);
int					print_hhx(unsigned char n, char type, int *index, int co);
int					print_zd(size_t n, int *index);
int					print_zu(intmax_t n, int *index);
int					print_f(double d, int count, int i, int g);
int					find_okrug(double d, int okrug);
void				up_g_zero_ld(long int *n);
void				up_g_zero_lld(long long int *n);
int					simple(char c);
int					add_hard(int index, int *s, t_hard **list);
int					hard_valid(int *i, char *str, t_hard **list);
int					s_flags(char *str, int i, va_list *args, int *index);
int					z_flags(char *str, int i, va_list *args, int *index);
int					l_flags(char *str, int i, va_list *args, int *index);
int					ll_flags(char *str, int i, va_list *args, int *index);
int					h_flags(char *str, int i, va_list *args, int *index);
int					hh_flags(char *str, int i, va_list *args, int *index);
int					j_flags(char *str, int i, va_list *args, int *index);
int					find_simple(char *str, int i, va_list *args, int *index);
int					valid_width(char *str, t_hard **list, int digit);
int					valid_toch(char *str, t_hard **list, int start);
long long int		valid_digit(char *str, t_hard **list, int dig);
int					add_steps(t_hard **list);
int					find_hard(char *str, t_hard **list,
		int *index, va_list *args);
int					parser(va_list *args, const char *format,
		int i, int length);
long long int		get_width(int len, int plus, int chr, int type);
int					digit_width_min3(int *otric, int *len,
		int *length, int *spec);
int					digit_width_min4(int *otric, int *zero_suka,
		int *length, int *spec);
int					digit_width_min5(int *otric, int *len,
		int *length, int *spec);
void				digit_width_min6(int *oux, int *otric, int *length);
int					digit_width_min8(int *otric, int *ret,
		int *set_minus, int *zero_suka);
void				digit_width_min9(int *otric, int *length,
		int *ret, int *spec);
int					digit_width_min10(int *otric, int *spec,
		int *set_minus, int *zero_suka);
int					digit_width_min11(int *otric, int *spec);
int					digit_width_min12(int *otric, int *spec,
		int *len, int *zero_suka);
int					digit_width_min13(int *otric, int *len,
		int *ret, int *spec);
void				digit_width_min14(int *ret, int *length, int *spec);
char				*convert_wstrtostr(wchar_t *str, int max_len);
int					min_width(char *str, int *i, int stope, int steps);
void				min_width_min1(char *str, int *start_w,
		int *start_t, int t);
int					min_width_min2(char *str, int t, int *start_w,
		int *start_t);
int					find_cifra(char *str, int t);
int					get_min_width(void);
void				print_f_min4(int *count, int *zero_count, long long *right);

#endif
