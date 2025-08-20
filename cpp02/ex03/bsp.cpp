/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:43:47 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/08/20 14:14:15 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed a2 = (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));

	Fixed l1 = ((b.x * c.y - c.x * b.y) + point.x * (b.y - c.y) + point.y * (c.x - b.x)) / a2;
	Fixed l2 = ((c.x * a.y - a.x * c.y) + point.x * (c.y - a.y) + point.y * (a.x - c.x)) / a2;
	Fixed l3 = ((a.x * b.y - b.x * a.y) + point.x * (a.y - b.y) + point.y * (b.x - a.x)) / a2;

	return (l1 >= 0 && l1 <= 1 && l2 >= 0 && l2 <= 1 && l3 >= 0 && l3 <= 1);
}