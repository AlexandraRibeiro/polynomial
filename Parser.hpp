/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:05:42 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/25 22:11:11 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

# include "BaseException.hpp"
# include "Lexer.hpp"

struct s_opMultiplications {
	long double		val1; 	// 1 if [val1]^ || 2 if [val2]^
	bool			x1;
	long double		powval1;
	long double		val2;
	bool			x2;
	long double		powval2;
};

struct s_numbers {
	long double		val; 	//-5 || 4.2 || 4
	bool			x;		// true if +X or -X
};



class Parser {
	public:
		Parser(void);
		Parser(Parser const & cpy);
		~Parser(void);
		Parser & operator=(Parser const & );
		// PARSING 1 ___________________________________________________________
		void	set_parsing(std::vector<s_scanner> & lexical);
		size_t	set_booleans(int token, size_t c, std::vector<s_scanner> & lexical);
		// PARSING 2 ___________________________________________________________
		// void	set_operands();
		// void	set_errorParser(std::string opOrnb, std::string &str);

	private:
		bool					_op;
		bool					_nb;
		int						_sign;
		// std::vector<s_operands>	_operands;

};

#endif
