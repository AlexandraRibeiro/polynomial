/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lead.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:43:11 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/22 20:55:48 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lead.hpp"

Lead::Lead(void) : _arg("-v") {
	std::cout << "Lead's constructor called\n";
}

Lead::Lead(Lead const & cpy) : _arg("-v") {
	std::cout << "Lead's copy constructor called\n";
	*this = cpy;
}

Lead::~Lead(void) {
	std::cout << "Lead's destructor called\n";
}

Lead	&	Lead::operator=(Lead const & ) {return *this; }

void		Lead::reader(int ac, char **av) {
	std::cout << "DEBUG reader() called\n";
	if (ac == 3 && _arg.compare(av[1]) == 0) {
		verbose_option = true;
		_arg = av[2];
	}
	else if (ac == 3 && _arg.compare(av[2]) == 0) {
		verbose_option = true;
		_arg = av[1];
	}
	else if (ac == 2) {
		_arg = av[1];
	}
	else if (ac > 2) {
		throw BaseException("=> Error too many arguments.");
	}
	else {
		std::string msg;
		msg.append(NORMAL);
		msg.append("\n\tUSAGE\n\t------------\n\t");
		msg.append("This program takes an argument in parameter,\n\ta polynomial equation (simple or quadratic)");
		msg.append("\n\tex: 5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0\n\n\t");
		msg.append("-v : verbose\n");
		throw BaseException(msg);
	}
	regex();
}


void		Lead::regex(void) {
	std::cout << "DEBUG regex() called\n";
	std::string *regexValidCharacters = "";
	std::string *regexBeginEnd = "";

	if (_arg.compare("") == 0)
		throw BaseException("=> Error empty string.");
	_arg.erase(std::remove (_arg.begin(), _arg.end(), ' '), _arg.end()); 		//remove spaces

	std::cout << _arg << std::endl;
}
