/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 02:37:38 by sel-jett          #+#    #+#             */
/*   Updated: 2024/07/01 17:37:52 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "The memory address of the string variable: \"" << &str << "\"" << std::endl;
    std::cout << "The memory address held by stringPTR: \"" << stringPTR << "\"" << std::endl;
    std::cout << "The memory address held by stringREF: \"" << &stringREF << "\"" << std::endl;

    std::cout << "The value of the string variable: \"" << str << "\"" << std::endl;
    std::cout << "The value pointed to by stringPTR: \"" << *stringPTR << "\"" << std::endl;
    std::cout << "The value pointed to by stringREF: \"" << stringREF << "\"" << std::endl;
    return 0;
}