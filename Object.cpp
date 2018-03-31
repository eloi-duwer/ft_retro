/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:05:13 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 15:17:57 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"

Object::Object( void ) : _pos{0, 0}, _hp(1) {

	return;

}

Object::Object( int x, int y, int hp) : _pos{x, y}, _hp(hp) {

	return;

}

Object::Object( Object const &src ) : _pos{src._pos[0], src._pos[1]}, _hp(src._hp) {

	return;

}

Object::~Object( void ) {

	return;

}

Object	&Object::operator=(Object const &src) {

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

int		Object::takeDamage( int damage ) {

	this->_hp = max(0, this->_hp - damage);
	return this->_hp;

}

const int		*Object::getPos( void ) const {

	return this->_pos;

}

int		Object::getHp( void ) const {

	return this->_hp;

}
