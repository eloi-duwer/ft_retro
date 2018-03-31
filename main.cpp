/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:42:21 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 17:27:20 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <sstream>


#include "Map.hpp"
#include "AObject.hpp"
#include "Enemy.hpp"
#include "GameObject.hpp"


int main() {
	initscr();
	
	srand(time(NULL));
	// Map *map = new Map();
	// Enemy *enemy = new Enemy();
	GameObject *GO = new GameObject();
	int noExit = 1;
	int posY = LINES / 2;
	int posX = COLS / 2;
	int keyPressed;
	halfdelay(1);
	keypad(stdscr, TRUE);
	noecho();
	move(posY, posX - 14);
	printw("BIENVENUE SUR SPACE INVADERS");
	int frames = 0;
	while (noExit) {
		frames++;
		if (frames % 20 == 0)
			GO->newEnemy();
		keyPressed = getch();
		if (keyPressed == KEY_DOWN)
			posY += 1;
		else if (keyPressed == KEY_UP)
			posY -= 1;
		else if (keyPressed == KEY_RIGHT)
			posX += 1;
		else if (keyPressed == KEY_LEFT)
			posX -= 1;
		else if (keyPressed == 27)
			noExit = 0;
		erase();
		GO->updateGame(0);
		wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0);
		wrefresh(stdscr);
	}
	endwin();
	return 0;
}
