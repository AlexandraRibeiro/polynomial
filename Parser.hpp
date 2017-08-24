/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:05:42 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/24 20:37:50 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

# include "BaseException.hpp"
# include "Lexer.hpp"


enum tokensParser {
	CONTINUE,	// 10 for X^..
	SIGN		// 11 for exemple *-3 sign not an operand
}

// struct s_scanner2 {
// 	int				token;
// 	std::string		strValue;
// 	long double		iValue;
// 	std::string		original_line;
// };


class Parser {
	public:
		Parser(void);
		Parser(Parser const & cpy);
		~Parser(void);
		Parser & operator=(Parser const & );
		void	set_parsing(std::vector<s_scanner> & lexical);
		void	fill_parsing(int j, int token, std::string str);

	private:
		std::vector<long double>		_operands;
		std::vector<long double>		_values;

};

#endif