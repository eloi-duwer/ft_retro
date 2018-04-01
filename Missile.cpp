/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:04:12 by eduwer            #+#    #+#             */
/*   Updated: 2018/04/01 18:47:34 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.hpp"

Missile::Missile( void ) : AObject(0, 0, 1, "|", 1, 1) {

	return;

}

Missile::Missile( Missile const &src ) {

	*this = src;
	return;

}

Missile::~Missile( void ) {

	return;

}

bool	Missile::update( int directionSpeed ) {

	++_framesOfExistence;
	if ((directionSpeed < 0 && this->_pos[1] < 1) || (directionSpeed > 0 && this->_pos[1] > LINES - 1))
		return false;
	if (_framesOfExistence % directionSpeed == 0)
		this->_pos[1] += directionSpeed > 0 ? 1 : -1;
	move(this->_pos[1], this->_pos[0]);
	addch(this->_skinString.c_str()[0]);
	return true;
}

void	Missile::setPos(int x, int y) {

	this->_pos[0] = x;
	this->_pos[1] = y;

}
