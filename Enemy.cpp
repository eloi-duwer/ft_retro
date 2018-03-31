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

Enemy::Enemy( void ) : skin('V'), framesOfExistence(0)
{
	AObject::_pos[0] = rand () % COLS;
	AObject::_pos[1] = 1;
	AObject::_hp = 1;
}

Enemy::~Enemy( void )
{

}

void Enemy::update( int keycode )
{
	keycode++;
	this->framesOfExistence++;
	if (framesOfExistence % 2 == 0)
		AObject::_pos[1]++;
	move(AObject::_pos[1], AObject::_pos[0]);
	addch(this->skin);
}

