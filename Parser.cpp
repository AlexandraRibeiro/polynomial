/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:05:34 by aribeiro          #+#    #+#             */
/*   Updated: 2017/09/04 16:47:04 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser(void) {
	if (debug_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Parser's constructor called\n";
}

Parser::Parser(Parser const & cpy) {
	*this = cpy;
}

Parser::~Parser(void) {
	if (debug_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Parser's destructor called\n";
}

Parser &	Parser::operator=(Parser const & ) {
	return *this;
}


// PARSING _____________________________________________________________________
void		Parser::set_parsing(std::vector<s_scanner> & lexical) {
	size_t c = 0;
	int token;
	_prev_token = -1;
	_op = true;
	_nb = false;
	while (c < lexical.size()) {
		if (lexical[c].token == END) {
			_op = true;
			_nb = false;
			c++;
		}
		token = lexical[c].token;
		if (token == RNUM && lexical[c].lexeme.size() == 1)
			throw BaseException("=> (parser) Error '.' is not a valid real number.");
		c = set_booleans(token, c, lexical);
		_prev_token = token;
		c++;
	}
}

size_t		Parser::set_booleans(int token, size_t c, std::vector<s_scanner> & lexical) {
	if (token == INUM)
		lexical[c].token = RNUM;												// INUM -> RNUM
	if (token == PLUS && _op == true) {
		lexical.erase(lexical.begin() + (c));
		_sign = 1;
		c--;
	}
	else if (token == MINUS && _op == true) {
		lexical.erase(lexical.begin() + (c));
		_sign = -1;
		c--;
	}
	else if (token < 4 && _nb == false) { 										// RNUM || XSYMB
		_op = false;
		_nb = true;
		if (_sign == -1)
			lexical[c].lexeme.insert(0,1,'-');
		_sign = 1;
	}
	else if (token > 3 && _op == false) {										// PLUS || MINUS || POWER || MULTI || DIV
		_op = true;
		_nb = false;
		if (token == MINUS)
			_sign = -1;
	}
	return c;
}
