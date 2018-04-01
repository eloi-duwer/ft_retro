/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:23:58 by eduwer            #+#    #+#             */
/*   Updated: 2018/04/01 18:15:46 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ENEMY_
# define _ENEMY_

#include "LaunchMissiles.hpp"
#include <iostream>

class Enemy : public LaunchMissiles {

	public:
		Enemy ( void );
		Enemy( Enemy const &src );
		~Enemy( void );

		virtual bool update(int keycode = 0);

};

# endif
