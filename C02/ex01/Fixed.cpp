/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:03:42 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/13 06:34:53 by sel-jett         ###   ########.fr       */
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
    std::cout << "getRawBits member function called" << std::endl;
    return (this->int_value);
}

void Fixed::setRawBits( int const raw ){
    int_value = raw;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    int_value = fixed.int_value;
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
    int_value = (roundf(x * (1 << fractional_value)));
}

float Fixed::toFloat( void ) const
{
    return ((int_value) / (1 << fractional_value));
}

int Fixed::toInt( void ) const
{
    return (int_value >> fractional_value);
}


std::ostream& operator<<(std::ostream& stream, const Fixed x)
{
    stream << x.toFloat();
    return (stream);
}