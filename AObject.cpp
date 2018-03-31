/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AObject.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:05:13 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 15:17:57 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AObject.hpp"
#include <iostream>

AObject::AObject( void )
{

	return;

}

AObject::AObject( int x, int y, int hp)
{
	std::cout << x << y << hp;
	return;
}

AObject::AObject( AObject const &src )
{
	*this  = src;
	return;
}

AObject::~AObject( void ) 
{

	return;

}

bool AObject::onCollision(AObject const & aobj)
{
	if (this->_pos[0] == aobj.getPos()[0] &&
		this->_pos[1] == aobj.getPos()[1])
		return true;
	return false;
}

AObject	&AObject::operator=(AObject const &src) {

	this->_pos[0] = src._pos[0];
	this->_pos[1] = src._pos[1];
	this->_hp = src._hp;
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
