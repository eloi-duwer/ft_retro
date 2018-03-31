/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 00:37:23 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 20:22:40 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PLAYER_HPP_
# define _PLAYER_HPP_

#include "AObject.hpp"
#include "Missile.hpp"
#include <ncurses.h>

class Player : public AObject {

	public:
		Player( void );
		Player( Player const &src );
		~Player( void );

		const Missile	*getMissiles( void ) const;
		int				getNbMissiles( void ) const;
		void			deleteMissile( Missile *adress );
		void			deleteMissile( int index );
		virtual bool	update( int keyCode );

	private:
		void	_newMissile( void );
		Missile	*_missiles;
		int		_nbMissiles;
		char _skin;

};

# endif
