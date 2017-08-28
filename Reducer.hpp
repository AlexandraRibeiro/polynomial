/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reducer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:41:13 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/29 01:19:23 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDUCER_H
# define REDUCER_H

# include "BaseException.hpp"
# include "Lexer.hpp"


struct s_Xpower {
	long double					power;
	std::vector<long double> 	allCoeff;
	int							sign;
};

class Reducer {
	public:
		Reducer(std::vector<s_scanner> & lex);
		Reducer(Reducer const & cpy);
		~Reducer(void);
		Reducer & operator=(Reducer const & );
		// CALCULATE NUM _______________________________________________________
		void	calculate_powerNum(void);
		void	calculate_multiNum(void);
		void	set_allNum(void);
		void	calculate_allNum(void);
		void	debug_print_allNum(void) const;
		// X POWER _____________________________________________________________
		void	search_powerX();
		void	push_Xpower(long double power, size_t c, int j)
		// GETTER ______________________________________________________________
		std::vector<s_scanner>	& get_lexical(void) const;

	private:
		std::vector<long double>		_allNum;
		int								_sign;
		long double						_ld1;
		long double						_ld2;
		std::vector<s_Xpower>			_Xpow;
		std::vector<s_scanner>			&lexical;
};


#endif
