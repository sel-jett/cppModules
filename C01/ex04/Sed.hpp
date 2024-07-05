/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:34:45 by sel-jett          #+#    #+#             */
/*   Updated: 2024/07/05 11:06:22 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>

class Sed {
    private :
        const std::string   filename;
        const std::string   s1;
        const std::string   s2;

    public:
        Sed(const std::string &filename, const std::string &s1, const std::string &s2);
        ~Sed();
        void    search_and_replace();
};

#endif