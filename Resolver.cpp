/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Resolver.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:35:39 by aribeiro          #+#    #+#             */
/*   Updated: 2017/09/05 00:23:12 by aribeiro         ###   ########.fr       */
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
	_delta = (_b * _b) - 4 * _a * _c;

	if (verbose_option == true) {
		std::cout << YELLOW << "\nDiscriminant :\n" << NORMAL;
		std::cout << "delta = b^2 - 4 * a * c\n";
		std::cout << "delta = " << _b << "^2 - 4 * " << _a << " * " << _c << std::endl;
		std::cout << "delta = " << _delta << std::endl;
	}

	if (_delta == 0)
		deltaZero();
	else if (_delta > 0)
		deltaPositif();
	else
		deltaNeg();
}



void		Resolver::deltaZero(void) {
	/*
	* 1 solution :
	* X = −b/(2a)
	*/
	std::cout << "Discriminant is null.\n";
	std::cout << YELLOW << "The solution is :\n" << NORMAL;

	//attention div par zero!!!
	std::cout << -_b / (2 * _a) << std::endl;

}

void		Resolver::deltaPositif(void) {
	/*
	* 2 solutions :
	* x1 = ( −b - √_delta ) / (2a)
	* x2 =( −b + √_delta ) / (2a)
	*/

	std::cout << "Discriminant is strictly positive.\n";
	std::cout << YELLOW << "The two solutions are :\n" << NORMAL;

	long double racine = heronMethod();

	std::cout << (-_b - racine) / (2 * _a) << std::endl;
	std::cout << (-_b + racine) / (2 * _a) << std::endl;
	//attention div par zero!!!

	heronMethod();

}


void			Resolver::deltaNeg(void) {
	/*
	* 2 solutions :
	* x1 = (−b − i√(-Δ)) / (2a)
	* x2 = (−b + i√(-Δ)) / (2a)
	*/

	std::cout << "Discriminant is strictly negative.\n";
	std::cout << YELLOW << "The two solutions are :\n" << NORMAL;

	_delta *= -1;
	// long double racine = heronMethod();

	if (_b > 0)
		std::cout << "(-" << _b;
	else
		std::cout << "(" << _b;
	std::cout << " - i√" << _delta << ") / (2 * " << _a << ")\n";

	if (_b > 0)
		std::cout << "(-" << _b;
	else
		std::cout << "(" << _b;
	std::cout << " + i√" << _delta << ") / (2 * " << _a << ")\n";
}


long double		Resolver::heronMethod(void) {
	long double a1 = 2;
	long double average;
	int i = 0;

	average = _delta;

	while (a1 > 1 && i < 7) {
		a1 = (average + _delta/average) / 2;
		average = a1;
		i++;
	}

	return a1;
}

// GETTERS _____________________________________________________________________
std::vector<s_Xpow>			& Resolver::get_xpow(void) const {
	return xpow;
}

long double					Resolver::get_maxDegree(void) const {
	return _maxDegree;
}
