/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lead.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:43:13 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/25 17:41:28 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEAD_H
# define LEAD_H

# include "Lexer.hpp"
# include "Parser.hpp"

class Lead {

	public:
		Lead(void);
		Lead(Lead const & cpy);
		~Lead();
		Lead	&	operator=(Lead const &); //ajouter rhs ?
		void		reader(int ac, char **av);
		void		regex(void);
		void		split(char delim);
		void		runLexer(void);
		void		runParser(void);
		void		runReducer(void);

	private:
		std::string					_arg;
		std::vector<std::string>	_split;
		Lexer						*_lexer;
		Parser						*_parser;
};

#endif
