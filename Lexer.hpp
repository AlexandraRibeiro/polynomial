/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 16:53:30 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/28 16:43:44 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "BaseException.hpp"

enum tokens {
	END = 0,
	INUM, 		// 1 = Integer
	RNUM,		// 2 = '.' Real (ex: 3.8)
	XSYMB,		// 3 = 'X'
	PLUS,		// 4 = '+'
	MINUS,		// 5 = '-'
	POWER,		// 6 = '^'
	MULTI,		// 7 = '*'
	DIV,		// 8 = '/'
	ERROR,		// 9
};

struct s_scanner {
	int			token;
	std::string	lexeme;
	std::string original_line;
	long double	ld;
};

class Lexer {
	public:
		Lexer(void);
		Lexer(Lexer const & cpy);
		~Lexer(void);
		Lexer & operator=(Lexer const & );
		//LEXICAL ______________________________________________
		void						set_lexical(std::vector<std::string> & split);
		int							fsm(std::string &str, int j);
		void						fill_lexical(int j, int token, char c);
		std::vector<s_scanner>		& get_lexical(void);
		void						debug_print_lexical(void);
		void						set_error(char c, std::string &str);
		//GETTER _______________________________________________
		int							get_token(char c) const;
		static const std::string	_tokenVerbose[10];
	private:
		std::vector<s_scanner>		_lexical;
		std::string					_error;
		static const int 			_fsm[10][10];
};

#endif
