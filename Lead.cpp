/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lead.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:43:11 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/17 19:31:04 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lead.hpp"

Lead::Lead(void) {
	if (verbose_option == true)
		std::cout << "Lead's constructor called\n";
}

Lead::Lead(Lead const & cpy) {
	if (verbose_option == true)
		std::cout << "Lead's copy constructor called\n";
	*this = cpy;
}

Lead::~Lead(void) {
	if (verbose_option == true)
		std::cout << "Lead's destructor called\n";
}

Lead	&	Lead::operator=(Lead const & ) {return *this; }

void		Lead::reader(int ac, char **av) {
	std::cout << "reader called\n";
	ac = ac - 0;
	av = av - 0;
}
