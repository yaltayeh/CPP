/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 19:47:30 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/08/20 15:21:58 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int32_t main(void)
{
	Point a(20, 0), b(0, 20), c(80, 20);

	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 80; x++)
		{
			Point p(x, y);
			if (bsp(a, b, c, p))
				std::cout << "O";
			else
				std::cout << " ";
		}
		std::cout << "\n";
	}
	std::cout.flush();
	return (0);
}
