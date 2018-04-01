/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:48:30 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 14:41:17 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GAME_OBJECT_HPP_
# define _GAME_OBJECT_HPP_

#include "Enemy.hpp"
#include "Player.hpp"

#define MAX_ENEMIES
class GameObject {

	public:
		GameObject( void );
		GameObject( GameObject const &src );
		~GameObject( void );

		GameObject &operator=(GameObject const &src);

		const Player	&getPlayer( void ) const;
		const Enemy		*getEnemies( void ) const;
		int 			getScore( void );
		int				getNbEnemies( void ) const;
		void			updateGame(int keyCode);
		void 			newEnemy(void);
		Enemy			createEnemy(void);
		void 			deleteEnemy(Enemy *adress);
		void 			deleteEnemy(int index);
	private:
		Player			_player;
		Enemy			*_enemies;
		int				_nbEnemies;
		int				_score;

};

# endif
