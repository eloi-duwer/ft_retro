/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:23:58 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 15:12:04 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ENEMY_
# define _ENEMY_

#include "Object.hpp"

class Enemy : public Object {

	public:
		Enemy ( void );
		Enemy( Enemy const &src );
		~Enemy( void );

		//Enemy &operator=( Enemy const &src );

		void updateEnemy( void );

};

# endif
