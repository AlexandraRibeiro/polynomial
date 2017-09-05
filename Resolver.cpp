/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Resolver.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:35:39 by aribeiro          #+#    #+#             */
/*   Updated: 2017/09/05 18:19:41 by aribeiro         ###   ########.fr       */
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
	_a = 0;
	_b = 0;
	_c = 0;
	int k = 0;
	_maxDegree = 2;
	while (k < static_cast<int>(xpow.size())) {

		if (xpow[k].allPower.back() == 0) {
			_c = 1;
			if (xpow[k].allCoeff.size() == 1)
				_c = xpow[k].allCoeff.back();
		}
		else if (xpow[k].allPower.back() == 1) {
			_b = 1;
			if (xpow[k].allCoeff.size() == 1)
				_b = xpow[k].allCoeff.back();
		}
		else if (xpow[k].allPower.back() == 2) {
			_a = 1;
			if (xpow[k].allCoeff.size() == 1)
				_a = xpow[k].allCoeff.back();
		}
		else if (xpow[k].allPower.back() > _maxDegree)
			_maxDegree = xpow[k].allPower.back();
		k++;
	}

	if (_maxDegree > 2) {
		std::cout << YELLOW << "Polynomial degree : " << NORMAL << _maxDegree << std::endl;
		std::cout << "The polynomial degree is stricly greater than 2, I can't solve.";
		throw BaseException("");
	}

	if (_a != 0)
		discriminant();
	else if (_b != 0 && _a == 0)
		resolve_1degree();
	else
		resolve_others();
}



// DEGREE 1 ____________________________________________________________________
void		Resolver::resolve_1degree(void) {
	long double result = - _c / _b;

	std::cout << YELLOW << "Polynomial degree : " << NORMAL << "1" << std::endl;
	std::cout << YELLOW << "The solution is :\n" << NORMAL;

	if (result == -0)
		std::cout << 0 << std::endl;
	else
		std::cout << result << std::endl;

}



// DEGREE 2 ____________________________________________________________________
void		Resolver::discriminant(void) {
	/*
	 * a * X^2 + b * X^1 + c * X^0 = 0
	 * delta = b^2 - 4ac
	 */

	std::cout << YELLOW << "Polynomial degree : " << NORMAL << "2" << std::endl;

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

	heronMethod();

}


void			Resolver::deltaNeg(void) {
	/*
	* 2 solutions :
	* x1 = (−b − i√(-Δ)) / (2a)
	* x2 = (−b + i√(-Δ)) / (2a)
	*/

	std::cout << "Discriminant is strictly negative.\n";

	_delta *= -1;
	long double imag = heronMethod();
	long double under = 2 * _a;

	if (imag == 0) {
		std::cout << YELLOW << "The solutions are :\n" << NORMAL;
		std::cout << -_b / under << std::endl;
	}
	else {
		std::cout << YELLOW << "The two complex solutions are :\n" << NORMAL;
		//x1
		std::cout << (-_b / under) << " - ";
		if (imag/under == 1)
	 		std::cout << "i\n";
		else
			std::cout << imag/under << "i\n";
		//x2
		std::cout << (-_b / under) << " + ";
		if (imag/under == 1)
	 		std::cout << "i\n";
		else
			std::cout << imag/under << "i\n";
	}
}


long double		Resolver::heronMethod(void) {
	long double a1 = 2;
	long double average;
	int i = 0;

	average = _delta;

	while (a1 > 1 && i < 20) {
		a1 = (average + _delta/average) / 2;
		average = a1;
		i++;
	}

	return a1;
}


// OTHERS ______________________________________________________________________
void			Resolver::resolve_others(void) {

	std::cout << YELLOW << "Polynomial degree : " << NORMAL << "0" << std::endl;

	_a = xpow[0].allCoeff.back();
	if (_a != 0)
		throw BaseException("=> (resolver) Error not a valid equation.");
	else
		std::cout << "All real numbers are solution.\n";
}


// GETTERS _____________________________________________________________________
std::vector<s_Xpow>			& Resolver::get_xpow(void) const {
	return xpow;
}

long double					Resolver::get_maxDegree(void) const {
	return _maxDegree;
}
