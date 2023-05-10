/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:34:58 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 18:03:09 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_STRING_H
# define MY_STRING_H

char	ft_16_to_hex(unsigned char c);
void	ft_char_to_hex(unsigned char c);
void	puthex(int size);
void	putmemory(int size, int count);
int		ft_strlen(char *str);
int		ft_strncmp(char *str1, char *str2, int size);
void	ft_putchar(char c);
void	ft_initstr(char *str, int size);
void	ft_putstr(char *str);
void	ft_putnstr(char *str, int size);
void	ft_putstr_printable(char *str, int size);
void	ft_strncpy(char *dest, char *src, int size);
void	ft_putstr_err(char *filename, char *str);

#endif
