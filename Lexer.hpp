/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 16:53:30 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 17:38:00 by aribeiro         ###   ########.fr       */
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
	POWER,		// 4 = '^'
	SIGNS,		// 5 = '+' || '-'
	MULTI,		// 6 = '*'
	DIV,		// 7 = '/'
	ERROR,		// 8
};


//
// struct s_scanner {
// 	int			line_nb;
// 	int			token;
// 	std::string	lexeme;
// 	std::string original_line;
// 	bool		error;
// 	int			error_position_lexer;
// };

class Lexer {
	public:
		Lexer(void);
		Lexer(Lexer const & cpy);
		~Lexer(void);
		Lexer & operator=(Lexer const & );

	private:
		static const int 			_fsm[11][11];
};

#endif
