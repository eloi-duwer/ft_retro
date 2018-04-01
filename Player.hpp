/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 00:37:23 by eduwer            #+#    #+#             */
/*   Updated: 2018/04/01 18:14:43 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PLAYER_HPP_
# define _PLAYER_HPP_

#include "LaunchMissiles.hpp"
#include "Missile.hpp"
#include <ncurses.h>
#include <iostream>

class Player : public LaunchMissiles {

	public:
		Player( void );
		Player( Player const &src );
		~Player( void );

//		Player	&operator=(Player const &src);

		virtual bool	update( int keyCode );

};

# endif
