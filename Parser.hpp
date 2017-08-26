/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:05:42 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 22:15:17 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

# include "BaseException.hpp"
# include "Lexer.hpp"

struct	s_operands {
	long double		ld1;
	long double		ld2;
	std::string		s1;			// if X
	std::string		s2;			// if X
};

class Parser {
	public:
		Parser(void);
		Parser(Parser const & cpy);
		~Parser(void);
		Parser & operator=(Parser const & );
		// PARSING _____________________________________________________________
		void	set_parsing(std::vector<s_scanner> & lexical);
		size_t	set_booleans(int token, int prev_token, size_t c, std::vector<s_scanner> & lexical);
		void	delete_plus_minus(std::vector<s_scanner> & lexical);
		// OPERANDS ____________________________________________________________
		void	fill_operands(std::vector<s_scanner> & lexical);
		void	init_operands(std::vector<s_scanner> & lexical);
		void	debug_print_operands(void);

	private:
		bool					_op;
		bool					_nb;
		int						_sign;
		int						_prev_token;
		std::vector<s_operands>	_operands;
		// std::vector<s_multi>	_multi;
		// std::vector<s_numbers>	_numbers;

};

#endif
