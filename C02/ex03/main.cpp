/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:58:02 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/16 02:03:52 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
    Fixed const a( 7 );
    Fixed const b( 7 );
    Fixed const c( 11 );
    Fixed const d( 1 );
    Fixed const e( 2 );
    Fixed const f( 2 );
    Fixed const h( 7 );
    Fixed const g( 2 );
    Point const x(a, b);
    Point const y(c, d);
    Point const z(e, f);
    Point const k(h, g);
    
    bsp( x, y, z, k);
    return 0;
}