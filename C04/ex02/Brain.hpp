/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 20:46:47 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/20 08:51:25 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& obj);
        Brain& operator=(const Brain& obj);
        ~Brain();
};