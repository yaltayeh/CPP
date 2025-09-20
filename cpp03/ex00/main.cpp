/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 09:21:33 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/20 09:21:34 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap copy("⌘-C");
	ClapTrap paste("⌘-V");

	copy.attack("⌘-V");
	paste.takeDamage(0);
	paste.beRepaired(5);

	copy.attack("⌘-V");
	paste.takeDamage(0);
	paste.attack("⌘-C");
	copy.takeDamage(0);
	copy.beRepaired(2);

	return 0;
}