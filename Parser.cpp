/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:05:34 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/25 17:51:35 by aribeiro         ###   ########.fr       */
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
	_op = true;
	_nb = false;
	std::string line = "";
	while (c < lexical.size()) {
		token = lexical[c].token;
		if (c != 0 && (lexical[c].original_line).compare(line) != 0) {
			_op = true;
			_nb = false;
		}
		line = lexical[c].original_line;
		c = set_booleans(token, c, lexical);
		c++;
	}
}

size_t		Parser::set_booleans(int token, size_t c, std::vector<s_scanner> & lexical) {
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
	else if (token < 4 && _nb == false) {
		_op = false;
		_nb = true;
		if (_sign == -1)
			lexical[c].lexeme.insert(0,1,'-');
		_sign = 1;
	}
	else if (token > 3 && _op == false) {
		_op = true;
		_nb = false;
	}
	return c;
}

// void		Parser::set_errorParser(std::string opOrnb, std::string &str) {
// 	_errorParser.append("=> (parser) Error missing ");
// 	_errorParser.append(opOrnb);
// 	_errorParser.append(" in this part ");
// 	_errorParser.append(str);
// 	_errorParser.append("'");
// }
