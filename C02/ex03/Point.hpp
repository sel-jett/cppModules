/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 05:48:27 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/15 20:20:45 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point {
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(const Fixed& a, const Fixed& b);
        Point(const Point& point);
        Point& operator=(const Point& point);
        const Fixed& getx() const;
        const Fixed& gety() const;
        ~Point();
};
bool bsp( Point const a, Point const b, Point const c, Point const point);