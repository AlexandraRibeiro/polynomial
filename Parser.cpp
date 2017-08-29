/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:05:34 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/29 20:54:03 by aribeiro         ###   ########.fr       */
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
	std::string line = "";
	while (c < lexical.size()) {
		if (c != 0 && (lexical[c].original_line).compare(line) != 0) {
			_op = true;
			_nb = false;
			lexical.insert(lexical.begin() + c, s_scanner());
			lexical[c].token = END;
			c++;
		}
		token = lexical[c].token;
		if (token == RNUM && lexical[c].lexeme.size() == 1)
			throw BaseException("=> (parser) Error '.' is not a valid real number.");
		line = lexical[c].original_line;
		c = set_booleans(token, c, lexical);
		_prev_token = token;
		c++;
	}
	// clean_lexical(lexical);
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
	}
	return c;
}


//
//
// void		Parser::clean_lexical(std::vector<s_scanner> & lexical) {
// 	size_t c = 0;
// 	while (c < lexical.size()) {
// 		if (lexical[c].token == PLUS || lexical[c].token == MINUS) {
// 			lexical.erase(lexical.begin() + (c));
// 			c--;
// 		}
// 		else if (lexical[c].token == INUM)
// 			lexical[c].token = RNUM;
// 		c++;
// 	}
// }
