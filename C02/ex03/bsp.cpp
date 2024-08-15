/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bgety(): sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 06:14:29 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/15 20:28:05 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    int area_of_triangle = (a.getx().getRawBits() * (b.gety().getRawBits() - c.gety().getRawBits()) + b.getx().getRawBits() * (c.gety().getRawBits() - a.gety().getRawBits()) + c.getx().getRawBits() * (a.gety().getRawBits() - b.gety().getRawBits()));
    (area_of_triangle > 0) ? 1 : area_of_triangle = -area_of_triangle;
    area_of_triangle /= 2;

    int area_of_triangle1 = (a.getx().getRawBits() * (b.gety().getRawBits() - point.gety().getRawBits()) + b.getx().getRawBits() * (point.gety().getRawBits() - a.gety().getRawBits()) + point.getx().getRawBits() * (a.gety().getRawBits() - b.gety().getRawBits()));
    (area_of_triangle1 > 0) ? 1 : area_of_triangle1 = -area_of_triangle1;
    area_of_triangle1 /= 2;
    
    int area_of_triangle2 = (a.getx().getRawBits() * (point.gety().getRawBits() - c.gety().getRawBits()) + point.getx().getRawBits() * (c.gety().getRawBits() - a.gety().getRawBits()) + c.getx().getRawBits() * (a.gety().getRawBits() - point.gety().getRawBits()));
    (area_of_triangle2 > 0) ? 1 : area_of_triangle2 = -area_of_triangle2;
    area_of_triangle2 /= 2;

    int area_of_triangle3 = (point.getx().getRawBits() * (b.gety().getRawBits() - c.gety().getRawBits()) + b.getx().getRawBits() * (c.gety().getRawBits() - point.gety().getRawBits()) + c.getx().getRawBits() * (point.gety().getRawBits() - b.gety().getRawBits()));
    (area_of_triangle3 > 0) ? 1 : area_of_triangle3 = -area_of_triangle3;
    area_of_triangle3 /= 2;

    int check = (area_of_triangle1 == 0) * 1 + (area_of_triangle2 == 0) * 1 + (area_of_triangle3 == 0) * 1;
    if (check > 0)
    {
        std::cout << "no" << std::endl;
        return (false);
    }
    if (area_of_triangle == (area_of_triangle1 + area_of_triangle2 + area_of_triangle3))
    {
        std::cout << "yes" << std::endl;
        return (true);
    }
    else
    {
        std::cout << "no" << std::endl;
        return (false);
    }
}