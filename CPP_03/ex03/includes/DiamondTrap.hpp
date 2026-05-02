#pragma once

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
	// Constructors
		DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap(std::string name);

	// Deconstructors
		~DiamondTrap();

	// Overloaded Operators
		DiamondTrap &operator=(const DiamondTrap &src);

	// Public Methods
		void attack(const std::string &target);
		void whoAmI(void);
	// Getter

	// Setter

};