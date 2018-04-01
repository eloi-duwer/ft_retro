/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:28:55 by eduwer            #+#    #+#             */
/*   Updated: 2018/04/01 19:45:26 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include <ncurses.h>
#include <cstdlib>


GameObject::GameObject( void ) : _player(), _enemies(NULL), _nbEnemies(0), _score(0) {

	return;

}

GameObject::GameObject( GameObject const &src) {

	*this = src;
	return;

}

GameObject::~GameObject( void ) {

	delete[] this->_enemies;
	return;

}

GameObject	&GameObject::operator=(GameObject const &src) {

	if (this->_enemies != NULL)
		delete[] this->_enemies;
	this->_player = src._player;
	this->_nbEnemies = src._nbEnemies;
	this->_enemies = new Enemy[src._nbEnemies];
	int i = 0;
	while (i < this->_nbEnemies) {
		this->_enemies[i] = src._enemies[i];
		++i;
	}
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

int 	GameObject::getScore(void) 
{
	return (this->_score);
}

int		GameObject::getNbEnemies( void ) const {

	return this->_nbEnemies;

}

bool	GameObject::updateGame( int keyCode ) {

	int i = 0;
	int j;

	this->_player.update( keyCode );
	while (i < this->_nbEnemies) {
		j = 0;
		this->_enemies[i].update();
		if (this->_enemies[i].onCollision(this->_player)) { //Collision ennemy/player
			this->deleteEnemy(i);
			if (this->_player.takeDamage( 1 ) == 0)
				return false;
		}
		j = 0;
		while (j < this->_enemies[i].getNbMissiles()) { //Collision player/missile
			if (this->_player.onCollision(this->_enemies[i].getMissiles()[j])) {
				this->_enemies[i].deleteMissile(j);
				if(this->_player.takeDamage( 1 ) == 0)
					return false;
				break;
			}
			++j;
		}
		while (j < this->_player.getNbMissiles()) { //Collision ennemy/missile
			if (this->_enemies[i].onCollision(this->_player.getMissiles()[j])) {
				this->deleteEnemy(i);
				this->_player.deleteMissile(j);
				--i;
				this->_score++;
				break;
			}
			++j;
		}
		++i;
	}
	return true;
}

