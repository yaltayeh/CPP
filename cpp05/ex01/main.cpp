/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 07:53:25 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/10/14 08:40:20 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

void	printHelp()
{
	std::cout << "\n" << BOLD << CYAN << "========== BUREAUCRAT MANAGEMENT SYSTEM ==========" << RESET << std::endl;
	std::cout << BOLD << "Available commands:" << RESET << std::endl;
	std::cout << "  " << GREEN << "help" << RESET << "                          - Display this help message" << std::endl;
	std::cout << "  " << GREEN << "employment" << RESET << " <name> <grade>     - Create new employee" << std::endl;
	std::cout << "  " << GREEN << "emp" << RESET << " <name> <grade>            - Shorthand for employment" << std::endl;
	std::cout << "  " << GREEN << "list" << RESET << "                          - Display all employees" << std::endl;
	std::cout << "  " << GREEN << "promote" << RESET << " <id>                  - Promote employee by ID" << std::endl;
	std::cout << "  " << GREEN << "demote" << RESET << " <id>                   - Demote employee by ID" << std::endl;
	std::cout << "  " << GREEN << "dismissal" << RESET << " <id>                - Fire employee by ID" << std::endl;
	std::cout << "  " << GREEN << "dis" << RESET << " <id>                      - Shorthand for dismissal" << std::endl;
	std::cout << "  " << GREEN << "exit" << RESET << " (or " << GREEN << "quit" << RESET << ", " << GREEN << "q" << RESET << ", " << GREEN << "Ctrl-D" << RESET << ") - Exit the program" << std::endl;
	std::cout << BOLD << CYAN << "===================================================" << RESET << std::endl;
}

void	listEmployees(const std::vector<Bureaucrat*>& employees)
{
	if (employees.empty())
	{
		std::cout << YELLOW << "No employees in the system." << RESET << std::endl;
		return;
	}
	
	std::cout << "\n" << BOLD << BLUE << "========== EMPLOYEE LIST ==========" << RESET << std::endl;
	for (size_t i = 0; i < employees.size(); i++)
	{
		std::cout << CYAN << "[" << i << "]" << RESET << " " << *employees[i] << std::endl;
	}
	std::cout << BOLD << BLUE << "====================================" << RESET << std::endl;
}

void	createEmployee(std::vector<Bureaucrat*>& employees, const std::string& name, int grade)
{
	try
	{
		Bureaucrat* newEmployee = new Bureaucrat(name, grade);
		employees.push_back(newEmployee);
		std::cout << GREEN << "✓ Employee created successfully!" << RESET << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}
}

void	promoteEmployee(std::vector<Bureaucrat*>& employees, size_t id)
{
	if (employees.empty())
	{
		std::cout << YELLOW << "No employees to promote." << RESET << std::endl;
		return;
	}

	if (id >= employees.size())
	{
		std::cout << RED << "✗ Error: Invalid employee ID." << RESET << std::endl;
		return;
	}

	try
	{
		employees[id]->promotion();
	}
	catch (std::exception& e)
	{
		std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}
}

void	demoteEmployee(std::vector<Bureaucrat*>& employees, size_t id)
{
	if (employees.empty())
	{
		std::cout << YELLOW << "No employees to demote." << RESET << std::endl;
		return;
	}

	if (id >= employees.size())
	{
		std::cout << RED << "✗ Error: Invalid employee ID." << RESET << std::endl;
		return;
	}

	try
	{
		employees[id]->demoted();
	}
	catch (std::exception& e)
	{
		std::cout << RED << "✗ Error: " << e.what() << RESET << std::endl;
	}
}

void	dismissEmployee(std::vector<Bureaucrat*>& employees, size_t id)
{
	if (employees.empty())
	{
		std::cout << YELLOW << "No employees to dismiss." << RESET << std::endl;
		return;
	}

	if (id >= employees.size())
	{
		std::cout << RED << "✗ Error: Invalid employee ID." << RESET << std::endl;
		return;
	}

	delete employees[id];
	employees.erase(employees.begin() + id);
	std::cout << GREEN << "✓ Employee dismissed successfully!" << RESET << std::endl;
}

int main()
{
	std::vector<Bureaucrat*> employees;
	std::string line;
	std::string command;

	std::cout << BOLD << BLUE << "Welcome to the Bureaucrat Management System!" << RESET << std::endl;
	std::cout << "Type '" << GREEN << "help" << RESET << "' for available commands." << std::endl;

	while (true)
	{
		std::cout << "\n" << BOLD << "> " << RESET;
		std::cout.flush();
		
		if (!std::getline(std::cin, line))
		{
			if (std::cin.eof())
			{
				std::cout << "\n" << YELLOW << "EOF detected. Cleaning up and exiting..." << RESET << std::endl;
				for (size_t i = 0; i < employees.size(); i++)
					delete employees[i];
				employees.clear();
				std::cout << BOLD << GREEN << "Goodbye!" << RESET << std::endl;
				return 0;
			}
			std::cin.clear();
			continue;
		}

		// Filter out ANSI escape sequences (arrow keys, etc.)
		if (!line.empty() && line[0] == 27)
		{
			// Skip escape sequences (arrow keys produce ESC[A, ESC[B, ESC[C, ESC[D)
			continue;
		}

		std::istringstream iss(line);
		iss >> command;

		if (command == "help")
		{
			printHelp();
		}
		else if (command == "employment" || command == "emp")
		{
			std::string name;
			int grade;
			
			if (!(iss >> name >> grade))
			{
				std::cout << RED << "✗ Error: Usage: " << command << " <name> <grade>" << RESET << std::endl;
				continue;
			}
			
			createEmployee(employees, name, grade);
		}
		else if (command == "list")
		{
			listEmployees(employees);
		}
		else if (command == "promote")
		{
			size_t id;
			
			if (!(iss >> id))
			{
				std::cout << RED << "✗ Error: Usage: promote <id>" << RESET << std::endl;
				continue;
			}
			
			promoteEmployee(employees, id);
		}
		else if (command == "demote")
		{
			size_t id;
			
			if (!(iss >> id))
			{
				std::cout << RED << "✗ Error: Usage: demote <id>" << RESET << std::endl;
				continue;
			}
			
			demoteEmployee(employees, id);
		}
		else if (command == "dismissal" || command == "dis")
		{
			size_t id;
			
			if (!(iss >> id))
			{
				std::cout << RED << "✗ Error: Usage: " << command << " <id>" << RESET << std::endl;
				continue;
			}
			
			dismissEmployee(employees, id);
		}
		else if (command == "exit" || command == "quit" || command == "q")
		{
			std::cout << YELLOW << "Cleaning up and exiting..." << RESET << std::endl;
			for (size_t i = 0; i < employees.size(); i++)
				delete employees[i];
			employees.clear();
			std::cout << BOLD << GREEN << "Goodbye!" << RESET << std::endl;
			return 0;
		}
		else if (command.empty())
		{
			continue;
		}
		else
		{
			std::cout << RED << "✗ Unknown command: '" << command << "'. Type 'help' for available commands." << RESET << std::endl;
		}
	}

	// Cleanup in case of abnormal exit
	for (size_t i = 0; i < employees.size(); i++)
		delete employees[i];

	return 0;
}
