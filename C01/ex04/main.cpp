/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:33:52 by sel-jett          #+#    #+#             */
/*   Updated: 2024/07/05 11:15:02 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>

#include "Sed.hpp"

int main (void)
{
    std::string     filename;
    std::string     s1;
    std::string     s2;
    
    while (filename.empty())
    {
        std::cout << "enter a file name : ";
        getline(std::cin, filename);
    }
    while (s1.empty())
    {
        std::cout << "enter a string to be replaced : ";
        getline(std::cin, s1);
    }
    while (s2.empty())
    {
        std::cout << "enter a string to replace with : ";
        getline(std::cin, s2);
    }

    Sed sed(filename, s1, s2);
    sed.search_and_replace();
    // fs.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    std::cout << "filename : " << filename << " s1 : " << s1 << " s2 : " << s2 << std::endl;
}