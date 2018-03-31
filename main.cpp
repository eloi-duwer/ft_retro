/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 21:42:21 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 14:47:18 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <sstream>
int main() {
	initscr();
	
	int noExit = 1;
	int posY = LINES / 2;
	int posX = COLS / 2;
	int keyPressed;
	halfdelay(1);
	keypad(stdscr, TRUE);
	noecho();
	while (noExit) {
		keyPressed = getch();
		if (keyPressed == KEY_DOWN)
			posY += 1;
		else if (keyPressed == KEY_UP)
			posY -= 1;
		else if (keyPressed == KEY_RIGHT)
			posX += 1;
		else if (keyPressed == KEY_LEFT)
			posX -= 1;
		else if (keyPressed == KEY_EXIT)
			noExit = 0;
		move(posY, posX);
		addch('.');
		refresh();
	}
	endwin();
	return 0;
}
