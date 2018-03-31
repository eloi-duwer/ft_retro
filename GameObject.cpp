/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:28:55 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 14:41:43 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include <ncurses.h>


GameObject::GameObject( void ) : _player(), _enemies(NULL), _nbEnemies(0) {

	return;

}

GameObject::GameObject( GameObject const &src) :
_player(src._player),
_enemies(src._enemies),
_nbEnemies(src._nbEnemies) {

	return;

}

GameObject::~GameObject( void ) {

	delete[] this->_enemies;
	return;

}

GameObject	&GameObject::operator=(GameObject const &src) {

	this->_player = src._player;
	this->_enemies = src._enemies;
	this->_nbEnemies = src._nbEnemies;
	return *this;

}

const Player &GameObject::getPlayer( void ) const {

	return this->_player;

}

const Enemy *GameObject::getEnemies( void ) const {

	return this->_enemies;

}

int		GameObject::getNbEnemies( void ) const {

	return this->_nbEnemies;

}

void	GameObject::updateGame( int keyCode ) {

	this->_player.updatePlayer( keyCode );
	int i = 0;
	while (i < this->_nbEnemies) {
		this->_enemies[i].updateEnemy();
		++i;
	}

}
