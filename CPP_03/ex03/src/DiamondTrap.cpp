/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbest <mbest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:22:15 by tblaase           #+#    #+#             */
/*   Updated: 2025/02/11 16:26:58 by mbest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

// Constructors
DiamondTrap::DiamondTrap() : ClapTrap("defaultDT_clap_trap")
{
	this->_name = "defaultDT";
	this->_hitPoint = FragTrap::_hitPoint;
	this->_Energy = ScavTrap::_Energy;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap")
{
	this->_name = name;
	this->_hitPoint = FragTrap::_hitPoint;
	this->_Energy = ScavTrap::_Energy;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Constructor for the name " << this->_name << " called" << std::endl;
}

// Deconstructors
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Deconstructor for " << this->_name << " called" << std::endl;
}

// Overloaded Operators
DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->_name = src._name + "_clap_trap";
	this->_hitPoint = src._hitPoint;
	this->_Energy = src._Energy;
	this->_attackDamage = src._attackDamage;
	return *this;
}

// Public Methods
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hello i am a DiamondTrap named " << this->_Name <<
	" and i am originated from the ClapTrap named " << ClapTrap::_Name << "." <<
	std::endl;
}
