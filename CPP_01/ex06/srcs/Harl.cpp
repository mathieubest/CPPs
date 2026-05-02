#include "../includes/Harl.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbest <mbest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:40:24 by mbest             #+#    #+#             */
/*   Updated: 2024/11/07 15:02:20 by mbest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() { return; }

Harl::~Harl() { return; }

void Harl::debug(void) {
    std::cout << "--[DEBUG]--" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
    std::cout << std::endl;
}

void Harl::info(void) {
    std::cout << "--[INFO]--" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
    std::cout << std::endl;
}

void Harl::warning(void) {
    std::cout << "--[WARNING]--" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;

}

void Harl::error(void) {
    std::cout << "--[ERROR]--" << std::endl;
    std::cout << "This is unacceptable ! I want to speak to the manager now." <<std::endl;
    std::cout << std::endl;

}

void Harl::complain(std::string level) {
    int i = 0;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*fptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (i = 0; i < 4; i++) {
        if (levels[i] == level) {
            while (i < 4) {
                (this->*fptr[i])();
                i++;
            }
            return ;
        }
    }
    std::cout << "Invalid level..." << std::endl;
    std::cout << "These are the levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
}