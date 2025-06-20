#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";"
			  << "total:" << Account::_totalAmount << ";"
			  << "deposits:" << Account::_totalNbDeposits << ";"
			  << "withdrawals:" << Account::_totalNbWithdrawals
			  << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = Account::_amount;

	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_nbDeposits++;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << Account::_amount << ";"
			  << "nb_deposits:" << Account::_nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = Account::_amount;
	if (Account::_amount < withdrawal)
	{
		Account::_displayTimestamp();
		std::cout << "index:" << Account::_accountIndex << ";"
				  << "p_amount:" << p_amount << ";"
				  << "withdrawal:refused"
				  << std::endl;
		return (false);
	}
	Account::_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "withdrawal:" << withdrawal << ";"
			  << "amount:" << Account::_amount << ";"
			  << "nb_withdrawals:" << Account::_nbWithdrawals
			  << std::endl;
	return (true);
}

int Account::checkAmount(void) const
{
	return (Account::_amount);
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";"
			  << "amount:" << Account::_amount << ";"
			  << "deposits:" << Account::_nbDeposits << ";"
			  << "withdrawals:" << Account::_nbWithdrawals
			  << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(NULL);
	std::tm *now = std::localtime(&t);

	std::cout << "[" << (now->tm_year + 1900)
        << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
        << std::setw(2) << std::setfill('0') << now->tm_mday
        << "_"
        << std::setw(2) << std::setfill('0') << now->tm_hour
        << std::setw(2) << std::setfill('0') << now->tm_min
        << std::setw(2) << std::setfill('0') << now->tm_sec
		<< "] ";
}

Account::Account(void)
{
	static int index = 0;

	Account::_amount = 0;
	Account::_accountIndex = index;
	Account::_nbAccounts++;
}

Account::Account(int initial_deposit)
{
	static int index = 0;

	Account::_accountIndex = index++;
	Account::_nbAccounts++;
	// local
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;

	// static
	Account::_totalAmount += Account::_amount;

	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";"
			  << "amount:" << Account::_amount << ";"
			  << "created" << std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_totalAmount -= Account::_amount;
	Account::_totalNbDeposits -= Account::_nbDeposits;
	Account::_totalNbWithdrawals -= Account::_nbWithdrawals;

	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";"
			  << "amount:" << Account::_amount << ";"
			  << "closed" << std::endl;
}
