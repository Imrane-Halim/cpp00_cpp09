#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void):
	_accountIndex(0),
	_amount(0),
	_nbDeposits(0),
	_nbWithdrawals(0) {}

Account::Account(int initial_desposit):
	_accountIndex(_nbAccounts),
	_amount(initial_desposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_desposit;
	_totalNbDeposits += 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
}

int	Account::getNbAccounts(void) {return (_nbAccounts);}
int	Account::getTotalAmount(void) {return (_totalAmount);}
int	Account::getNbDeposits(void) {return (_totalNbDeposits);}
int	Account::getNbWithdrawals(void) {return (_totalNbWithdrawals);}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawl)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (withdrawl <= _amount)
	{
		_amount -= withdrawl;
		_totalAmount -= withdrawl;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		std::cout << withdrawl << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals;
		std::cout << std::endl;
		return (true);
	}
	std::cout << "refused" << std::endl;
	return (false);
}

int		Account::checkAmount(void) const {return (_amount);}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals; 
	std::cout << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t time_in_sec = time(NULL);
	struct tm local = *localtime(&time_in_sec);

	std::cout << "[" << local.tm_year + 1900;
	std::cout << (local.tm_mon < 10 ? "0" : "") << local.tm_mon;
	std::cout << (local.tm_mday < 10 ? "0" : "") << local.tm_mday;
	std::cout << "_";
	std::cout << (local.tm_hour < 10 ? "0" : "") << local.tm_hour;
	std::cout << (local.tm_min < 10 ? "0" : "") << local.tm_min;
	std::cout << (local.tm_sec < 10 ? "0" : "") << local.tm_sec;
	std::cout << "] ";
}
