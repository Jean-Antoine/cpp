/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:08:26 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/31 14:18:18 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

void	display(std::string label, int value, int last)
{
	std::cout << label << ":" << value;
	if (last)
		std::cout << std::endl;
	else
		std::cout << ";";		
}

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	display("index", this->_accountIndex, 0);
	display("amount", this->_amount, 0);
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	display("index", this->_accountIndex, 0);
	display("amount", this->_amount, 0);
	std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp()
{
	std::time_t	t = std::time(NULL);
	char s[] = "[YYYYMMDD HHMMSS] ";
	
	std::strftime(s, 17, "[%Y%m%d %H%M%S] ", std::gmtime(&t));
	std::cout << s;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	display("accounts", _nbAccounts, 0);
	display("total", _totalAmount, 0);
	display("deposits", _totalNbDeposits, 0);
	display("withdrawals", _totalNbWithdrawals, 1);
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	display("index", _accountIndex, 0);
	display("p_amount", _amount, 0);
	display("deposit", deposit, 0);
	_amount += deposit;
	display("amount", _amount, 0);
	display("nb_deposits", ++_nbDeposits, 1);
	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	display("index", _accountIndex, 0);
	display("p_amount", _amount, 0);
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (0);
	}
	display("withdrawal", withdrawal, 0);
	_amount -= withdrawal;
	display("amount", _amount, 0);
	display("nb_withdrawals", ++_nbWithdrawals, 1);
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (1);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	display("index", _accountIndex, 0);
	display("amount", _amount, 0);
	display("deposits", _nbDeposits, 0);
	display("withdrawals", _nbWithdrawals, 1);
}
