/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 22:55:25 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/28 23:08:11 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lead.hpp"

void			split(char delim, std::string &str, std::vector<std::string> &split) {
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim))
		split.push_back(token);
}

long double		stringToLong(std::string & str) {
	std::stringstream ss(str);
	long double result ;
	return ss >> result ? result : throw BaseException("=> (reducer) Error wrong value -> stringToLong.");
}

std::string longToString(long double ld) {
	std::ostringstream oss;
	oss << std::setprecision(DB_PRECIS) << ld;
	if (oss.str().compare("inf") == 0 || oss.str().compare("-inf") == 0)
	 	throw BaseException("=> (reducer) Error one value is too high, detected by longToString().");
	return oss.str();
}
