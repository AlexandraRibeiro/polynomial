/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reducer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:41:10 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/31 17:32:54 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reducer.hpp"


Reducer::Reducer(std::vector<s_scanner> & lex) : lexical(lex)  {
	if (debug_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Reducer's constructor called\n";
}

Reducer::Reducer(Reducer const & cpy) : lexical(this->get_lexical()) {
	*this = cpy;
}

Reducer::~Reducer(void) {
	if (debug_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Reducer's destructor called\n";
}

Reducer &		Reducer::operator=(Reducer const & rhs) {
	lexical = rhs.get_lexical();
	return *this;
}



// step1 CALCULATE * ^ RNUM ____________________________________________________
void		Reducer::calculate_powerNum(void) {
	/* step 1 */
	size_t c = 0;
	long double result;
	while (c < lexical.size()) {
		if (lexical[c].token == POWER && lexical[c-1].token != XSYMB) {
			_ld1 = stringToLong(lexical[c-1].lexeme);
			_ld2 = stringToLong(lexical[c+1].lexeme);
			_sign = 1;
			if (_ld1 < 0 && _ld2 != 1) {
				_sign = -1;
				_ld1 = _ld1 * _sign;
			}
			result = _ld1;
			if (_ld2 == 0)
				result = 1;
			while (_ld2 > 1 && _ld1 > 1) {
				result = _ld1 * result;
				_ld2--;
			}
			lexical[c + 1].ld = result * _sign;
			lexical[c + 1].token = RNUM;
			lexical[c + 1].lexeme = longToString(lexical[c + 1].ld);
			lexical.erase(lexical.begin() + (c - 1));
			lexical.erase(lexical.begin() + (c - 1));
			c--;
		}
		else if (lexical[c].token == POWER && lexical[c-1].token == XSYMB) {	// X^6 => 6 (POWER)
			lexical[c+1].token = POWER;
			lexical.erase(lexical.begin() + (c));
			lexical.erase(lexical.begin() + (c-1));
			c--;
		}
		c++;
	}

	calculate_multiNum();
	/* step 2 */
	set_Xpow();
	/* step 3 */
	set_allNum();
	/* step4 */
	reduceAll();
}


void		Reducer::calculate_multiNum(void) {
	size_t c = 0;
	while (c < lexical.size()) {
		if (lexical[c].token == MULTI && lexical[c-1].token < 3 && lexical[c+1].token < 3) {
			_ld1 = stringToLong(lexical[c-1].lexeme);
			_ld2 = stringToLong(lexical[c+1].lexeme);
			lexical[c + 1].ld = _ld1 * _ld2;
			lexical[c + 1].token = RNUM;
			lexical[c + 1].lexeme = longToString(lexical[c + 1].ld);
			lexical.erase(lexical.begin() + (c - 1));
			lexical.erase(lexical.begin() + (c - 1));
			c--;
		}
		c++;
	}
}



// step2 SEARCH X ______________________________________________________________
void		Reducer::set_Xpow(void) {
	size_t c = 0;
	_sign = 1;
	_j = 0;
	bool multi = false;
	while (c < lexical.size()) {
		_Xpow.push_back(s_Xpow());
		while (c < lexical.size()) {
			if (lexical[c].token == MULTI) {
				if (multi == false) {
					push_Xpow(c-1);
					multi = true;
				}
				push_Xpow(c+1);
				c++;
			}
			else if (lexical[c].token == XSYMB) {
				if (c != 0 && lexical[c-1].token == MULTI)
					break;
				if ((c + 1) < lexical.size() && lexical[c+1].token == MULTI)
					break;
				push_Xpow(c);
			}
			else if (lexical[c].token == PLUS || lexical[c].token == MINUS || lexical[c].token == END) {
				if (lexical[c].token == END)
					_sign = -1;
				c++;
				multi = false;
				break;
			}
			c++;
		}
		_j++;
	}

	if (debug_option == true)
		debug_print_Xpow();
}



void		Reducer::push_Xpow(size_t c) {
	_Xpow[_j].sign = _sign;

	if (lexical[c].token == RNUM) {
		_ld1 = stringToLong(lexical[c].lexeme);
		lexical[c].lexeme = longToString(_ld1);
		_Xpow[_j].allCoeff.push_back(_ld1);
	}
	else if (lexical[c].token == POWER) {
		_ld1 = stringToLong(lexical[c].lexeme);
		lexical[c].lexeme = longToString(_ld1);
		_Xpow[_j].allPower.push_back(_ld1);
	}
	else if (lexical[c].token == XSYMB) {
		_ld1 = 1;
		if (lexical[c].lexeme.compare("-X") == 0)
			_ld1 = _ld1 * -1;
		_Xpow[_j].allPower.push_back(_ld1);
	}
}


void		Reducer::debug_print_Xpow(void) const {
	size_t c = 0;
	size_t j = 0;
	std::cout << BLUE << "\n\t****** DEBUG _Xpow ******\n" << NORMAL;
	while (c < _Xpow.size()) {
		j = 0;
		std::cout << "\tallPower =   ";
		while (j < _Xpow[c].allPower.size()) {
			std::cout << " " << _Xpow[c].allPower[j];
			j++;
		}
		j = 0;
		std::cout << "\n\tallCoeff =   ";
		while (j < _Xpow[c].allCoeff.size()) {
			std::cout << " " << _Xpow[c].allCoeff[j];
			j++;
		}
		std::cout << "\n\tsign = \t   " << _Xpow[c].sign << std::endl;
		std::cout << BLUE << "\t___________________________\n" << NORMAL;
		c++;
	}
}


// step3 REDUCE ALL RNUM _______________________________________________________
void		Reducer::set_allNum(void) {
	size_t c = 0;
	_sign = 1;
	while (c < lexical.size()) {
		if (lexical[c].token == RNUM) {
			_allNum.push_back(stringToLong(lexical[c].lexeme) * _sign);
			if (c+1 < lexical.size() && lexical[c+1].token == MULTI)
				_allNum.pop_back();
			else if (c-1 > 0 && lexical[c-1].token == MULTI)
				_allNum.pop_back();
		}
		if (lexical[c].token == MINUS && lexical[c+1].token == RNUM) {
			lexical[c+1].lexeme.insert(0,1,'-');
		}
		if (c != 0 && lexical[c].token == END) {
			_sign = -1;
		}
		c++;
	}

	if (debug_option == true)
		debug_print_allNum();

	calculate_allNum();
}


void		Reducer::calculate_allNum(void) {
	while (_allNum.size() > 1) {
		_ld1 = _allNum.back();
		_allNum.pop_back();
		_ld2 = _allNum.back();
		_allNum.pop_back();
		_ld1 = _ld1 + _ld2;
		_allNum.push_back(_ld1);
	}

	if (debug_option == true)
		debug_print_allNum();
}


void		Reducer::debug_print_allNum(void) const {
	size_t c = 0;
	std::cout << BLUE << "\n\t****** DEBUG _allNum ******\n" << NORMAL;
	while (c < _allNum.size()) {
		std::cout << "\t" << _allNum[c] << std::endl;
		c++;
	}
	std::cout << BLUE << "\t___________________________\n\n" << NORMAL;
}



// step4 PRINT REDUCE FORM ____________________________________________________
void		Reducer::reduceAll(void) {
	size_t c = 0;
	while (c < _Xpow.size()) {
		reduce_allCoeff(c);
		c++;
	}

	if (debug_option == true)
		debug_print_Xpow();

	sort_power();
}

void		Reducer::reduce_allCoeff(size_t c) {
	while (_Xpow[c].allCoeff.size() > 1) {
		_ld1 = _Xpow[c].allCoeff.back();
		_Xpow[c].allCoeff.pop_back();
		_ld2 = _Xpow[c].allCoeff.back();
		_Xpow[c].allCoeff.pop_back();
		_ld1 = _ld1 * _ld2;
		longToString(_ld1); //verif secu
		_Xpow[c].allCoeff.push_back(_ld1);
	}
}

void		Reducer::sort_power(void) {
	size_t c = 0;
	size_t j = 0;
	while (c < _Xpow.size()) {													// 3 cases : size = 0 / size = 1 / size > 1
		if (_Xpow[c].allCoeff.size() < 0)
			j++;
		else if (_Xpow[c].allCoeff.size() == 1)
			_ld1 = _Xpow[c].allCoeff.back();
		}
		c++;
	}

}



// GETTER ______________________________________________________________________
std::vector<s_scanner>	&	Reducer::get_lexical(void) const {
	return lexical;
}
