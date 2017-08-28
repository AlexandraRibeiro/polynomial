/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reducer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:41:13 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/28 23:42:17 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDUCER_H
# define REDUCER_H

# include "BaseException.hpp"
# include "Lexer.hpp"


class Reducer {
	public:
		Reducer(void);
		Reducer(Reducer const & cpy);
		~Reducer(void);
		Reducer & operator=(Reducer const & );
		// CALCULATE NUM _______________________________________________________
		void	calculate_powerNum(std::vector<s_scanner> & lexical);
		void	calculate_multiNum(std::vector<s_scanner> & lexical);
		void	set_allNum(std::vector<s_scanner> & lexical);
		void	calculate_allNum(void);
		void	debug_print_allNum(void) const;

	private:
		std::vector<long double>	_allNum;
		int							_sign;
		long double					_ld1;
		long double					_ld2;
};


#endif
