/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:05:42 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/28 23:09:55 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

# include "BaseException.hpp"
# include "Lexer.hpp"

class Parser {
	public:
		Parser(void);
		Parser(Parser const & cpy);
		~Parser(void);
		Parser & operator=(Parser const & );
		// PARSING _____________________________________________________________
		void	set_parsing(std::vector<s_scanner> & lexical);
		size_t	set_booleans(int token, int prev_token, size_t c, std::vector<s_scanner> & lexical);
		void	clean_lexical(std::vector<s_scanner> & lexical);


	private:
		bool						_op;
		bool						_nb;
		int							_sign;
		int							_prev_token;

		// std::vector<long double>	_all

};

#endif
