/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:19:03 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 17:21:40 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "AObject.hpp"
#include "Map.hpp"
#include <ncurses.h>
#include <cstdlib>

Enemy::Enemy( void ) : skin('W'), framesOfExistence(0)
{
	AObject::_pos[0] = (rand () % COLS - 2) + 1;
	AObject::_pos[1] = 1;
	AObject::_hp = 1;
	speed = rand() % 9 + 5;
	// _skinString = "◹🜃◸";
	_skinString = "\\I/";
}

Enemy::~Enemy( void )
{

}

bool Enemy::onCollision(AObject const & aobj)
{
	if ((this->_pos[0] == aobj.getPos()[0] &&
		 this->_pos[1] == aobj.getPos()[1]) ||

		(this->_pos[0] - 1 == aobj.getPos()[0] &&
         this->_pos[1] == aobj.getPos()[1]) ||

		(this->_pos[0] + 1 == aobj.getPos()[0] &&
 		 this->_pos[1] == aobj.getPos()[1]))
		return true;
	return false;
}


bool Enemy::update( int keycode )
{
	keycode++;
	this->framesOfExistence++;
	if (AObject::_pos[1] > LINES - 1)
		return false;
	if (framesOfExistence % speed == 0)
		AObject::_pos[1]++;
	move(AObject::_pos[1], AObject::_pos[0] - 1);
	// addch(this->skin);

	attron(COLOR_PAIR(1));
	addstr(_skinString.c_str());
	attroff(COLOR_PAIR(1));
	return true;
}

