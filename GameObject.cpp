/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:28:55 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 20:42:38 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include <ncurses.h>
#include <cstdlib>


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

void	GameObject::newEnemy( void ) {

	Enemy *newEnemy = new Enemy[this->_nbEnemies + 1];
	int i = 0;
	while ( i < this->_nbEnemies) {
		newEnemy[i] = this->_enemies[i];
		++i;
	}
	delete [] this->_enemies;
	this->_enemies = newEnemy;
	this->_nbEnemies += 1;

}

void	GameObject::deleteEnemy(Enemy *adress) {

	Enemy *newEnemy = new Enemy[this->_nbEnemies - 1];
	int	i = 0;
	int	j = 0;
	while ( i < this->_nbEnemies) {
		if (&(this->_enemies[i]) != adress && j < this->_nbEnemies - 1) {
			newEnemy[j] = this->_enemies[i];
			++j;
		}
		++i;
	}
	delete [] this->_enemies;
	this->_enemies = newEnemy;
	this->_nbEnemies -= 1;

}

void	GameObject::deleteEnemy( int index ) {

	Enemy *newEnemy = new Enemy[this->_nbEnemies - 1];
	int	i = 0;
	int	j = 0;
	while ( i < this->_nbEnemies) {
		if (i != index && j < this->_nbEnemies - 1) {
			newEnemy[j] = this->_enemies[i];
			++j;
		}
		++i;
	}
	delete [] this->_enemies;
	this->_enemies = newEnemy;
	this->_nbEnemies -= 1;

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

	int i = 0;
	int j;

	this->_player.update( keyCode );
	while (i < this->_nbEnemies) {
		j = 0;
		while (j < this->_player.getNbMissiles()) {
			if (this->_enemies[i].onCollision(this->_player.getMissiles()[j])) {
				this->deleteEnemy(i);
				this->_player.deleteMissile(j);
				--i;
				break;
			}
			++j;
		}
		this->_enemies[i].update();
		if (this->_enemies[i].onCollision(this->_player)) {
			endwin();
			std::exit(0);
		}
		while (j < this->_player.getNbMissiles()) {
			if (this->_enemies[i].onCollision(this->_player.getMissiles()[j])) {
				this->deleteEnemy(i);
				this->_player.deleteMissile(j);
				--i;
				break;
			}
			++j;
		}
		++i;
	}
}
