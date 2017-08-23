/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lead.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:43:13 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 17:12:06 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEAD_H
# define LEAD_H

# include "Lexer.hpp"

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
	private:
		std::string					_arg;
		std::vector<std::string>	_split;
		Lexer						*_lexer;
};

#endif
