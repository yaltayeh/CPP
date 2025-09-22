/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:43:15 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/22 12:24:05 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AANIMAL_HPP__
# define __AANIMAL_HPP__

#include <string>

class AAnimal
{
protected:
	AAnimal();
	~AAnimal();
	std::string type;
	AAnimal(const std::string &type);
	
public:
	virtual void makeSound() const;
	const std::string &getType() const;
};

#endif /* __AANIMAL_HPP__ */
