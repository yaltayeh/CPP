#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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
				
				std::string type = "ClapTrap";
				if (typeid(*robots[i]) == typeid(ScavTrap))
					type = "ScavTrap";
				else if (typeid(*robots[i]) == typeid(FragTrap))
					type = "FragTrap";
				
				std::cout << "Type: " << type << std::endl;
				std::cout << "Hit Points: " << robots[i]->getHitPoints() << std::endl;
				std::cout << "Energy Points: " << robots[i]->getEnergyPoints() << std::endl;
				std::cout << "Attack Damage: " << robots[i]->getAttackDamage() << std::endl;

				if (typeid(*robots[i]) == typeid(ScavTrap))
				{
					std::cout << "Gate Keeper Mode: " << (static_cast<ScavTrap*>(robots[i])->isGateKeeperMode() ? "ON" : "OFF") << std::endl;
				}
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
		if (typeid(victim) == typeid(ScavTrap) && static_cast<ScavTrap&>(victim).isGateKeeperMode())
		{
			std::cout << victim.getName() << " is in Gate Keeper mode and cannot be attacked!" << std::endl;
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

void gate()
{
	try
	{
		ClapTrap &gate_keeper = getRobot("Enter the name of the ScavTrap to toggle Gate Keeper mode: ");
		if (typeid(gate_keeper) != typeid(ScavTrap))
		{
			std::cout << gate_keeper.getName() << " is not a ScavTrap and cannot toggle Gate Keeper mode!" << std::endl;
			return;
		}
		static_cast<ScavTrap&>(gate_keeper).guardGate();
	}
	catch (const std::ios_base::failure &e)
	{
		throw std::runtime_error("Ctrl+D detected");
	}
	catch (const std::exception &e)
	{
		std::cout << "Error in gate: " << e.what() << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void highFives()
{
	try
	{
		ClapTrap &fragtrap = getRobot("Enter the name of the FragTrap for high fives: ");
		if (typeid(fragtrap) != typeid(FragTrap))
		{
			std::cout << fragtrap.getName() << " is not a FragTrap and cannot give high fives!" << std::endl;
			return;
		}
		static_cast<FragTrap&>(fragtrap).highFivesGuys();
	}
	catch (const std::ios_base::failure &e)
	{
		throw std::runtime_error("Ctrl+D detected");
	}
	catch (const std::exception &e)
	{
		std::cout << "Error in highFives: " << e.what() << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void newRobot(const std::string &type, const std::string &name)
{
	if (type == "ClapTrap")
	{
		robots[robotCount] = new ClapTrap(name);
	}
	else if (type == "ScavTrap")
	{
		robots[robotCount] = new ScavTrap(name);
	}
	else if (type == "FragTrap")
	{
		robots[robotCount] = new FragTrap(name);
	}
	else
	{
		throw std::invalid_argument("Invalid robot type!");
	}
	robotCount++;
}

void addRobot()
{
	try
	{
		std::string type;
		std::string name;

		std::cout << "Enter robot name: ";
		std::cin >> name;

		std::cout << "Enter robot type (ClapTrap, ScavTrap, or FragTrap): ";
		std::cin >> type;

		newRobot(type, name);
		std::cout << "Robot " << name << " added successfully!" << std::endl;
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
	}
}

void help()
{
	std::cout << "\nCommands:\n"
			  << "attack    : Make one robot attack another.\n"
			  << "repair    : Repair a robot by a specified amount.\n"
			  << "gate      : Toggle the Gate Keeper mode of a ScavTrap.\n"
			  << "highfives : Make a FragTrap give high fives.\n"
			  << "status    : Display the status of all robots.\n"
			  << "add       : Add a new robot.\n"
			  << "help      : Show this help message.\n"
			  << "exit      : Exit the program." << std::endl;
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
	newRobot("ClapTrap", "CT-01");
	newRobot("ClapTrap", "CT-02");
	newRobot("ScavTrap", "ST-01");
	newRobot("ScavTrap", "ST-02");
	newRobot("FragTrap", "FT-01");
	newRobot("FragTrap", "FT-02");

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
			else if (input == "gate")
				gate();
			else if (input == "highfives")
				highFives();
			else if (input == "add")
				addRobot();
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
