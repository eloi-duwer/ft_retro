/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:42:05 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 18:49:54 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AObject.hpp"
#include "Player.hpp"
#include "Missile.hpp"
#include <ncurses.h>

Player::Player( void ) : AObject(COLS / 2, LINES - 2, 1) {

	return;

}

Player::Player( Player const &src ) : AObject(src._pos[0], src._pos[1], src._hp), _skin('H') {

	return;

}

Player::~Player ( void ) {

	delete [] this->_missiles;

}

bool	Player::update( int keyCode ) {

	/*if (keyCode == KEY_DOWN)
		this->_pos[1] += 1;
	else if (keyCode == KEY_UP)
		this->_pos[1] -= 1;
	else */

	if (keyCode == KEY_LEFT && this->_pos[0] > 0)
		this->_pos[0] -= 1;
	else if (keyCode == KEY_RIGHT && this->_pos[0] < COLS - 1)
		this->_pos[0] += 1;
	else if (keyCode == ' ')
		Player::_newMissile();

	move(this->_pos[1], this->_pos[0]);
	addch(_skin);
	int i = 0;
	while (i < this->_nbMissiles) {
		if (!this->_missiles[i].update())
		{
			deleteMissile(i);
			--i;
		}
		++i;
	}
	return true;
}

void	Player::_newMissile( void ) {

	Missile *newMissiles = new Missile[this->_nbMissiles + 1];
	int i = 0;
	while ( i < this->_nbMissiles) {
		newMissiles[i] = this->_missiles[i];
		++i;
	}
	newMissiles[i].setPos(this->_pos[0], this->_pos[1]);
	delete [] this->_missiles;
	this->_missiles = newMissiles;
	this->_nbMissiles += 1;

}

void	Player::deleteMissile(Missile *adress) {

	Missile *newmissiles = new Missile[this->_nbMissiles - 1];
	int	i = 0;
	int	j = 0;
	while ( i < this->_nbMissiles) {
		if (&(this->_missiles[i]) != adress && j < this->_nbMissiles - 1) {
			newmissiles[j] = this->_missiles[i];
			++j;
		}
		++i;
	}
	delete [] this->_missiles;
	this->_missiles = newmissiles;
	this->_nbMissiles -= 1;

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
