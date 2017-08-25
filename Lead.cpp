/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lead.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:43:11 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/25 17:25:31 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lead.hpp"

Lead::Lead(void) : _arg("-v"), _lexer(NULL), _parser(NULL) {
	if (verbose_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Lead's constructor called\n";
}

Lead::Lead(Lead const & cpy) : _arg("-v"), _lexer(NULL), _parser(NULL) {
	if (verbose_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Lead's copy constructor called\n";
	*this = cpy;
}

Lead::~Lead(void) {
	if (_lexer != NULL)
		delete(_lexer);
	if (_parser != NULL)
		delete(_parser);
	if (verbose_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Lead's destructor called\n";
}

Lead	&	Lead::operator=(Lead const & ) {return *this; }



// READER_______________________________________________________________________
void		Lead::reader(int ac, char **av) {
	if (ac == 3 && _arg.compare(av[1]) == 0) {
		verbose_option = true;
		_arg = av[2];
	}
	else if (ac == 3 && _arg.compare(av[2]) == 0) {
		verbose_option = true;
		_arg = av[1];
	}
	else if (ac == 2) {
		_arg = av[1];
	}
	else if (ac > 2) {
		throw BaseException("=> Error too many arguments.");
	}
	else {
		std::string msg;
		msg.append(NORMAL);
		msg.append("\n\tUSAGE\n\t------------\n\t");
		msg.append("This program takes an argument in parameter,\n\ta polynomial equation.");
		msg.append("\n\tex: 5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0\n\n\t");
		msg.append("-v : verbose\n");
		throw BaseException(msg);
	}
	regex();
}


void		Lead::regex(void) {
	std::regex regexValidChars("[0-9X+\\-\\^\\*\\.\\/]+[=]{1}[0-9X+\\-\\^\\*\\.\\/]+");
	std::regex regexStart("^[0-9\\-+\\.]");
	std::regex regexEnd("[0-9\\.]$");

	if (_arg.compare("") == 0)
		throw BaseException("=> Error empty string.");
	_arg.erase(std::remove (_arg.begin(), _arg.end(), ' '), _arg.end()); 		//remove spaces

	std::transform(_arg.begin(), _arg.end(),_arg.begin(), ::toupper);			//toUpper x -> X (bonus)

	if (std::regex_match(_arg, regexValidChars) == false)						//check valid chars
		throw BaseException("=> (regex) Error detected.");

	split('=');

	if (std::regex_search(_split[0], regexStart) == false)
		throw BaseException("=> (regex) Error detected in the part to the left of the sign '='.");
	if (std::regex_search(_split[1], regexStart) == false)
		throw BaseException("=> (regex) Error detected in the part to the right of the sign '='.");
	if (std::regex_search(_split[0], regexEnd) == false)
		throw BaseException("=> (regex) Error detected in the part to the left of the sign '='.");
	if (std::regex_search(_split[1], regexEnd) == false)				
		throw BaseException("=> (regex) Error detected in the part to the right of the sign '='.");

	runLexer();
}

void		Lead::split(char delim) {
	std::stringstream ss(_arg);
	std::string token;
	while (std::getline(ss, token, delim))
		_split.push_back(token);
}

void		Lead::runLexer(void) {
	_lexer = new Lexer();
	_lexer->set_lexical(_split);

	runParser();
}

void		Lead::runParser(void) {
	_parser = new Parser();
	_parser->set_parsing(_lexer->get_lexical());

	_lexer->debug_print_lexical();
}
