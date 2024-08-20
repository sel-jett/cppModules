/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-jett <sel-jett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 04:48:07 by sel-jett          #+#    #+#             */
/*   Updated: 2024/08/20 13:17:21 by sel-jett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// void f( void )
// {
//     system("leaks Fixed");
// }

int main()
{
    // atexit(f);
    const Animal    *j = new Cat() ;
    const Animal    *i = new Dog();
    delete j;//should not create a leak
    delete i;
    return 0;
}