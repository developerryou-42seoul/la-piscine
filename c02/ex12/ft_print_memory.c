/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:09:15 by sryou             #+#    #+#             */
/*   Updated: 2022/02/07 19:15:35 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_char_to_hex(unsigned char c)
{
	char	*hexarr;

	hexarr = "0123456789abcdef";
	write(1, hexarr + c, 1);
}

void	write_chararr(char *addr, int len)
{
	while (len > 0)
	{
		if (' ' <= *addr && *addr <= '~')
			write(1, addr, 1);
		else
			write(1, ".", 1);
		addr++;
		len--;
	}
}

void	write_hex_and_chararr(char *addr, int len)
{
	int		idx;

	idx = 0;
	while (idx < 16)
	{
		if (idx >= len)
			write(1, "  ", 2);
		else
		{
			write_char_to_hex(((unsigned char)addr[idx]) / 16);
			write_char_to_hex(((unsigned char)addr[idx]) % 16);
		}
		if (idx % 2 == 1)
			write(1, " ", 1);
		idx++;
	}
	write_chararr(addr, len);
}

void	write_pointer(unsigned long long addr, int len)
{
	if (len == 16)
		return ;
	write_pointer(addr / 16, len + 1);
	write_char_to_hex(addr % 16);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*idx_addr;

	idx_addr = (char *)addr;
	while (size > 0)
	{
		write_pointer((unsigned long long)idx_addr, 0);
		write(1, ": ", 2);
		if (size >= 16)
		{
			write_hex_and_chararr(idx_addr, 16);
			size -= 16;
		}
		else
		{
			write_hex_and_chararr(idx_addr, size);
			size = 0;
		}
		idx_addr += 16;
		write(1, "\n", 1);
	}
	return (addr);
}
