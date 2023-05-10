/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:36:07 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 08:35:16 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>
int		ft_atoi(char *str);
void	ft_putnbr(int nbr);
void	calculator(int a, int b, char op);
int		cal_plus(int a, int b);
int		cal_minus(int a, int b);
int		cal_times(int a, int b);
int		cal_div(int a, int b);
int		cal_mod(int a, int b);
void	ft_putchar(char c);
void	ft_putstr(char *str);

#endif
