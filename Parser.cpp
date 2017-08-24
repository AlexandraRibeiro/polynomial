/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:05:34 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/24 18:35:38 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser(void) {
	if (verbose_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Parser's constructor called\n";
}

Parser::Parser(Parser const & cpy) {
	*this = cpy;
}

Parser::~Parser(void) {
	if (verbose_option == true)
		std::cout << BLUE << "\t-> " << NORMAL << "Parser's destructor called\n";
}

Parser &	Parser::operator=(Parser const & ) {
	return *this;
}

void		Parser::set_parsing(std::vector<s_scanner> & lexical) {
	size_t c = 0;
	int j = 0;
	while (c < lexical.size())
	{
		_parsing.push_back(s_scanner2());
		_parsing[j].original_line.append(lexical[c].original_line);
		while (c < lexical.size()) {
			if (c == 0 && (lexical[c].token == MINUS || lexical[c].token == PLUS)) {
				fill_parsing(j, -1, lexical[c].lexeme);
			}
			c++;
		}
		j++;
	}

}

void		Parser::fill_parsing(int j, int token, std::string str) {
	if (token != -1)
		_parsing[j].token = token;
	if (str.compare("") == false)
		_parsing[j].strValue.append(str);
}
