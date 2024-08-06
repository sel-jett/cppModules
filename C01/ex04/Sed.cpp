/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:05:53 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/06 02:14:58 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(const std::string &filename, const std::string &s1, const std::string &s2): filename(filename), s1(s1), s2(s2)
{
	// std::cout << "Sed's Contructed is called !!" << std::endl;
}

Sed::~Sed()
{
	// std::cout << "Sed being destructed !!" << std::endl;
}

void Sed::search_and_replace()
{
	if (!std::freopen((this->filename).c_str(), "r", stdin) || \
			!std::freopen(((this->filename + ".replace")).c_str(), "w+", stdout))
		std::cerr << "failed to load the new file :(" << std::endl;
	else
	{
		std::string text;
		std::getline(std::cin, text, '\0');
		if (text.empty())
		{
			std::cerr << "empty file" << std::endl;
			return ;
		}
		while (!text.empty())
		{
			int s1 = text.find(this->s1);
			if (s1 == -1)
			{
				std::cout << text;
				text = text.substr(text.length());
			}
			else
			{
				std::cout << text.substr(0, s1) << this->s2;
				text = text.substr(s1 + (this->s1).length());
			}
		}
		fclose(stdout);
	}
}
