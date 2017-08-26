/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 16:53:26 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/25 22:39:09 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"


Lexer::Lexer(void) {
	if (debug_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Lexer's constructor called\n";
}

Lexer::Lexer(Lexer const & cpy) {
	*this = cpy;
}

Lexer::~Lexer(void) {
	if (debug_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Lexer's destructor called\n";
}

Lexer &		Lexer::operator=(Lexer const & ) {
	return *this;
}

// LEXICAL _____________________________________________________________________
void					Lexer::set_lexical(std::vector<std::string> & split) {
	if (split.size() != 2)
		throw BaseException("=> (split) Error detected."); 						//SECU double check
	std::string _p1 = split[0];
	std::string _p2 = split[1];
	int j = 0;
	j = fsm(_p1, j);
	fsm(_p2, j);
}

int					Lexer::fsm(std::string &str, int j) {
	int i = 0;
	int previous_state = 0;
	int current_state = 0;
	while (str[i] != '\0') {
		/* Push new s_scanner in lexical */
		_lexical.push_back(s_scanner());
		_lexical[j].original_line.append(str);
		/* Fill _lexical[..] */
		while (str[i] != '\0') {
			previous_state = current_state;
			current_state = _fsm[previous_state][get_token(str[i])];
			if (current_state == ERROR) {
				if (i == 0)
					i = 1;
				set_error(str[i - 1], str);
				throw BaseException(_error);
			}
			if (current_state != END)
				fill_lexical(j, current_state, str[i]);
			else if (current_state == END)
				break;
			i++;
		}
		j++;
	}
	return j;
}

void					Lexer::fill_lexical(int j, int token, char c) {
	if (token != -1)
		_lexical[j].token = token;
	if (c != '\0')
		_lexical[j].lexeme.push_back(c);
}

std::vector<s_scanner>	& Lexer::get_lexical(void) {
	return _lexical;
}

void					Lexer::debug_print_lexical(void) {
	size_t c = 0;
	std::cout << BLUE << "\n\n\t****** DEBUG LEXICAL ******\n" << NORMAL;
	while (c < _lexical.size())
	{
		std::cout << "\ttoken = " << _tokenVerbose[_lexical[c].token] << std::endl;
		std::cout << "\tlexeme = \"" << _lexical[c].lexeme << "\"\n";
		std::cout << "\toriginal line = \"" << _lexical[c].original_line << "\"\n";
		std::cout << BLUE << "\t___________________________\n" << NORMAL;
		c++;
	}
	std::cout << "\n";
}

void					Lexer::set_error(char c, std::string &str) {
	_error.append("=> (lexer) Error detected after this character '");
	_error.push_back(c);
	_error.append("' from this part '");
	_error.append(str);
	_error.append("'");
}


// GETTER ______________________________________________________________________
int						Lexer::get_token(char c) const{
	if (c >= '0' && c <= '9')
		return INUM;
	else if (c == '.')
		return RNUM;
	else if (c == 'X')
		return XSYMB;
	else if (c == '+')
		return PLUS;
	else if (c == '-')
		return MINUS;
	else if (c == '^')
		return POWER;
	else if (c == '*')
		return MULTI;
	else if (c == '/')
		return DIV;
	else
		return ERROR;
}


// STATIC PUBLIC _______________________________________________________________
const std::string	Lexer::_tokenVerbose[10] = {
	"END", "INUM", "RNUM", "XSYMB", "PLUS", "MINUS", "POWER", "MULTI", "DIV", "ERROR"
};


// STATIC PRIVATE ______________________________________________________________
const int			Lexer::_fsm[10][10]= {
				/* INPUT */
{END,			INUM,	RNUM,	XSYMB,	PLUS,	MINUS,	POWER,	MULTI,	DIV,	ERROR},
/* STATE */
{INUM,			INUM,	RNUM,	ERROR,	END,	END,	END,	END,	END,	ERROR},
{RNUM,			RNUM,	RNUM,	END,	END,	END,	ERROR,	END,	END,	ERROR},
{XSYMB,			ERROR,	ERROR,	ERROR,	END,	END,	END,	END,	ERROR,	ERROR},
{PLUS,			END,	END,	END,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR},
{MINUS,			END,	END,	END,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR},
{POWER,			END,	END,	ERROR,	END,	END,	ERROR,	ERROR,	ERROR,	ERROR},
{MULTI,			END,	END,	END,	END,	END,	ERROR,	ERROR,	ERROR,	ERROR},
{DIV,			END,	END,	ERROR,	END,	END,	ERROR,	ERROR,	ERROR,	ERROR},
{ERROR,			ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR}
};
