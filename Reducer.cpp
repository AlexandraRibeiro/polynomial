/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reducer.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:41:10 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/29 01:51:13 by aribeiro         ###   ########.fr       */
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



// CALCULATE NUM _______________________________________________________________
void		Reducer::calculate_powerNum(void) {
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
		else if (lexical[c].token == POWER && lexical[c-1].token == XSYMB) {
			lexical[c+1].token = POWER;
			lexical.erase(lexical.begin() + (c));
		}
		c++;
	}

	calculate_multiNum();
	set_allNum();
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


void		Reducer::set_allNum(void) {
	size_t c = 0;
	std::string line = "";
	_sign = 1;
	while (c < lexical.size()) {
		if (c != 0 && (lexical[c].original_line).compare(line) != 0)
			_sign = -1;
		if (lexical[c].token == RNUM)
			_allNum.push_back(stringToLong(lexical[c].lexeme) * _sign);
		if (lexical[c].token == RNUM && c - 1 > 0 && lexical[c - 1].token == MULTI) {
			lexical[c].token = COEFF;
			_allNum.pop_back();
		}
		else if (lexical[c].token == MULTI && lexical[c - 1].token == RNUM) {
			lexical[c - 1].token = COEFF;
			_allNum.pop_back();
		}
		line = lexical[c].original_line;
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



// X POWER _____________________________________________________________________
void		Reducer::search_powerX(std::vector<s_scanner> & lexical) {
	size_t c = 0;
	int j = -1;
	_sign = 1;
	std::string line = "";
	while (c < lexical.size()) {
		if (c != 0 && (lexical[c].original_line).compare(line) != 0)
			_sign = -1;
		if (lexical[c].token == COEFF || lexical[c] == XSYMB) {
			j++;
			_Xpow.push_back(s_Xpower());
			c = push_Xpower(c, j);
		}
		line = lexical[c].original_line;
		c++;
	}
}


void		Reducer::push_Xpower(size_t c, int j) {
	_Xpow[j].power = 1;															//by default
	_Xpow[j].sign = _sign;
	while (c < lexical.size()) {
		if (lexical[c].token == COEFF) {
			_ld1 = stringToLong(lexical[c].lexeme);
			lexical[c].lexeme = longToString(_ld1);
			_Xpow[j].allCoeff.push_back(_ld1);
			c++;
		}
		else if (lexical[c].token == MULTI) {
			c++;
		}
		else if (l)
		else
			break;
	}
	return c;
	//attention X sans puissance
}



// GETTER ______________________________________________________________________
std::vector<s_scanner>	&	Reducer::get_lexical(void) const {
	return lexical;
}
