/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseException.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:39:05 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/17 18:39:13 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseException.hpp"

BaseException::BaseException(void){}

BaseException::~BaseException(void) throw () {} 		//inherited from std::exception

BaseException::BaseException(std::string const & message) : std::exception(), _msg(message){}

BaseException::BaseException(BaseException const & cpy) {
	*this = cpy;
}

BaseException & BaseException::operator=(BaseException const &) {
	return *this;
}

const char * BaseException::what(void) const throw () { //inherited from std::exception
	return this->_msg.c_str();
}
