/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:05:34 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 22:26:16 by aribeiro         ###   ########.fr       */
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
		token = lexical[c].token;
		if (token == RNUM && lexical[c].lexeme.size() == 1)
			throw BaseException("=> (parser) Error '.' is not a valid real number.");
		if (c != 0 && (lexical[c].original_line).compare(line) != 0) {
			_op = true;
			_nb = false;
		}
		line = lexical[c].original_line;
		c = set_booleans(token, _prev_token, c, lexical);
		_prev_token = token;
		c++;
	}
	delete_plus_minus(lexical);
	fill_operands(lexical);
//***********************************************
	debug_print_operands();
//***********************************************
}

size_t		Parser::set_booleans(int token, int prev_token, size_t c, std::vector<s_scanner> & lexical) {
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
	else if (token < 4 && _nb == false) { 										// INUM || RNUM || XSYMB
		_op = false;
		_nb = true;
		if (prev_token == MINUS) {
			lexical[c].lexeme.insert(0,1,'-');
		}
		else if (_sign == -1)
			lexical[c].lexeme.insert(0,1,'-');
		_sign = 1;
	}
	else if (token > 3 && _op == false) {										// PLUS || MINUS || POWER || MULTI || DIV
		_op = true;
		_nb = false;
	}
	return c;
}

void		Parser::delete_plus_minus(std::vector<s_scanner> & lexical) {
	size_t c = 0;
	while (c < lexical.size()) {
		if (lexical[c].token == PLUS || lexical[c].token == MINUS) {
			lexical.erase(lexical.begin() + (c));
			c--;
		}
		c++;
	}
}



// OPERANDS ____________________________________________________________________
void		Parser::fill_operands(std::vector<s_scanner> & lexical) {
	size_t i = 0;
	size_t j = -1;
	int pos = 1;
	init_operands(lexical);
	while (i < lexical.size()) {
		if (lexical[i].token < 3 && pos == 1) {									//INUM || RNUM
			j++;
			_operands[j].ld1 = stringToLong(lexical[i].lexeme);
		}
		else if (lexical[i].token < 3 && pos == 2) {
			_operands[j].ld2 = stringToLong(lexical[i].lexeme);
			pos--;
			j++;
		}
		else if (lexical[i].token == XSYMB && pos == 1) {
			j++;
			_operands[j].s1.append(lexical[j].lexeme);
		}
		else if (lexical[i].token == XSYMB && pos == 2) {
			_operands[j].s2.append(lexical[j].lexeme);
			pos--;
			j++;
		}
		else if (lexical[i].token == MULTI)
			pos++;
		// else if (lexical[i].token == POWER)
		// 	fill_operands_power()
		i++;
	}

}

void		Parser::init_operands(std::vector<s_scanner> & lexical) {
	size_t c = 0;
	int j = 0;
	while (c < lexical.size()) {
		_operands.push_back(s_operands());
		_operands[j].ld1 = 1;
		_operands[j].ld2 = 1;
		// _operands[j].s1 = NULL;
		// _operands[j].s2 = NULL;
		c++;
		j++;
	}
}


void		Parser::debug_print_operands(void) {
	size_t c = 0;
	std::cout << BLUE << "\n\n\t****** DEBUG OPERANDS ******\n" << NORMAL;
	while (c < _operands.size())
	{
		std::cout << "\tld1 = " << _operands[c].ld1 << std::endl;
		std::cout << "\tld2 = " << _operands[c].ld2 << std::endl;
		std::cout << "\ts1 = '" << _operands[c].s1 << "'\n";
		std::cout << "\ts2 = '" << _operands[c].s2 << "'\n";
		std::cout << BLUE << "\t___________________________\n" << NORMAL;
		c++;
	}
	std::cout << "\n";
}
