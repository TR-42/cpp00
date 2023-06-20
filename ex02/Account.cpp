/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 23:08:35 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/21 00:56:56 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

#pragma region getter

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

#pragma endregion getter

static std::ostream& print()
{
	struct tm *_tm;
	time_t t = time(NULL);

	_tm = localtime(&t);
#ifdef DEBUG
	_tm->tm_year = 92;
	_tm->tm_mon = 0;
	_tm->tm_mday = 4;
	_tm->tm_hour = 9;
	_tm->tm_min = 15;
	_tm->tm_sec = 32;
#endif

	return std::cout
		<< '['
		<< std::setfill('0') << std::setw(4) << _tm->tm_year + 1900
		<< std::setfill('0') << std::setw(2) << _tm->tm_mon + 1
		<< std::setfill('0') << std::setw(2) << _tm->tm_mday
		<< '_'
		<< std::setfill('0') << std::setw(2) << _tm->tm_hour
		<< std::setfill('0') << std::setw(2) << _tm->tm_min
		<< std::setfill('0') << std::setw(2) << _tm->tm_sec
		<< "] ";
}

// static method
void Account::displayAccountsInfos(void)
{
	print()
		<< "accounts:" << Account::_nbAccounts << ';'
		<< "total:" << Account::_totalAmount << ';'
		<< "deposits:" << Account::_totalNbDeposits << ';'
		<< "withdrawals:" << Account::_totalNbWithdrawals
		<< std::endl;
}

Account::Account(int initial_deposit):
	_accountIndex(Account::_nbAccounts++),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_totalAmount += this->_amount;

	print()
		<< "index:" << this->_accountIndex << ';'
		<< "amount:" << this->_amount << ';'
		<< "created" << std::endl;
}

Account::~Account(void)
{
	print()
		<< "index:" << this->_accountIndex << ';'
		<< "amount:" << this->_amount << ';'
		<< "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = this->_amount;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;

	this->_nbDeposits += 1;
	this->_amount += deposit;

	print()
		<< "index:" << this->_accountIndex << ';'
		<< "p_amount:" << p_amount << ';'
		<< "deposit:" << deposit << ';'
		<< "amount:" << this->_amount << ';'
		<< "nb_deposits:" << this->_nbDeposits
		<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = this->_amount;

	if ((p_amount - withdrawal) < 0)
	{
		print()
			<< "index:" << this->_accountIndex << ';'
			<< "p_amount:" << p_amount << ';'
			<< "withdrawal:refused"
			<< std::endl;
		return (false);
	}

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;

	this->_nbWithdrawals += 1;
	this->_amount -= withdrawal;

	print()
		<< "index:" << this->_accountIndex << ';'
		<< "p_amount:" << p_amount << ';'
		<< "withdrawal:" << withdrawal << ';'
		<< "amount:" << this->_amount << ';'
		<< "nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	return false;
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	print()
		<< "index:" << this->_accountIndex << ';'
		<< "amount:" << this->_amount << ';'
		<< "deposits:" << this->_nbDeposits << ';'
		<< "withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

void Account::_displayTimestamp(void)
{
	print();
}
