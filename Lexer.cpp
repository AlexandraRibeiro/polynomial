/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 16:53:26 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 18:14:08 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"


Lexer::Lexer(void) {
	if (verbose_option == true)
		std::cout << BLUE << "\t -> " << NORMAL << "Lexer's constructor called" << std::endl;
}

Lexer::Lexer(Lexer const & cpy) {
	*this = cpy;
}

Lexer::~Lexer(void) {
	if (verbose_option == true)
		std::cout << BLUE << "\t\t -> " << NORMAL << "Lexer's destructor called" << std::endl;
}

Lexer &		Lexer::operator=(Lexer const & ) {
	return *this;
}


// STATIC _____________________________________________________________________
const int	Lexer::_fsm[9][9]= {
				/* INPUT */
{END,			INUM,	RNUM,	XSYMB,	POWER,	SIGNS,	MULTI,	DIV,	ERROR},
/* STATE */
{INUM,			INUM,	RNUM,	END,	END,	END,	END,	END,	ERROR},
{RNUM,			RNUM,	RNUM,	END,	ERROR,	END,	END,	END,	ERROR},
{XSYMB,			ERROR,	ERROR,	ERROR,	END,	END,	END,	ERROR,	ERROR},
{POWER,			END,	END,	END,	ERROR,	END,	ERROR,	ERROR,	ERROR},
{SIGNS,			END,	END,	END,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR},
{MULTI,			END,	END,	END,	ERROR,	END,	ERROR,	ERROR,	ERROR},
{DIV,			END,	END,	ERROR,	ERROR,	END,	ERROR,	ERROR,	ERROR},
{ERROR,			ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR,	ERROR}
};
