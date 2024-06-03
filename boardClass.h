#pragma once
#include "tetriminoClass.h"
#include <SFML/Graphics.hpp>

class Board {

private:
	sf::RectangleShape bg;
	sf::RectangleShape boardSq;
	int** boardNum;

public:

	Board() {

		// start of initialization

			// initializing background rectangle
		bg.setSize(sf::Vector2f(304.f, 594.f));				// set the background size
		bg.setOutlineThickness(2.0f);
		bg.setFillColor(sf::Color(50, 50, 50));			// and the background size
		bg.setOutlineColor(sf::Color(25, 25, 25));
		bg.setPosition(sf::Vector2f(40.f, 25.f));			// and where on the screen it should show

			//initializing grid square
		boardSq.setSize(sf::Vector2f(23.f, 23.f));				// setting the size of the square
		boardSq.setOutlineThickness(2.f);						// we will use to print the grid colors

			// initializing the board numbers 
			// (boardSq will reference this to output the 
			// right squares and their appropriate colors)
		boardNum = new int* [10];

		for (int i = 0; i < 10; i++) {

			boardNum[i] = new int[20];		// making the board size 20 * 10, cause Tetris

			for (int j = 0; j < 20; j++) {
				boardNum[i][j] = 0;				// setting all values to zero to start
			}

		}

		// end of initialization

	}

	void setSomeSq() {			// purely for testing purposes (colors and positions and stuff)
		
		boardNum[3][15] = 1;
		boardNum[0][8] = 2;
		boardNum[5][9] = 3;
		boardNum[2][6] = 4;
		boardNum[7][17] = 5;
		boardNum[9][19] = 1;
		boardNum[0][0] = 3;
		boardNum[6][19] = 6;
		boardNum[4][0] = 6;
		boardNum[9][12] = 7;
		
	}

	void resetBoard() {

		for (int i = 0; i < 10; i++) {			// now making boardSq a specific color based on boardNum[i][j]
			for (int j = 0; j < 20; j++) {

				boardNum[i][j] = 0;

			}
		}

	}

	void addPiecesToBoard(int** pN, int s, int xP, int yP) {

		for (int i = 0; i < s; i++) {			// now making boardSq a specific color based on boardNum[i][j]
			for (int j = 0; j < s; j++) {

				if (pN[i][j] != 0) {
					boardNum[i + xP][j + yP] = pN[i][j];
				}

			}
		}

	}

	int clearFullRows() {

		int flag = 0;
		int temp = 0;
		int score = 0;

		for (int i = 0; i < 20; i++) {			// now making boardSq a specific color based on boardNum[i][j]
			for (int j = 0; j < 10; j++) {

				if (boardNum[j][i] == 0) { flag = 1; }

			}

			if (flag == 0) {

				for (int k = 0; k < 10; k++) {
					boardNum[k][i] = 0;

					for (int l = i; l > 0; l--) {
						temp = boardNum[k][l]; boardNum[k][l] = boardNum[k][l - 1]; boardNum[k][l - 1] = temp;
					}
					temp = 0;

				}

				score += 100;

			}
			flag = 0;

		}

		return score;

	}

	int clearFullRows(int& lD) {

		int flag = 0;
		int temp = 0;
		int score = 0;

		for (int i = 0; i < 20; i++) {			// now making boardSq a specific color based on boardNum[i][j]
			for (int j = 0; j < 10; j++) {

				if (boardNum[j][i] == 0) { flag = 1; }

			}

			if (flag == 0) {

				for (int k = 0; k < 10; k++) {
					boardNum[k][i] = 0;

					for (int l = i; l > 0; l--) {
						temp = boardNum[k][l]; boardNum[k][l] = boardNum[k][l - 1]; boardNum[k][l - 1] = temp;
					}
					temp = 0;

				}

				score += 100;
				lD++;

			}
			flag = 0;

		}

		return score;

	}

	void loadBoard(sf::RenderWindow& window) {

		window.draw(bg);		// output the background first

		for (int i = 0; i < 10; i++) {			// now making boardSq a specific color based on boardNum[i][j]
			for (int j = 0; j < 20; j++) {

				if (boardNum[i][j] == 0) {								// nothing
					boardSq.setFillColor(sf::Color::Black);
					boardSq.setOutlineColor(sf::Color::Black);
				}
				else if (boardNum[i][j] == 1) {							// cyan square
					boardSq.setFillColor(sf::Color(0, 255, 255));
					boardSq.setOutlineColor(sf::Color(0, 175, 175));
				}
				else if (boardNum[i][j] == 2) {							// blue square
					boardSq.setFillColor(sf::Color::Blue);
					boardSq.setOutlineColor(sf::Color(0, 0, 175));
				}
				else if (boardNum[i][j] == 3) {							// orange square
					boardSq.setFillColor(sf::Color(255, 128, 0));
					boardSq.setOutlineColor(sf::Color(175, 100, 0));
				}
				else if (boardNum[i][j] == 4) {							// yellow square
					boardSq.setFillColor(sf::Color::Yellow);
					boardSq.setOutlineColor(sf::Color(175, 175, 0));
				}
				else if (boardNum[i][j] == 5) {							// green square
					boardSq.setFillColor(sf::Color::Green);
					boardSq.setOutlineColor(sf::Color(0, 175, 0));
				}
				else if (boardNum[i][j] == 6) {							// purple square
					boardSq.setFillColor(sf::Color(128, 0, 255));
					boardSq.setOutlineColor(sf::Color(100, 0, 175));
				}
				else if (boardNum[i][j] == 7) {							// red square
					boardSq.setFillColor(sf::Color::Red);
					boardSq.setOutlineColor(sf::Color(175, 0, 0));
				}

				boardSq.setPosition(sf::Vector2f(float(50 + (29 * i)), float(35 + (29 * j))));		// and now setting position
																									// of each square
				window.draw(boardSq);

			}
		}

	}

	bool checkForLoss() {
		
		bool flag = false;

		for (int i = 0; i < 10; i++) {

			if (boardNum[i][0] != 0) { flag = true; }

		}

		return flag;

	}

	int** returnBoardNum() {
		return boardNum;
	}

	~Board() {

		for (int i = 0; i < 10; i++) {
			delete[] boardNum[i];
		}

		delete[] boardNum;

	}


};