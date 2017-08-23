/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <aribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 18:36:24 by aribeiro          #+#    #+#             */
/*   Updated: 2017/08/23 20:33:09 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lead.hpp"

bool	verbose_option = false;


int		main(int ac, char **av)
{
	try {
		Lead lead;
		lead.reader(ac, av);
	}
	catch (BaseException & e){
		std::cout << MAGENTA << "\t" << e.what() << NORMAL << std::endl;
	}
	catch (std::exception & exception) {
		std::cerr << MAGENTA << "\n Some other std::exception occured" << std::endl;
		std::cerr << MAGENTA << "\t" << exception.what() << NORMAL << std::endl;
		return 1;
	}
	return 0;
}
