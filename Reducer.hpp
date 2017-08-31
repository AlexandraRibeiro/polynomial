/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reducer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:41:13 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/31 17:05:28 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDUCER_H
# define REDUCER_H

# include "BaseException.hpp"
# include "Lexer.hpp"


struct s_Xpow {
	std::vector<long double>	allPower;
	std::vector<long double> 	allCoeff;
	int							sign;
};

class Reducer {
	public:
		Reducer(std::vector<s_scanner> & lex);
		Reducer(Reducer const & cpy);
		~Reducer(void);
		Reducer & operator=(Reducer const & );
		// step1 CALCULATE * ^ RNUM ____________________________________________
		void	calculate_powerNum(void);
		void	calculate_multiNum(void);
		//step2 SEARCH X _______________________________________________________
		void	set_Xpow(void);
		void	push_Xpow(size_t c);
		void	debug_print_Xpow(void) const;
		//step3 REDUCE ALL RNUM ________________________________________________
		void	set_allNum(void);
		void	calculate_allNum(void);
		void	debug_print_allNum(void) const;
		//step4 PRINT REDUCE FORM ______________________________________________
		void	reduceAll(void);
		void	reduce_allCoeff(size_t c);
		// void	sort_power(void);

		// GETTER ______________________________________________________________
		std::vector<s_scanner>	& get_lexical(void) const;

	private:
		int								_sign;
		int								_j;
		long double						_ld1;
		long double						_ld2;
		std::vector<s_Xpow>				_Xpow;
		std::vector<long double>		_allNum;
		std::vector<s_scanner>			&lexical;
};


#endif
