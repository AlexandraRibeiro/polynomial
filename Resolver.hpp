/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Resolver.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:35:46 by aribeiro          #+#    #+#             */
/*   Updated: 2017/09/04 18:33:58 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVER_H
# define RESOLVER_H

# include "BaseException.hpp"
# include "Reducer.hpp"

class Resolver {
	public:
		Resolver(std::vector<s_Xpow> & _Xpow, std::vector<long double> & _allNum, long double ld1);
		Resolver(Resolver const & cpy);
		~Resolver(void);
		Resolver & operator=(Resolver const & );
		// _____________________________________________________________________
		void	tryToResolve(void);
		void	print_degree(void);
		// GETTERS _____________________________________________________________
		std::vector<s_Xpow>			& get_xpow(void) const;
		std::vector<long double>	& get_allNum(void) const;
		long double					get_maxDegree(void) const;
	private:
		std::vector<s_Xpow>				& xpow;
		std::vector<long double>		& allNum;
		long double						_maxDegree;

};

#endif
