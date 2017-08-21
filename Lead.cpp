/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lead.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:43:11 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/21 19:16:28 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lead.hpp"

Lead::Lead(void) : _arg("-v") {
	if (verbose_option == true)
		std::cout << "Lead's constructor called\n";
}

Lead::Lead(Lead const & cpy) : _arg("-v") {
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
	if (verbose_option == true)
		std::cout << "reader called\n";
	if (ac == 3 && _arg.compare(av[1]) == 0) {
		_arg = av[2];
		std::cout << _arg;
	}
	else if (ac == 2) {
		_arg = av[1];
		std::cout << _arg;
	}
	else {
		std::string msg;
		msg.append(GREEN);
		msg.append("Usage :\n\t-v: verbose\n\tThis program takes an argument in parameter,");
		msg.append("a polynomial equation (simple or quadratic)\n\t(ex: 5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0).");
		msg.append(NORMAL);
		throw BaseException(msg);
	}
}
