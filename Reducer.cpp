/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reducer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:41:10 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/25 20:21:36 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reducer.hpp"


Reducer::Reducer(void) {
	if (debug_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Reducer's constructor called\n";
}

Reducer::Reducer(Reducer const & cpy) {
	*this = cpy;
}

Reducer::~Reducer(void) {
	if (debug_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Reducer's destructor called\n";
}

Reducer &		Reducer::operator=(Reducer const & ) {
	return *this;
}

// void			Reducer::reduce_equation(std::vector<s_scanner> & lexical) {
//
// }
