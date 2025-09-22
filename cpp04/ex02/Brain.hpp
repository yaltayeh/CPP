/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:43:15 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/09/22 09:16:22 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

#include <string>

class Brain
{
private:
	std::string	ideas[100];
	int 		count;

public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();
	void addIdea(const std::string &idea);
	const std::string &getIdea(size_t i) const;
};

#endif /* __BRAIN_HPP__ */
