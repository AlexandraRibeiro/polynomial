/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:05:42 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/26 19:52:28 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

# include "BaseException.hpp"
# include "Lexer.hpp"

struct s_numbers {
	int				sign; 	//case 3 = X... -> 3 -X = 0
	long double		val; 	// -5 || 4.2 || 4
	bool			x;		// true if +X or -X
	long double		powval; // if + X^5 or -3^2
};

struct s_multi {
	s_numbers		& nb1;
	s_numbers		& nb2;
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
		void	fill_vectors();
		void	set_multi(int n, size_t c, std::vector<s_scanner> & lexical);
		void	set_numbers(int n, std::string &str);
		std::vector<s_numbers>	& Parser::get_numbers(void);
		std::vector<s_multi>	& Parser::get_multi(void);

	private:
		bool					_op;
		bool					_nb;
		int						_sign;
		int						_prev_token;
		std::vector<s_multi>	_multi;
		std::vector<s_numbers>	_numbers;

};

#endif
