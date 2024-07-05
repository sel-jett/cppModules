/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:05:53 by sel-jett          #+#    #+#             */
/*   Updated: 2024/07/05 13:19:15 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

#include <fstream>

Sed::Sed(const std::string &filename, const std::string &s1, const std::string &s2): filename(filename), s1(s1), s2(s2)
{
    std::cout << "Sed's Contructed is called !!" << std::endl;
}

Sed::~Sed()
{
    std::cout << "Sed being destructed !!" << std::endl;
}

void Sed::search_and_replace()
{
    std::string     text;
    std::string     fullText;

    std::ifstream fs(this->filename);
    if (fs.fail())
    {
        std::cout << "\033[31m" << this->filename << " failed to open !!!" << std::endl;
        return ;
    }
    while (getline(fs, text))
    {
        if (!fullText.empty() && !text.empty())
            fullText = fullText + '\n' + text;
        else if (!text.empty())
            fullText = fullText + text;
    }
    if (fullText.empty())
    {
        std::cout << "Error: file is empty" << std::endl;
        return ;
    }
    std::ofstream ostrm(this->filename + ".replace");
    if (ostrm.good())
        std::cout << "\033[31m" << "goooooood !!!" << std::endl;
    // std::cout << "\033[32m" << fullText << std::endl;
    
}
