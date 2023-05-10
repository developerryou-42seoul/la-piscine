/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 09:39:09 by sryou             #+#    #+#             */
/*   Updated: 2022/02/19 18:11:44 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	// check number valid
	//		only digit
	//
	// check dict valid
	// check other dict valid
	//		colone, digit ++..
	
	// parse dictionary and save 
	// 		t_dict *list = (t_dict *)malloc(sizeof(t_dict))
	// 		t_dict.key = char*
	// 		t_dict.value = char*
	// 		t_dict.next = t_dict*
	// parse other dixtionary and save
	// 		if key is same, modi val
	// 		if new key, add dict
	// change number with using dict
	//		7124561 -> check 1000000
	//				7 + 1000000 + 124561
	//			check 7				check 100000->10000->1000
	//												124 + 1000 + 561
	//											check 100		check 100
	//										1 + 100 + 24		5 + 100 + 61
	//											check 20			check 60
	//												20 + 4				60 + 1
}
