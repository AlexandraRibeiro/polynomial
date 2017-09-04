/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Resolver.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:35:39 by aribeiro          #+#    #+#             */
/*   Updated: 2017/09/04 21:49:15 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Resolver.hpp"

Resolver::Resolver(std::vector<s_Xpow> & _Xpow, long double ld1) :	xpow(_Xpow),
																	_maxDegree(ld1) {
	if (debug_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Resolver's constructor called\n";
}

Resolver::Resolver(Resolver const & cpy) :	xpow(this->get_xpow()),
											_maxDegree(this->get_maxDegree()) {
	*this = cpy;
}

Resolver::~Resolver(void) {
	if (debug_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Resolver's destructor called\n";
}

Resolver &	Resolver::operator=(Resolver const & rhs) {
	xpow = rhs.get_xpow();
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
	else if (_maxDegree == 2)
		discriminant();
}


void		Resolver::discriminant(void) {
	/*
	 * a * X^2 + b * X^1 + c * X^0 = 0
	 * delta = b^2 - 4ac
	 */
	_a = 0;
	_b = 0;
	_c = 0;
	int k = 0;
	while (k < static_cast<int>(xpow.size())) {
		if (xpow[k].allPower.back() == 0)
			_c = xpow[k].allCoeff.back();
		else if (xpow[k].allPower.back() == 1)
			_b = xpow[k].allCoeff.back();
		else if (xpow[k].allPower.back() == 2)
			_a = xpow[k].allCoeff.back();
		k++;
	}
	std::cout << "a = " << _a << std::endl;
	std::cout << "b = " << _b << std::endl;
	std::cout << "c = " << _c << std::endl;
	_b = _b * _b;
	std::cout << "new b = " << _b << std::endl;
	_delta = _b - 4 * _a * _c;
	std::cout << "delta =  " << _delta << std::endl;
	if (_delta > 0)
		deltaPositif();
	else if (_delta == 0)
		deltaZero();
	// else
	//

}

void		Resolver::deltaPositif(void) {
	/*
	* 2 solutions :
	* X' = ( −b + √_delta ) / 2a
	* X'' =( −b − √_delta ) / 2a
	*/
	// long double x1;
	// long double x2;
	std::cout << "Discriminant is strictly positive, the two solutions are : \n";


}

void		Resolver::deltaZero(void) {
	/*
	* 1 solution :
	* X = −b/2a
	*/
	std::cout << "Discriminant is null, the solution is : \n";
	//attention div par zero!!!
	std::cout << -_b/2*_a << std::endl;

}




// GETTERS _____________________________________________________________________
std::vector<s_Xpow>			& Resolver::get_xpow(void) const {
	return xpow;
}

long double					Resolver::get_maxDegree(void) const {
	return _maxDegree;
}
