/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:19:03 by eduwer            #+#    #+#             */
/*   Updated: 2018/04/01 19:25:55 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "AObject.hpp"
#include "Map.hpp"
#include <ncurses.h>
#include <cstdlib>

Enemy::Enemy( void ) : LaunchMissiles((rand() % COLS - 2) + 10, 1, 1, "\\I/", 3, rand() % 9 + 5, 4)
{

	return;

}

Enemy::~Enemy( void )
{

	return;

}

bool Enemy::update( int keycode )
{
	keycode++;
	this->_framesOfExistence++;
	if (this->_framesOfExistence % 120 == 0)
		_newMissile();
	if (AObject::_pos[1] > LINES - 2)
		return false;

	if (_framesOfExistence % _speed == 0)
		AObject::_pos[1]++;
	move(AObject::_pos[1], AObject::_pos[0]);
	attron(COLOR_PAIR(_speed % 6));
	addstr(_skinString.c_str());
	attroff(COLOR_PAIR(_speed % 6));
	updateMissiles();
	return true;
}
