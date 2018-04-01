/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:42:05 by eduwer            #+#    #+#             */
/*   Updated: 2018/04/01 20:07:51 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AObject.hpp"
#include "Player.hpp"
#include "Missile.hpp"
#include <ncurses.h>
#include <iostream>


Player::Player( void ) : LaunchMissiles(COLS / 2, LINES - 2, 3, "/o\\-o-\\o/", 3, 1, -1)
{

	return;

}

Player::Player( Player const &src ) {

	*this = src;
	return;

}

Player::~Player ( void ) {

	return;

}

bool	Player::update( int keyCode ) {

	if (keyCode == KEY_LEFT && this->_pos[0] > 0)
		this->_pos[0] -= 1;
	if (keyCode == KEY_RIGHT && this->_pos[0] + this->_objectSize - 1 < COLS - 1)
		this->_pos[0] += 1;
	if (keyCode == ' ')
		Player::_newMissile();

	move(this->_pos[1], this->_pos[0]);

	attron(COLOR_PAIR(this->_hp));
	int timelapse = (_framesOfExistence++ % 45) / 15;
		addstr(this->_skinString.substr(timelapse * 3, this->_objectSize).c_str());
	attroff(COLOR_PAIR(this->_hp));
	updateMissiles();
	return true;
}
