/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 22:55:25 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/25 23:02:14 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lead.hpp"

void		split(char delim, std::string &str, std::vector<std::string> &split) {
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim))
		split.push_back(token);
}
