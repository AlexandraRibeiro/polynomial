/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:05:42 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/25 17:40:39 by aribeiro         ###   ########.fr       */
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
		size_t	set_booleans(int token, size_t c, std::vector<s_scanner> & lexical);
		// void	set_errorParser(std::string opOrnb, std::string &str);

	private:
		bool		_op;
		bool		_nb;
		int			_sign;
		// std::string	_errorParser;

};

#endif
