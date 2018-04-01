/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LaunchMissiles.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 00:37:23 by eduwer            #+#    #+#             */
/*   Updated: 2018/04/01 20:02:18 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCHMISSILES_HPP
# define LAUNCHMISSILES_HPP

#include "AObject.hpp"
#include "Missile.hpp"
#include <ncurses.h>
#include <iostream>

class LaunchMissiles : public AObject {

	public:
		LaunchMissiles( int x = 1, int y = 1, int hp = 1, \
			std::string skinString = "^", int objectSize = 1, \
			int objectSpeed = 1, int missileDirectionSpeed = 1);
		LaunchMissiles( LaunchMissiles const &src );
		~LaunchMissiles( void );

		LaunchMissiles	&operator=(LaunchMissiles const &src);

		const Missile	*getMissiles( void ) const;
		int				getNbMissiles( void ) const;
		void			deleteMissile( int index );


	protected:
		void	_newMissile( void );
		void	updateMissiles( void );
		Missile	*_missiles;
		int		_nbMissiles;
		int		_missilesDirectionSpeed;

};

# endif
