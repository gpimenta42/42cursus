/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:03:17 by gpimenta          #+#    #+#             */
/*   Updated: 2022/10/28 17:43:29 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void		ft_put_c_arg(int a, int *l);
void		ft_put_s_arg(char *s, int *l);
void		ft_put_i_arg(int i, int *l);
void		ft_put_u_arg(unsigned int i, int *l);
void		ft_put_h_arg(unsigned int a, char s, int *l);
void		ft_put_p_arg(unsigned long p, int *l);
int			ft_printf(const char *str, ...);

#endif
