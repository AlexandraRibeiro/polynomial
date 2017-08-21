/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lead.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:43:13 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/21 18:24:20 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEAD_H
# define LEAD_H

# include "BaseException.hpp"

extern bool		verbose_option;

class Lead {

	public:
		Lead(void);
		Lead(Lead const & cpy);
		~Lead();
		Lead	&	operator=(Lead const &); //ajouter rhs ?
		void		reader(int ac, char **av);
	private:
		std::string _arg;

};

#endif
