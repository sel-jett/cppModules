/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:58:34 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/16 01:38:48 by sel-jett         ###   ########.fr       */
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
        Fixed& operator++();
        Fixed operator++( int );
        Fixed operator--( int );
        Fixed& operator--();
        bool operator<(const Fixed& fixed);
        bool operator>(const Fixed& fixed);
        bool operator>=(const Fixed& fixed);
        bool operator<=(const Fixed& fixed);
        bool operator==(const Fixed& fixed);
        bool operator!=(const Fixed& fixed);
        Fixed operator+(const Fixed& fixed);
        Fixed operator-(const Fixed& fixed);
        Fixed operator*(const Fixed& fixed);
        Fixed operator/(const Fixed& fixed);
        static Fixed& min(Fixed& obj1, Fixed& obj2);
        static Fixed& max(Fixed& obj1, Fixed& obj2);
        static Fixed& min(const Fixed& obj1, const Fixed& obj2);
        static Fixed& max(const Fixed& obj1, const Fixed& obj2);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed &x);