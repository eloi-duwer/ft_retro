/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:42:21 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/30 23:43:40 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <sstream>
int main() {
	initscr();
	
	int noExit = 1;
	int posX = LINES / 2;
	int posY = COLS / 2;
	int keyPressed;
	halfdelay(1);
	keypad(stdscr, TRUE);
	noecho();
	while (noExit) {
		keyPressed = getch();
		if (keyPressed == KEY_DOWN)
			posX += 1;
		else if (keyPressed == KEY_UP)
			posX -= 1;
		else if (keyPressed == KEY_RIGHT)
			posY += 1;
		else if (keyPressed == KEY_LEFT)
			posY -= 1;
		else if (keyPressed == KEY_EXIT)
			noExit = 0;
		move(posX, posY);
		addch('.');
		refresh();
	}
	endwin();
	return 0;
}
