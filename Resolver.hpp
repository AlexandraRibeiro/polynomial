/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Resolver.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:35:46 by aribeiro          #+#    #+#             */
/*   Updated: 2017/09/05 00:56:52 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLVER_H
# define RESOLVER_H

# include "BaseException.hpp"
# include "Reducer.hpp"

class Resolver {
	public:
		Resolver(std::vector<s_Xpow> & _Xpow, long double ld1);
		Resolver(Resolver const & cpy);
		~Resolver(void);
		Resolver & operator=(Resolver const & );
		// _____________________________________________________________________
		void	tryToResolve(void);
		void	print_degree(void);
		// DEGREE 1 ____________________________________________________________
		void	resolve_1degree(void);
		// DEGREE 2 ____________________________________________________________
		void	discriminant(void);
		void	deltaZero(void);
		void	deltaPositif(void);
		void	deltaNeg(void);
		long double	heronMethod(void);
		// OTHERS ______________________________________________________________
		void	resolve_others(void);
		// GETTERS _____________________________________________________________
		std::vector<s_Xpow>			& get_xpow(void) const;
		long double					get_maxDegree(void) const;
	private:
		std::vector<s_Xpow>		& xpow;
		long double				_maxDegree;
		long double				_delta;
		long double				_a;
		long double				_b;
		long double				_c;

};

#endif
