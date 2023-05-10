/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:41:47 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 08:40:27 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

char	operator_handler(char *op_str)
{
	if (*op_str == '+' || *op_str == '-' || \
		*op_str == '/' || *op_str == '*' || *op_str == '%')
	{
		if (*(op_str + 1) == '\0')
			return (*op_str);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	op;

	if (argc != 4)
		return (0);
	op = operator_handler(argv[2]);
	if (op == 0)
	{
		ft_putstr("0\n");
		return (0);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	calculator(a, b, op);
	return (0);
}
