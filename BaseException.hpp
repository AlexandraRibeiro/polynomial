/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseException.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:39:33 by aribeiro          #+#    #+#             */
/*   Updated: 2017/09/03 15:42:08 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASEEXCEPTION_H
# define BASEEXCEPTION_H

# include <iostream>
# include <string>
# include <iomanip>
# include <algorithm>
# include <sstream>
# include <iterator>
# include <regex>


# define YELLOW		"\033[33;1m"
# define BLUE		"\033[34;1m"
# define MAGENTA	"\033[35;1m"
# define GREEN		"\033[32;1m"
# define NORMAL		"\033[0m"

//precision long double -> stringToLong
# define LDB_PRECIS	std::numeric_limits<long double>::digits10

void			split(char delim, std::string &str, std::vector<std::string> &split);
long double		stringToLong(std::string & str);
std::string		longToString(long double ld);

extern bool		verbose_option;
extern bool		debug_option;

class BaseException : public std::exception {
	public:
		BaseException(void);
		~BaseException(void) throw (); 			// virtual
		BaseException(std::string const & message);
		BaseException(BaseException const &);
		BaseException & operator=(BaseException const &);
		const char *what(void) const throw (); //virtual
	private:
		std::string		_msg;
};


#endif
