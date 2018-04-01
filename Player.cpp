/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:42:05 by eduwer            #+#    #+#             */
/*   Updated: 2018/04/01 18:22:58 by eduwer           ###   ########.fr       */
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
/*
Player	&Player::operator=(Player const &src ) {

	AObject::operator=( src );
	this->_nbMissiles = src._nbMissiles;
	if (this->_nbMissiles > 0) {
		this->_missiles = new Missile[this->_nbMissiles];
		int i = 0;
		while ( i < this->_nbMissiles ) {
			this->_missiles[i] = src._missiles[i];
			++i;
		}
	}
	return *this;
}
*/
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
/*
void	Player::_newMissile( void ) {

	Missile *newMissiles = new Missile[this->_nbMissiles + 1];
	int i = 0;
	while ( i < this->_nbMissiles) {
		newMissiles[i] = this->_missiles[i];
		++i;
	}
	newMissiles[i].setPos(this->_pos[0] + this->_objectSize / 2, this->_pos[1] - 1);
	delete [] this->_missiles;
	this->_missiles = newMissiles;
	this->_nbMissiles += 1;

}

void	Player::deleteMissile( int index ) {

	Missile *newmissiles = new Missile[this->_nbMissiles - 1];
	int	i = 0;
	int	j = 0;
	while ( i < this->_nbMissiles) {
		if (i != index && j < this->_nbMissiles - 1) {
			newmissiles[j] = this->_missiles[i];
			++j;
		}
		++i;
	}
	delete [] this->_missiles;
	this->_missiles = newmissiles;
	this->_nbMissiles -= 1;

}

int		Player::getNbMissiles( void ) const {

	return this->_nbMissiles;

}

const Missile	*Player::getMissiles( void ) const {

	return this->_missiles;

}*/
