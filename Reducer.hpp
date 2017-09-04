/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reducer.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 17:41:13 by aribeiro          #+#    #+#             */
/*   Updated: 2017/09/04 15:58:00 by aribeiro         ###   ########.fr       */
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
		//step1 CALCULATE * ^ RNUM _____________________________________________
		void	calculate_powerNum(void);
		void	calculate_multiNum(void);
		//step2 REDUCE ALL RNUM ________________________________________________
		void	set_allNum(void);
		void	calculate_allNum(void);
		void	debug_print_allNum(void) const;
		//step3 SEARCH X _______________________________________________________
		void	set_Xpow(void);
		void	push_Xpow(size_t c);
		void	debug_print_Xpow(void) const;
		//step4 PRINT REDUCE FORM ______________________________________________
		void	reduceForm(void);
		void	reduce_all(std::vector<long double> &all, int i);
		void	sort_power(void);
		void	clean_Xpow(void);
		void	match_power(size_t c, size_t k);
		void	print_reduceForm(void);
		void	print_XpowMinToMax(bool firstOp);
		bool	print_sign(bool firstOp);

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
