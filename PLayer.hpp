/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 00:37:23 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 16:24:00 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PLAYER_HPP_
# define _PLAYER_HPP_

#include "Object.hpp"
#include "Missile.hpp"

class Player : public Object {

	public:
		Player( void );
		Player( Player const &src );
		~Player( void );

		//Player	&operator=( Player const &src );

		void			updatePlayer( int keyCode );
		const Missile	*getMissiles( void ) const;
		void	deleteMissile( Missile *adress );
		void	deleteMissile( int index );

	private:
		void	newMissile( void );
		Missile	*missiles;
		int		nbMissiles;
};

# endif
