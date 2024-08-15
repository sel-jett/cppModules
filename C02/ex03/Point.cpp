/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 05:50:34 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/15 20:24:18 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(0),y(0){}

const Fixed& Point::getx() const
{
    return (this->x);
}

const Fixed& Point::gety() const
{
    return (this->y);
}

Point::Point(const Fixed& a, const Fixed& b):x(a),y(b){}

Point::Point(const Point& point): x(point.getx()), y(point.gety())
{   
}

Point& Point::operator=(const Point& point)
{
    (void)point;
    return (*this);
}

Point::~Point(){}