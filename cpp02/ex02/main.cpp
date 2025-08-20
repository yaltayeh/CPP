/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:48:49 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/08/20 14:00:53 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a(1.15f);
	Fixed b(0.5f);
	std::cout << a << std::endl;
	std::cout << a << std::endl;
	std::cout << a << std::endl;
	std::cout << "a / b: " << a / b << std::endl;
	return 0;
}