/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:03:42 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/14 00:10:23 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractional_value = 8;

Fixed::Fixed():int_value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

int Fixed::getRawBits( void ) const {
    return (this->int_value);
}

void Fixed::setRawBits( int const raw ){
    int_value = raw;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    int_value = fixed.getRawBits();
    return *this;    
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int x)
{
    std::cout << "Int constructor called" << std::endl;
    int_value = x << fractional_value;
}

Fixed::Fixed(const float x)
{
    std::cout << "Float constructor called" << std::endl;
    int_value = roundf(x * (1 << fractional_value));
}

float Fixed::toFloat( void ) const
{
    return ((float)int_value / (1 << fractional_value));
}

int Fixed::toInt( void ) const
{
    return (int_value >> fractional_value);
}


std::ostream& operator<<(std::ostream& stream, const Fixed &x)
{
    stream << x.toFloat();
    return (stream);
}