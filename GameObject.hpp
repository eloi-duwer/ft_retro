/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:48:30 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 01:40:59 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GAME_OBJECT_HPP_
# define _GAME_OBJECT_HPP_

#include "Enemy.hpp"
#include "Player.hpp"

#define HEIGHMAP_SIZE 400
#define MAX_ENEMIES
class GameObject {

	public:
		GameObject( void );
		GameObject( GameObject const &src );
		~GameObject( void );
		void	updateGame(int keyCode);
		void	updateScreen( void );

		GameObject &operator=(GameObject const &src);

		const int		*getHeighMap( void ) const;
		const Player	&getPlayer( void ) const;
		const Enemy		*getEnemies( void ) const;
		static int		getTick( void ) const;

	private:
		int			*_heighMap; //Hauteur du sol pour chaque colonne
		Player		_player;
		Enemy		*_enemies;

};

# endif
