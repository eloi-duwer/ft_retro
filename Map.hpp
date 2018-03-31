/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp           		                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 00:22:21 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 00:38:42 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_HPP_
# define _MAP_HPP_

#include <iostream>
#include <ncurses.h>
#include <sstream>

class Map {

	public:
		Map( void );
		// Map( Map &src);
		~Map( void );
		
		std::string getOutput(void);

		int height;
		int width;


		// Map &operator=(Map const &src);

};
std::ostream &	operator<<(std::ostream & o, Map const & i);

#endif
