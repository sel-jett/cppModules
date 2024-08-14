/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:58:34 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/14 00:09:11 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed {
    private:
        int int_value;
        static const int fractional_value;
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed(const int value);
        Fixed(const float value);
        Fixed& operator=(const Fixed& fixed);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed &x);