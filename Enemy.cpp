/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:19:03 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 15:27:00 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Object.hpp"
#include <ncurses.h>
#include <cstdlib>

Enemy::Enemy( void ) : Object(std::rand() % COLS, 0, 2) {



}
