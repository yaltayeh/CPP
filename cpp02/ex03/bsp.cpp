/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:43:47 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/08/20 15:13:15 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed a2 = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));

	if (a2 == 0)
		return (false);
	Fixed l1 = ((b.getX() * c.getY() - c.getX() * b.getY()) + point.getX() * (b.getY() - c.getY()) + point.getY() * (c.getX() - b.getX())) / a2;
	Fixed l2 = ((c.getX() * a.getY() - a.getX() * c.getY()) + point.getX() * (c.getY() - a.getY()) + point.getY() * (a.getX() - c.getX())) / a2;
	Fixed l3 = ((a.getX() * b.getY() - b.getX() * a.getY()) + point.getX() * (a.getY() - b.getY()) + point.getY() * (b.getX() - a.getX())) / a2;

	return (l1 >= 0 && l1 <= 1 && l2 >= 0 && l2 <= 1 && l3 >= 0 && l3 <= 1);
}
