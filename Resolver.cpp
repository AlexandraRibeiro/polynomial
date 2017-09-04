/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Resolver.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:35:39 by aribeiro          #+#    #+#             */
/*   Updated: 2017/09/04 18:35:02 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Resolver.hpp"

Resolver::Resolver(std::vector<s_Xpow> & _Xpow, std::vector<long double> & _allNum, long double ld1) :
																						xpow(_Xpow),
																						allNum(_allNum),
																						_maxDegree(ld1) {
	if (debug_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Resolver's constructor called\n";
}

Resolver::Resolver(Resolver const & cpy) :	xpow(this->get_xpow()),
											allNum(this->get_allNum()),
											_maxDegree(this->get_maxDegree()) {
	*this = cpy;
}

Resolver::~Resolver(void) {
	if (debug_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Resolver's destructor called\n";
}

Resolver &	Resolver::operator=(Resolver const & rhs) {
	xpow = rhs.get_xpow();
	allNum = rhs.get_allNum();
	_maxDegree = rhs.get_maxDegree();
	return *this;
}


// ____________________________________________________________________________
void		Resolver::tryToResolve(void) {
	print_degree();

}

void		Resolver::print_degree(void) {
	std::cout << YELLOW << "Polynomial degree : " << NORMAL << _maxDegree << std::endl;
	if (_maxDegree > 2) {
		std::cout << "The polynomial degree is stricly greater than 2, I can t solve.";
		throw BaseException("");
	}

}




// GETTERS _____________________________________________________________________
std::vector<s_Xpow>			& Resolver::get_xpow(void) const {
	return xpow;
}

std::vector<long double>	& Resolver::get_allNum(void) const {
	return allNum;
}

long double					Resolver::get_maxDegree(void) const {
	return _maxDegree;
}
