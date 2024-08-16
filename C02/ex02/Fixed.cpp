/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:03:42 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/16 01:38:56 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractional_value = 8;

Fixed::Fixed():int_value(0){
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    // std::cout << "Copy constructor called" << std::endl;
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
    // std::cout << "Copy assignment operator called" << std::endl;
    if (&fixed != this)
        int_value = fixed.getRawBits();
    return *this;    
}

Fixed& Fixed::operator++()
{
    this->int_value++;
    return *this;    
}

Fixed Fixed::operator--( int )
{
    Fixed fixed = *this;
    int_value--;
    return (fixed);
}
Fixed Fixed::operator++( int )
{
    Fixed fixed = *this;
    int_value++;
    return (fixed);   
}

Fixed& Fixed::operator--()
{
    int_value--;
    return *this;    
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int x)
{
    // std::cout << "Int constructor called" << std::endl;
    int_value = x << fractional_value;
}

Fixed::Fixed(const float x)
{
    // std::cout << "Float constructor called x : " << x * (1 << fractional_value) << std::endl;
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

bool Fixed::operator<(const Fixed& fixed)
{
    return (int_value < fixed.int_value);
}

bool Fixed::operator>(const Fixed& fixed)
{
    return (int_value > fixed.int_value);
}

bool Fixed::operator>=(const Fixed& fixed)
{
    return (int_value >= fixed.int_value);
}

bool Fixed::operator<=(const Fixed& fixed)
{
    return (int_value <= fixed.int_value);
}

bool Fixed::operator==(const Fixed& fixed)
{
    return (int_value == fixed.int_value);
}

bool Fixed::operator!=(const Fixed& fixed)
{
    return (int_value != fixed.int_value);
}

Fixed Fixed::operator+(const Fixed& fixed)
{
    Fixed res;
    res.int_value = int_value + fixed.int_value;
    return (res);
}

Fixed Fixed::operator-(const Fixed& fixed)
{
    Fixed res;
    res.int_value = int_value - fixed.int_value;
    return (res);
}

Fixed Fixed::operator*(const Fixed& fixed)
{
    Fixed res;
    res.int_value = (int_value * fixed.int_value) >> fractional_value;
    return (res);
}

Fixed Fixed::operator/(const Fixed& fixed)
{
    Fixed res;
    res.int_value = roundf(((float)int_value / fixed.int_value) * (1 << fractional_value));
    return (res);
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
    if (obj1 > obj2)
        return (obj2);
    else
        return (obj1);
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
    if (obj1 < obj2)
        return (obj2);
    else
        return (obj1);
}

Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
    if ((Fixed&)obj1 > (Fixed&)obj2)
        return (Fixed&)obj2;
    else
        return (Fixed&)obj1;
}

Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
    if ((Fixed&)obj1 < (Fixed&)obj2)
        return (Fixed&)obj2;
    else
        return (Fixed&)obj1;
}