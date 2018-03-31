/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:04:12 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 18:09:44 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.hpp"

Missile::Missile( void ) : AObject(0, 0, 1) {

	return;

}

Missile::Missile( Missile const &src ) : AObject(src._pos[0], src._pos[1], src._hp) {

	return;

}

Missile::~Missile( void ) {

	return;

}

void	Missile::update( void ) {

	this->_pos[1] -= 1;

}

void	Missile::setPos(int x, int y) {

	this->_pos[0] = x;
	this->_pos[1] = y;

}
