/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:42:21 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 19:51:45 by eduwer           ###   ########.fr       */
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
	std::string output;
	srand(time(NULL));
	setlocale(LC_ALL,"");
	// Map *map = new Map();
	// Enemy *enemy = new Enemy();
	GameObject *GO = new GameObject();
	int noExit = 1;
	int posY = LINES / 2;
	int posX = COLS / 2;
	int keyPressed;
	// halfdelay(1);
	// nodelay(stdscr,TRUE);
	// timeout();
	start_color();			/* Start color 			*/

	keypad(stdscr, TRUE);
	noecho();
	move(posY, posX - 14);
	printw("BIENVENUE SUR SPACE INVADERS");
	int frames = 0;
	nodelay(stdscr, true);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	while (noExit) {
		frames++;
		if (frames % 100 == 0)
			GO->newEnemy();
		keyPressed = getch();
		if (keyPressed == 27)
			noExit = 0;
		erase();
		GO->updateGame(keyPressed);
 		wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0);
 		move(0, 5);
		attron(COLOR_PAIR(4));
		output = "Welcome to Space invaders ! Score = " + std::to_string(GO->getScore()) + " ";
		addstr(output.c_str());
		attroff(COLOR_PAIR(4));
 		napms(17);
		wrefresh(stdscr);
	}
	endwin();
	return 0;
}
