/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:36:59 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/08/20 15:18:41 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0) {
      
}

Point::Point(float x, float y): x(x), y(y) {
    
}

Point::Point(Point &p) {
    this->x = p.x;
    this->y = p.y;
}

Point &Point::operator=(const Point &p) {
    this->x = p.x;
    this->y = p.y;
    return (*this);
}

Point::~Point() {
    this->x = 0;
    this->y = 0;
}

const Fixed Point::getX() const {
    return (this->x);
}

const Fixed Point::getY() const {
    return (this->y);
}
