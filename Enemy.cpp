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
	AObject::_pos[0] = rand () % COLS;
	AObject::_pos[1] = 1;
	AObject::_hp = 1;
}

Enemy::~Enemy( void )
{

}

bool Enemy::update( int keycode )
{
	keycode++;
	this->framesOfExistence++;
	if (AObject::_pos[1] > LINES - 1)
		return false;
	if (framesOfExistence % 2 == 0)
		AObject::_pos[1]++;
	move(AObject::_pos[1], AObject::_pos[0]);
	addch(this->skin);
	return true;
}

