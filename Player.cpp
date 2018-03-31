/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:42:05 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 15:25:09 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"
#include "Player.hpp"
#include "Missile.hpp"
#include <ncurses.h>

Player::Player( void ) : Object(COLS / 2, LINES - 2, 1) {

	return;

}

Player::Player( Player const &src ) : Object(src._pos[0], src._pos[1], src._hp) {

	return;

}

Player::~Player ( void ) {

	return;

}

void	Player::updatePlayer( int keyCode ) {

	/*if (keyCode == KEY_DOWN)
		this->_pos[1] += 1;
	else if (keyCode == KEY_UP)
		this->_pos[1] -= 1;
	else */if (keyCode == KEY_LEFT)
		this->_pos[0] -= 1;
	else if (keyCode == KEY_RIGHT)
		this->_pos[0] += 1;
	else if (keyCode == ' ')
		Player::newMissile();

	int i = 0;
	while (i < this->_nbMissiles) {
		this->_missiles[i].updateMissile( void );
		++i;
	}
}
