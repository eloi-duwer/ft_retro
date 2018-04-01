/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LaunchMissiles.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:42:05 by eduwer            #+#    #+#             */
/*   Updated: 2018/04/01 18:48:34 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AObject.hpp"
#include "LaunchMissiles.hpp"
#include "Missile.hpp"
#include <ncurses.h>
#include <iostream>


LaunchMissiles::LaunchMissiles( int x, int y, int hp, std::string skinString, \
	int objectSize, int speed, int direction ) : \
AObject(x, y, hp, skinString, objectSize, speed), \
_missiles(NULL), \
_nbMissiles(0), \
_missilesDirectionSpeed(direction) {

	return;

}

LaunchMissiles::LaunchMissiles( LaunchMissiles const &src ) {

	*this = src;
	return;

}

LaunchMissiles::~LaunchMissiles ( void ) {

	delete [] this->_missiles;

}

LaunchMissiles	&LaunchMissiles::operator=(LaunchMissiles const &src ) {

	AObject::operator=( src );
	this->_missilesDirectionSpeed = src._missilesDirectionSpeed;
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

void	LaunchMissiles::_newMissile( void ) {

	Missile *newMissiles = new Missile[this->_nbMissiles + 1];
	int i = 0;
	while ( i < this->_nbMissiles) {
		newMissiles[i] = this->_missiles[i];
		++i;
	}
	newMissiles[i].setPos(this->_pos[0] + this->_objectSize / 2, this->_pos[1] + this->_missilesDirectionSpeed);
	delete [] this->_missiles;
	this->_missiles = newMissiles;
	this->_nbMissiles += 1;

}

void	LaunchMissiles::deleteMissile( int index ) {

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

int		LaunchMissiles::getNbMissiles( void ) const {

	return this->_nbMissiles;

}

const Missile	*LaunchMissiles::getMissiles( void ) const {

	return this->_missiles;

}

void	LaunchMissiles::updateMissiles() {

	int i = 0;
	while ( i < this->_nbMissiles ) {
		if (!this->_missiles[i].update(this->_missilesDirectionSpeed)) {
			deleteMissile(i);
			--i;
		}
		++i;
	}

}
