/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PLayer.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 00:37:23 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 01:29:50 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PLAYER_HPP_
# define _PLAYER_HPP_

#include "Object.hpp"

class Player : Object {

	public:
		Player( void );
		Player( Player const &src );
		~Player( void );

		Player	&operator=( Player const &src );


	private:
		int		_reloadTime;
};

# endif
