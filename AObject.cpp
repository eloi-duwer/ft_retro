/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AObject.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:05:13 by eduwer            #+#    #+#             */
/*   Updated: 2018/04/01 17:46:21 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AObject.hpp"
#include <iostream>

AObject::AObject( int x, int y, int hp, std::string skinString, int objectSize, int speed) :
_hp(hp),
_framesOfExistence(0),
_skinString(skinString),
_objectSize(objectSize),
_speed(speed) {

	this->_pos[0] = x;
	this->_pos[1] = y;
	return;

}

AObject::AObject( AObject const &src )
{
	*this = src;
	return;
}

AObject::~AObject( void )
{

	return;

}

bool AObject::onCollision(AObject const & aobj)
{

	if (this->_pos[1] == aobj._pos[1] \
			&& ((this->_pos[0] >= aobj._pos[0] \
				&& this->_pos[0] <= aobj._pos[0] + aobj._objectSize - 1) \
			|| (this->_pos[0] + this->_objectSize - 1 >= aobj._pos[0] \
				&& this->_pos[0] + this->_objectSize - 1 <= aobj._pos[0] + aobj._objectSize - 1) \
			|| ( aobj._pos[0] >= this->_pos[0] \
				&& aobj._pos[0] <= this->_pos[0] + this->_objectSize - 1) \
			|| ( aobj._pos[0] + aobj._objectSize - 1 >= this->_pos[0] \
				&& aobj._pos[0] + aobj._objectSize - 1 <= this->_pos[0] + aobj._objectSize - 1)))
		return true;
	return false;

}

AObject	&AObject::operator=(AObject const &src) {

	this->_pos[0] = src._pos[0];
	this->_pos[1] = src._pos[1];
	this->_hp = src._hp;
	this->_framesOfExistence = src._framesOfExistence;
	this->_skinString = src._skinString;
	this->_objectSize = src._objectSize;
	this->_speed = src._speed;

	return *this;

}

static int max(int a, int b) {

	if (a > b)
		return a;
	return b;

}

int		AObject::takeDamage( int damage ) {

	this->_hp = max(0, this->_hp - damage);
	return this->_hp;

}

const int		*AObject::getPos( void ) const {

	return this->_pos;

}

int		AObject::getHp( void ) const {

	return this->_hp;

}
