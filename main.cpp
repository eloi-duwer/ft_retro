/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:42:21 by eduwer            #+#    #+#             */
/*   Updated: 2018/04/01 19:54:41 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <sstream>


#include "Map.hpp"
#include "AObject.hpp"
#include "Enemy.hpp"
#include "GameObject.hpp"

void	endScreen( GameObject &GO, int time) {

	std::string	text("GAME OVER");
	WINDOW *win = subwin(stdscr, 10, 50, LINES / 2 - 5, COLS / 2 - 25);
	wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
	mvwprintw(win, 2, 25 - text.size() / 2, text.c_str());
	text = "Score: " + std::to_string(GO.getScore());
	mvwprintw(win, 4, 25 - text.size() / 2, text.c_str());
	text = "Time survived: " + std::to_string(time) + " seconds";
	mvwprintw(win, 6, 25 - text.size() / 2, text.c_str());
	wrefresh(win);
	wrefresh(stdscr);
	nodelay(stdscr, FALSE);
	napms(3000);
	delwin(win);
	endwin();
	std::exit(0);

}

int main() {
	initscr();
	std::string output;
	srand(time(NULL));
	setlocale(LC_ALL,"");
	GameObject GO;
	int noExit = 1;
	int posY = LINES / 2;
	int posX = COLS / 2;
	int keyPressed;

	start_color();

	keypad(stdscr, TRUE);
	noecho();
	move(posY, posX - 14);
	printw("BIENVENUE SUR SPACE INVADERS");
	int frames = 0;
	nodelay(stdscr, true);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_WHITE);
	while (noExit) {
		frames++;
		if (frames % 100 == 0)
			GO.newEnemy();
		keyPressed = getch();
		if (keyPressed == 27)
			break;
		erase();
		if (!GO.updateGame(keyPressed))
			break;
		wborder(stdscr, 0, 0, 0, 0, 0, 0, 0, 0);
		move(0, 5);
		attron(COLOR_PAIR(6));
		output = "Welcome to Space invaders ! Score = " + std::to_string(GO.getScore());
		output += ", lifes: " + std::to_string(GO.getPlayer().getHp());
		output += ", time in life: " + std::to_string((frames * 17) / 1000) + " seconds";
		addstr(output.c_str());
		attroff(COLOR_PAIR(6));
		napms(17);
		wrefresh(stdscr);
	}
	endScreen(GO, (frames * 17) / 1000);
	return 0;
}
