/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:49:53 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 08:36:12 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	zero_handler(char op, int b)
{
	if (b == 0 && op == '/')
	{
		ft_putstr("Stop : division by zero\n");
		return (1);
	}
	else if (b == 0 && op == '%')
	{
		ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	return (0);
}

void	init_caltype(int(*caltype[])(int, int))
{
	caltype[0] = &cal_plus;
	caltype[1] = &cal_minus;
	caltype[2] = &cal_times;
	caltype[3] = &cal_div;
	caltype[4] = &cal_mod;
}

void	init_optype(char *optype)
{
	optype[0] = '+';
	optype[1] = '-';
	optype[2] = '*';
	optype[3] = '/';
	optype[4] = '%';
}

void	calculator(int a, int b, char op)
{
	int		result;
	int		(*caltype[5])(int, int);
	char	optype[5];
	int		idx;

	if (zero_handler(op, b))
		return ;
	init_optype(optype);
	init_caltype(caltype);
	idx = 0;
	while (idx < 5)
	{
		if (optype[idx] == op)
			result = (caltype[idx])(a, b);
		idx++;
	}
	ft_putnbr(result);
}
