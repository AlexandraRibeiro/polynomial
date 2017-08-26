/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reducer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:41:13 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/25 20:31:43 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDUCER_H
# define REDUCER_H

# include "BaseException.hpp"
# include "lexer.hpp"


class Reducer {
	public:
		Reducer(void);
		Reducer(Reducer const & cpy);
		~Reducer(void);
		Reducer & operator=(Reducer const & );
		// void	reduce_equation(std::vector<s_scanner> & lexical);

	private:
		// std::vector<long double>					_nb_plus_minus;
		// std::vector<long double>					_multipleX;
		// std::vector<long double>					_powerX;
		// std::vector<long double><long double>		_powerNb;
};


#endif
