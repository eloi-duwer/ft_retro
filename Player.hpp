/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 00:37:23 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 17:18:24 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PLAYER_HPP_
# define _PLAYER_HPP_

#include "AObject.hpp"
#include "Missile.hpp"

class Player : public AObject {

	public:
		Player( void );
		Player( Player const &src );
		~Player( void );

		//Player    &operator=( Player const &src );
		virtual void	update( int keyCode );
		const Missile	*getMissiles( void ) const;
		void			deleteMissile( Missile *adress );
		void			deleteMissile( int index );

		private:
			void	newMissile( void );
			Missile	*missiles;
			int		nbMissiles;
};

# endif
