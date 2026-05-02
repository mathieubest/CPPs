/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbest <mbest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:15:05 by mbest             #+#    #+#             */
/*   Updated: 2025/02/24 17:41:45 by mbest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"

Character::Character() : _name("Default") {}

Character::Character(std::string const& name) : _name(name)
{
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = NULL;
        this->_floor[i] = NULL;
    }
}

Character::Character(const Character& copy)
{
    *this = copy;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i]) {
            delete this->_inventory[i];
            // this->_inventory[i] = NULL;
        }
        if (this->_floor[i]) {
            delete this->_floor[i];
        }
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other) {
        this->_name = other._name;
        for (int i = 0; i < 4; i++) {
            if (this->_inventory[i]) {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            } if (other._inventory[i]) {
                this->_inventory[i] = other._inventory[i]->clone();
            } else {
                this->_inventory[i] = NULL;
            }
            if (this->_floor[i]) {
                delete this->_floor[i];
                this->_floor[i] = NULL;
            } 
            if (other._floor[i]) {
                this->_floor[i] = other._floor[i]->clone();
            } else {
                this->_floor[i] = NULL;
            }
        }
    }
    return *this;
}

std::string const& Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    if (!m) {
        std::cout << "Nothing to equip" << std::endl;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] == NULL) {
            this->_inventory[i] = m;
            std::cout << "Equipped " << m->getType() << " in slot " << i + 1 << std::endl;
            return;
        }
    }
    std::cout << "Inventory is full" << std::endl;
    delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx]) {
        for (int i = 0; i < 4; i++) {
            if (this->_floor[i] == NULL) {
                this->_floor[i] = this->_inventory[idx];
                std::cout << "Unequipped " << this->_inventory[idx]->getType() << " from slot " << idx << std::endl;
                this->_inventory[idx] = NULL;
                break;
            }
        }
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4) {
        if (this->_inventory[idx]) {
            this->_inventory[idx]->use(target);
        } else {
            std::cout << "Nothing found at that index" << std::endl;
        }
    } else {
        std::cout << "Index out of range" << std::endl;
    }
}
