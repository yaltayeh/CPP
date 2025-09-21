#include "ClapTrap.hpp"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <typeinfo>

ClapTrap **robots;
int robotCount = 0;

ClapTrap &getRobot(std::string msg)
{
	try
	{
		std::string name;
		std::cout << msg;
		std::cin >> name;

		for (int i = 0; robots[i] != NULL; i++)
		{
			if (name == robots[i]->getName())
				return *robots[i];
		}

		throw std::invalid_argument("No such robot exists!");
	}
	catch (const std::ios_base::failure &e)
	{
		throw std::runtime_error("Ctrl+D detected");
	}
	catch (const std::exception &e)
	{
		throw;
	}
}

void printStatus()
{
	try
	{
		if (robotCount == 0)
		{
			std::cout << "No robots created yet!" << std::endl;
			return;
		}

		std::cout << "\n=== All Robots Status ===" << std::endl;
		for (int i = 0; i < robotCount; i++)
		{
			if (robots[i] != NULL)
			{
				std::cout << "\nRobot " << (i + 1) << ": " << robots[i]->getName() << std::endl;
				std::cout << "Hit Points: " << robots[i]->getHitPoints() << std::endl;
				std::cout << "Energy Points: " << robots[i]->getEnergyPoints() << std::endl;
				std::cout << "Attack Damage: " << robots[i]->getAttackDamage() << std::endl;
				std::cout << "------------------------" << std::endl;
			}
		}
		std::cout << "========================\n" << std::endl;
	}
	catch (const std::ios_base::failure &e)
	{
		throw std::runtime_error("Ctrl+D detected");
	}
	catch (const std::exception &e)
	{
		std::cout << "Error in printStatus: " << e.what() << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void attack()
{
	try
	{
		ClapTrap &hunter = getRobot("Enter the name of the attacker: ");
		ClapTrap &victim = getRobot("Enter the name of the victim: ");

		if (victim.getName() == hunter.getName())
		{
			std::cout << "A robot cannot attack itself!" << std::endl;
			return;
		}

		if (hunter.getEnergyPoints() == 0)
		{
			std::cout << hunter.getName() << " has no energy left to attack!" << std::endl;
			return;
		}
		if (victim.getHitPoints() == 0)
		{
			std::cout << victim.getName() << " is dead !!." << std::endl;
			return;
		}
		hunter.attack(victim.getName());
		victim.takeDamage(hunter.getAttackDamage());
	}
	catch (const std::ios_base::failure &e)
	{
		throw std::runtime_error("Ctrl+D detected");
	}
	catch (const std::exception &e)
	{
		std::cout << "Error in attack: " << e.what() << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void repair()
{
	try
	{
		ClapTrap &repairer = getRobot("Enter the name of the robot to repair: ");

		int repair_points;
		std::cout << "Enter the amount of repair points: ";
		std::cin >> repair_points;

		repairer.beRepaired(repair_points);
	}
	catch (const std::ios_base::failure &e)
	{
		throw std::runtime_error("Ctrl+D detected");
	}
	catch (const std::exception &e)
	{
		std::cout << "Error in repair: " << e.what() << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void newRobot(const std::string &name)
{
	robots[robotCount] = new ClapTrap(name);
	robotCount++;
}

ClapTrap *addRobot()
{
	try
	{
		std::string type;
		std::string name;

		std::cout << "Enter robot name: ";
		std::cin >> name;

		newRobot(name);
		std::cout << "Robot " << name << " added successfully!" << std::endl;
		return robots[robotCount - 1];
	}
	catch (const std::ios_base::failure &e)
	{
		throw std::runtime_error("Ctrl+D detected");
	}
	catch (const std::exception &e)
	{
		std::cout << "Error in addRobot: " << e.what() << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (NULL);
	}
}

void help()
{
	std::cout << "\nCommands:\n"
			  << "attack : Make one robot attack another.\n"
			  << "repair : Repair a robot by a specified amount.\n"
			  << "status : Display the status of all robots.\n"
			  << "help   : Show this help message.\n"
			  << "exit   : Exit the program." << std::endl;
}

int main()
{
	robots = new ClapTrap *[100]();
	if (!robots)
	{
		std::cerr << "Memory allocation failed!" << std::endl;
		return 1;
	}
	// Add more robots as needed
	newRobot("CT-01");
	newRobot("CT-02");

	// Enable exceptions for cin on EOF
	std::cin.exceptions(std::ios_base::eofbit);

	std::string input;

	std::cout << "\ntype 'exit' to quit the program\n"
			  << std::endl;
	while (true)
	{
		try
		{
			std::cout << "\nEnter a command (type 'help' for options): ";
			std::cin >> input;

			if (input == "")
				continue;
			if (input == "exit")
				break;
			if (input == "help")
				help();
			else if (input == "attack")
				attack();
			else if (input == "repair")
				repair();
			else if (input == "status")
				printStatus();
			else if (input == "add")
			{
				if (addRobot())
				{
					break;
				}
			}
			else
			{
				std::cout << "Unknown command. Type 'help' for a list of commands." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
		catch (const std::ios_base::failure &e)
		{
			std::cout << "\nCtrl+D detected. Exiting..." << std::endl;
			break;
		}
		catch (const std::runtime_error &e)
		{
			std::cout << "\n"
					  << e.what() << ". Exiting..." << std::endl;
			break;
		}
		catch (const std::bad_alloc& e)
		{
        	std::cerr << "Memory allocation failed: " << e.what() << std::endl;
			break;
		}
		catch (const std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	delete[] robots;
	return 0;
}
