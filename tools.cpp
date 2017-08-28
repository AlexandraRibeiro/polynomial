/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 22:55:25 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/28 17:36:45 by aribeiro         ###   ########.fr       */
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
	return ss >> result ? result : throw BaseException("=> (parser) Error wrong value -> stringToLong.");
}

std::string numToString(long double ld) {
	std::ostringstream oss;
	return oss << std::setprecision(DB_PRECIS) << ld ? oss.str() : throw BaseException("=> (parser) Error wrong value -> numToString.");
}
