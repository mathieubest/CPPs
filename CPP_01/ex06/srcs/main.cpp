/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbest <mbest@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:07:12 by mbest             #+#    #+#             */
/*   Updated: 2024/11/07 15:18:57 by mbest            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"
#include "../includes/Support.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        invalid_arguments();
        return 1;
    }
    Harl harl;

    harl.complain(av[1]);
    return (0);
}