#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Tetrimino {

private:

	int x_pos, y_pos;
	sf::RectangleShape pieceSq;
	bool isLastMove = false;
	bool isOverLap = false;

protected:

	int size;
	int** pieceNum;

public:

	Tetrimino() {

		size = 3;
		x_pos = 3;
		y_pos = 0;

		pieceSq.setSize(sf::Vector2f(23.f, 23.f));
		pieceSq.setOutlineThickness(2.f);

		pieceNum = new int* [size];
		for (int i = 0; i < size; i++) {
			pieceNum[i] = new int[size];

			for (int j = 0; j < size; j++) {
				pieceNum[i][j] = 0;
			}

		}

	}

	Tetrimino(Tetrimino& copy) {

		size = copy.size;
		x_pos = copy.x_pos;
		y_pos = copy.y_pos;

		pieceSq.setSize(sf::Vector2f(23.f, 23.f));
		pieceSq.setOutlineThickness(2.f);

		pieceNum = new int* [size];
		for (int i = 0; i < size; i++) {
			pieceNum[i] = new int[size];

			for (int j = 0; j < size; j++) {
				pieceNum[i][j] = copy.pieceNum[i][j];
			}

		}

	}

	void signalLastMove() {
		isLastMove = true;
	}

	void lastMoveOver() {
		isLastMove = false;
	}

	void signalOverLap() {
		isOverLap = true;
	}

	void overlapOver() {
		isOverLap = false;
	}

	void loadColors(int pieceNo) {

		if (pieceNo == 0) {								// nothing
			//cout << "here ";
			pieceSq.setFillColor(sf::Color::Transparent);
			pieceSq.setOutlineColor(sf::Color::Transparent);
		}
		else if (pieceNo == 1) {							// cyan square
			//cout << "here1 ";
			pieceSq.setFillColor(sf::Color(0, 255, 255));
			pieceSq.setOutlineColor(sf::Color(0, 175, 175));
		}
		else if (pieceNo == 2) {							// blue square
			//cout << "here2 ";
			pieceSq.setFillColor(sf::Color::Blue);
			pieceSq.setOutlineColor(sf::Color(0, 0, 175));
		}
		else if (pieceNo == 3) {							// orange square
			//cout << "here3 ";
			pieceSq.setFillColor(sf::Color(255, 128, 0));
			pieceSq.setOutlineColor(sf::Color(175, 100, 0));
		}
		else if (pieceNo == 4) {							// yellow square
			//cout << "here4 ";
			pieceSq.setFillColor(sf::Color::Yellow);
			pieceSq.setOutlineColor(sf::Color(175, 175, 0));
		}
		else if (pieceNo == 5) {							// green square
			//cout << "here5 ";
			pieceSq.setFillColor(sf::Color::Green);
			pieceSq.setOutlineColor(sf::Color(0, 175, 0));
		}
		else if (pieceNo == 6) {							// purple square
			//cout << "here6 ";
			pieceSq.setFillColor(sf::Color(128, 0, 255));
			pieceSq.setOutlineColor(sf::Color(100, 0, 175));
		}
		else if (pieceNo == 7) {							// red square
			//cout << "here7 ";
			pieceSq.setFillColor(sf::Color::Red);
			pieceSq.setOutlineColor(sf::Color(175, 0, 0));
		}

		if (isLastMove && pieceNo > 0) { pieceSq.setOutlineColor(sf::Color::White); }
		if (isOverLap && pieceNo > 0) { pieceSq.setOutlineColor(sf::Color(255, 50, 50)); }

	}

	void loadPiece(sf::RenderWindow& window) {
		
		for (int i = 0; i < size; i++) {			// now making boardSq a specific color based on boardNum[i][j]
			for (int j = 0; j < size; j++) {

				if (pieceNum[i][j] == 0) {								// nothing
					//cout << "here ";
					pieceSq.setFillColor(sf::Color::Transparent);
					pieceSq.setOutlineColor(sf::Color::Transparent);
				}
				else if (pieceNum[i][j] == 1) {							// cyan square
					//cout << "here1 ";
					pieceSq.setFillColor(sf::Color(0, 255, 255));
					pieceSq.setOutlineColor(sf::Color(0, 175, 175));
				}
				else if (pieceNum[i][j] == 2) {							// blue square
					//cout << "here2 ";
					pieceSq.setFillColor(sf::Color::Blue);
					pieceSq.setOutlineColor(sf::Color(0, 0, 175));
				}
				else if (pieceNum[i][j] == 3) {							// orange square
					//cout << "here3 ";
					pieceSq.setFillColor(sf::Color(255, 128, 0));
					pieceSq.setOutlineColor(sf::Color(175, 100, 0));
				}
				else if (pieceNum[i][j] == 4) {							// yellow square
					//cout << "here4 ";
					pieceSq.setFillColor(sf::Color::Yellow);
					pieceSq.setOutlineColor(sf::Color(175, 175, 0));
				}
				else if (pieceNum[i][j] == 5) {							// green square
					//cout << "here5 ";
					pieceSq.setFillColor(sf::Color::Green);
					pieceSq.setOutlineColor(sf::Color(0, 175, 0));
				}
				else if (pieceNum[i][j] == 6) {							// purple square
					//cout << "here6 ";
					pieceSq.setFillColor(sf::Color(128, 0, 255));
					pieceSq.setOutlineColor(sf::Color(100, 0, 175));
				}
				else if (pieceNum[i][j] == 7) {							// red square
					//cout << "here7 ";
					pieceSq.setFillColor(sf::Color::Red);
					pieceSq.setOutlineColor(sf::Color(175, 0, 0));
				}

				//pieceSq.setPosition(sf::Vector2f(float(50 + (29 * (i + x_pos))), float(35 + (29 * (j + y_pos)))));
				pieceSq.setPosition(sf::Vector2f(50.f + (29.f * float(i + x_pos)), 35.f + (29.f * float(j + y_pos))));
				//pieceSq.move(sf::Vector2f(50 + (29 * (i + x_pos)), 35 + (29 * (j + y_pos))));
																									// and now setting position
																									// of each square
				
				window.draw(pieceSq);

			}
			//cout << endl;
		}
		//cout << endl;

	}

	void loadPiece2(sf::RenderWindow& window) {

		for (int i = 0; i < size; i++) {			// now making boardSq a specific color based on boardNum[i][j]
			for (int j = 0; j < size; j++) {

				loadColors(pieceNum[i][j]);

				//pieceSq.setPosition(sf::Vector2f(float(50 + (29 * (i + x_pos))), float(35 + (29 * (j + y_pos)))));
				pieceSq.setPosition(sf::Vector2f(50.f + (29.f * float(i + x_pos)), 35.f + (29.f * float(j + y_pos))));
				//pieceSq.move(sf::Vector2f(50 + (29 * (i + x_pos)), 35 + (29 * (j + y_pos))));
																									// and now setting position
																									// of each square

				window.draw(pieceSq);

			}
			//cout << endl;
		}
		//cout << endl;

	}

	void loadPiece(sf::RenderWindow& window, int xP, int yP) {		// for testing pieces

		for (int i = 0; i < size; i++) {			// now making boardSq a specific color based on boardNum[i][j]
			for (int j = 0; j < size; j++) {

				if (pieceNum[i][j] == 0) {								// nothing
					pieceSq.setFillColor(sf::Color::Transparent);
					pieceSq.setOutlineColor(sf::Color::Transparent);
				}
				else if (pieceNum[i][j] == 1) {							// cyan square
					pieceSq.setFillColor(sf::Color(0, 255, 255));
					pieceSq.setOutlineColor(sf::Color(0, 175, 175));
				}
				else if (pieceNum[i][j] == 2) {							// blue square
					pieceSq.setFillColor(sf::Color::Blue);
					pieceSq.setOutlineColor(sf::Color(0, 0, 175));
				}
				else if (pieceNum[i][j] == 3) {							// orange square
					pieceSq.setFillColor(sf::Color(255, 128, 0));
					pieceSq.setOutlineColor(sf::Color(175, 100, 0));
				}
				else if (pieceNum[i][j] == 4) {							// yellow square
					pieceSq.setFillColor(sf::Color::Yellow);
					pieceSq.setOutlineColor(sf::Color(175, 175, 0));
				}
				else if (pieceNum[i][j] == 5) {							// green square
					pieceSq.setFillColor(sf::Color::Green);
					pieceSq.setOutlineColor(sf::Color(0, 175, 0));
				}
				else if (pieceNum[i][j] == 6) {							// purple square
					pieceSq.setFillColor(sf::Color(128, 0, 255));
					pieceSq.setOutlineColor(sf::Color(100, 0, 175));
				}
				else if (pieceNum[i][j] == 7) {							// red square
					pieceSq.setFillColor(sf::Color::Red);
					pieceSq.setOutlineColor(sf::Color(175, 0, 0));
				}

				pieceSq.setPosition(sf::Vector2f(float(50 + (29 * (i + xP))), float(35 + (29 * (j + yP)))));	
																								// and now setting position
																								// of each square

				window.draw(pieceSq);

			}
		}

	}

	void loadPiece2(sf::RenderWindow& window, int xP, int yP) {

		for (int i = 0; i < size; i++) {			// now making boardSq a specific color based on boardNum[i][j]
			for (int j = 0; j < size; j++) {

				loadColors(pieceNum[i][j]);

				//pieceSq.setPosition(sf::Vector2f(float(50 + (29 * (i + x_pos))), float(35 + (29 * (j + y_pos)))));
				pieceSq.setPosition(sf::Vector2f(float(50 + (29 * (i + xP))), float(35 + (29 * (j + yP)))));
				//pieceSq.move(sf::Vector2f(50 + (29 * (i + x_pos)), 35 + (29 * (j + y_pos))));
																									// and now setting position
																									// of each square

				window.draw(pieceSq);

			}
			//cout << endl;
		}
		//cout << endl;

	}

	void loadPiece2(sf::RenderWindow& window, float xP, float yP) {

		for (int i = 0; i < size; i++) {			// now making boardSq a specific color based on boardNum[i][j]
			for (int j = 0; j < size; j++) {

				loadColors(pieceNum[i][j]);

				//pieceSq.setPosition(sf::Vector2f(float(50 + (29 * (i + x_pos))), float(35 + (29 * (j + y_pos)))));
				//pieceSq.setPosition(sf::Vector2f(50.f + (29.f * i) + (29.f * xP), 35.f + (29.f * j) + (29.f * yP)));
				pieceSq.setPosition(sf::Vector2f((29.f * i) + xP, (29.f * j) + yP));
				//pieceSq.move(sf::Vector2f(50 + (29 * (i + x_pos)), 35 + (29 * (j + y_pos))));
																									// and now setting position
																									// of each square

				window.draw(pieceSq);

			}
			//cout << endl;
		}
		//cout << endl;

	}

	int checkForBounds_left(int** bN, int x, int y) {

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {

				//cout << "left -> " << i << ", " << j << "; " << x << ", " << y << " : ";

				if (pieceNum[i][j] != 0) {

					/*if (i == 0) {

						if (i + x == 0) { return 1; }
						else if (bN[i + x - 1][j + y] != 0) { return 2; }

					}*/
					if (i + x <= 0) {
						return 1;
					}
					else if (i == 0) {

						if (bN[i + x - 1][j + y] != 0) { return 2; }

					}
					else {

						if (pieceNum[i - 1][j] == 0 
							&& bN[i + x - 1][j + y] != 0) {
							return 2; 
						}

					}

				}

			}
			//cout << endl;
		}

		return 0;

	}

	int checkForBounds_left2(int** bN, int x, int y) {

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {

				if (pieceNum[i][j] != 0) {

					if (i + x <= 0) {
						return 1;
					}
					else if (i == 0) {

						if (bN[i + x - 1][j + y] != 0) { return 2; }

					}
					//else if (j + y)
					else {

						if (pieceNum[i - 1][j] == 0
							&& bN[i + x - 1][j + y] != 0) {
							return 2;
						}

					}

				}

			}
			//cout << endl;
		}

		return 0;

	}

	int checkForBounds_right(int** bN, int x, int y) {

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {

				//cout << "right -> " << i << ", " << j << "; " << x << ", " << y << " : ";

				if (pieceNum[i][j] != 0) {

					/*if (i == (size - 1)) {

						if (i + x == 9) { return 1; }
						else if (bN[i + x + 1][j + y] != 0) { return 2; }

					}*/
					//if (x == 9) { return 1; }
					if (i + x >= 9) {
						return 1;
					}
					else if (i == (size - 1)) {

						if (bN[i + x + 1][j + y] != 0) { return 2; }

					}
					else {

						if (pieceNum[i + 1][j] == 0 && bN[i + x + 1][j + y] != 0) { return 2; }

					}

				}

			}
			//cout << endl;
		}

		return 0;

	}

	//else ((i + x_pos) <= 0 || (i + x_pos) >= 9) { return 1; }

	int checkForBounds_down(int** bN, int x, int y) {

		for (int i = 0; i < size; i++) {
			for (int j = size - 1; j >= 0; j--) {

				//cout << "down -> " << i << ", " << j << "; " << x << ", " << y << " : ";

				if (pieceNum[i][j] != 0) {

					if (j + y >= 19) { return 1; }
					else if (j == size - 1) {
						
						if (bN[i + x][j + y + 1] != 0) { return 2; }

					}
					else {

						if (pieceNum[i][j + 1] == 0 && bN[i + x][j + y + 1] != 0) { return 2; }

					}

				}

			}
			//cout << endl;
		}

		return 0;

	}

	int checkForBounds_down(int** bN) {

		for (int i = 0; i < size; i++) {
			for (int j = size - 1; j >= 0; j--) {

				if (pieceNum[i][j] != 0) {

					//cout << "i = " << i << ", x = " << x_pos << ", j = " << j << ", y = " << y_pos << endl;
					//cout << " [i + x_pos][j + y_pos] = [" << (i + x_pos) << "][" << (j + y_pos) << "]" << endl;

					if (j + y_pos >= 19) { return 1; }
					else if (j == size - 1) {

						if (bN[i + x_pos][j + y_pos + 1] != 0) { return 2; }

					}
					else {

						if (pieceNum[i][j + 1] == 0 && bN[i + x_pos][j + y_pos + 1] != 0) { return 2; }

					}

				}

			}
			//cout << endl;
		}

		return 0;

	}

	int checkForBounds_down2(int** bN, int x, int y) {

		for (int i = 0; i < size; i++) {
			for (int j = size - 1; j >= 0; j--) {

				//cout << "down -> " << i << ", " << j << "; " << x << ", " << y << " : ";

				if (pieceNum[i][j] != 0) {

					if (j + y >= 19) { return 1; }
					else if ((i + x) <= 0 || (i + x) >= 9) { return 1; }
					else if (j == size - 1) {

						if (bN[i + x][j + y + 1] != 0) { return 2; }

					}
					else {

						if (pieceNum[i][j + 1] == 0 && bN[i + x][j + y + 1] != 0) { return 2; }

					}

				}

			}
			//cout << endl;
		}

		return 0;

	}

	int checkForBounds_down2(int** bN) {

		for (int i = 0; i < size; i++) {
			for (int j = size - 1; j >= 0; j--) {

				if (pieceNum[i][j] != 0) {

					if (j + y_pos >= 19) { return 1; }
					else if ((i + x_pos) <= 0 || (i + x_pos) >= 9) { return 1; }
					else if (j == size - 1) {

						if (bN[i + x_pos][j + y_pos + 1] != 0) { return 2; }

					}
					else {

						if (pieceNum[i][j + 1] == 0 && bN[i + x_pos][j + y_pos + 1] != 0) { return 2; }

					}

				}

			}
			//cout << endl;
		}

		return 0;

	}

	void moveDown(int** bN) {

		//if (y_pos < (20 - size)) { y_pos++; }				// needs to stop going down when a block is located

		if (checkForBounds_down(bN, x_pos, y_pos) == 0) {
			y_pos++;
		}

	}

	bool moveDown2(int** bN) {

		//if (y_pos < (20 - size)) { y_pos++; }				// needs to stop going down when a block is located

		if (checkForBounds_down(bN, x_pos, y_pos) == 0) {
			y_pos++;
			return false;
		}
		return true;

	}

	void rotateBlock() {

		int** tempNum = new int* [size];
		for (int i = 0; i < size; i++) {
			tempNum[i] = new int[size];
			for (int j = 0; j < size; j++) { tempNum[i][j] = pieceNum[i][j]; }
		}

		for (int k = 0; k < size; k++) {
			for (int l = 0; l < size; l++) {

				pieceNum[(size - 1) - k][l] = tempNum[l][k];

			}
		}

		for (int m = 0; m < size; m++) {
			delete[] tempNum[m];
		}
		delete[] tempNum;

	}

	void rotateBlockBack() {

		int** tempNum = new int* [size];
		for (int i = 0; i < size; i++) {
			tempNum[i] = new int[size];
			for (int j = 0; j < size; j++) { tempNum[i][j] = pieceNum[i][j]; }
		}

		for (int k = 0; k < size; k++) {
			for (int l = 0; l < size; l++) {

				pieceNum[l][k] = tempNum[(size - 1) - k][l];

			}
		}

		for (int m = 0; m < size; m++) {
			delete[] tempNum[m];
		}
		delete[] tempNum;

	}

	void movementInput(sf::Event event_var) {

		//if (event_var.key.code == sf::Keyboard::Up) {

		//	//cout << size << endl;
		//	int** tempNum = new int* [size];
		//	for (int i = 0; i < size; i++) {
		//		tempNum[i] = new int[size];
		//		for (int j = 0; j < size; j++) { tempNum[i][j] = pieceNum[i][j]; }
		//	}

		//	for (int k = 0; k < size; k++) {
		//		for (int l = 0; l < size; l++) {
		//			
		//			pieceNum[(size - 1) - k][l] = tempNum[l][k];

		//		}
		//	}

		//	for (int m = 0; m < size; m++) {
		//		delete[] tempNum[m];
		//	}
		//	delete[] tempNum;

		//}
		//else if (event_var.key.code == sf::Keyboard::Z) {

		//	//cout << size << endl;
		//	int** tempNum = new int* [size];
		//	for (int i = 0; i < size; i++) {
		//		tempNum[i] = new int[size];
		//		for (int j = 0; j < size; j++) { tempNum[i][j] = pieceNum[i][j]; }
		//	}

		//	for (int k = 0; k < size; k++) {
		//		for (int l = 0; l < size; l++) {

		//			pieceNum[l][k] = tempNum[(size - 1) - k][l];

		//		}
		//	}

		//	for (int m = 0; m < size; m++) {
		//		delete[] tempNum[m];
		//	}
		//	delete[] tempNum;

		//}
		//else 


		if (event_var.key.code == sf::Keyboard::Left) {

			if (x_pos > 0) { x_pos--; } // upgrade coding procedure based on where the left-most color is, cause yes

			/*if (checkForBounds_left(bN, x_pos, y_pos) == 0) {

				x_pos--;

			}*/

		}
		else if (event_var.key.code == sf::Keyboard::Right) {

			if (x_pos < (10 - size)) { x_pos++; } // upgrade coding procedure based on where the right-most color is

			/*if (checkForBounds_right(bN, x_pos, y_pos) == 0) {

				x_pos++;

			}*/

		}
		else if (event_var.key.code == sf::Keyboard::Down) {

			if (y_pos < (20 - size)) { y_pos++; }				// needs to stop going down when a block is located

			/*if (checkForBounds_right(bN, x_pos, y_pos) == 0) {

				y_pos++;

			}*/

		}

	}

	void movementInput2(sf::Event event_var, int** bN) {

		if (event_var.key.code == sf::Keyboard::Up) {

			//cout << size << endl;
			/*int** tempNum = new int* [size];
			for (int i = 0; i < size; i++) {
				tempNum[i] = new int[size];
				for (int j = 0; j < size; j++) { tempNum[i][j] = pieceNum[i][j]; }
			}

			for (int k = 0; k < size; k++) {
				for (int l = 0; l < size; l++) {
					
					pieceNum[(size - 1) - k][l] = tempNum[l][k];

				}
			}

			for (int m = 0; m < size; m++) {
				delete[] tempNum[m];
			}
			delete[] tempNum;*/

		}
		else if (event_var.key.code == sf::Keyboard::Z) {

			//cout << size << endl;
			/*int** tempNum = new int* [size];
			for (int i = 0; i < size; i++) {
				tempNum[i] = new int[size];
				for (int j = 0; j < size; j++) { tempNum[i][j] = pieceNum[i][j]; }
			}

			for (int k = 0; k < size; k++) {
				for (int l = 0; l < size; l++) {

					pieceNum[l][k] = tempNum[(size - 1) - k][l];

				}
			}

			for (int m = 0; m < size; m++) {
				delete[] tempNum[m];
			}
			delete[] tempNum;*/

		}
		else if (event_var.key.code == sf::Keyboard::Left) {

			//if (x_pos > 0) { x_pos--; } // upgrade coding procedure based on where the left-most color is, cause yes

			if (checkForBounds_left(bN, x_pos, y_pos) == 0) {

				x_pos--;

			}

		}
		else if (event_var.key.code == sf::Keyboard::Right) {

			if (checkForBounds_right(bN, x_pos, y_pos) == 0) {

				x_pos++;

			}

		}
		else if (event_var.key.code == sf::Keyboard::Down) {
																			// needs to stop going down when
			if (checkForBounds_down(bN, x_pos, y_pos) == 0) { y_pos++; }	// a block is located or when it
																			// hits the floor
		}

	}

	bool movementInput2_1(sf::Event event_var, int** bN) {

		if (event_var.key.code == sf::Keyboard::Left) {

			if (checkForBounds_left(bN, x_pos, y_pos) == 0) {

				x_pos--;
				return true;

			}

		}
		else if (event_var.key.code == sf::Keyboard::Right) {

			if (checkForBounds_right(bN, x_pos, y_pos) == 0) {

				x_pos++;
				return true;

			}

		}
		else if (event_var.key.code == sf::Keyboard::Down) {
																			// needs to stop going down when
			if (checkForBounds_down(bN, x_pos, y_pos) == 0) { y_pos++; }	// a block is located or when it
																			// hits the floor
			return true;
		}

		return false;

	}

	void movementInput3(sf::Event event_var, int** bN) {

		int og_x = 0; int og_y = 0;
		bool fitsOnLeft = false, fitsOnRight = false, fitsAbove = false;
		bool notOverlapping = false;

		if (event_var.key.code == sf::Keyboard::Up) {

			rotateBlock();
			//cout << "rotateBlock called" << endl;
			og_x = x_pos;
			og_y = y_pos;

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {

					if (pieceNum[i][j] != 0) {

						if ((i + x_pos) < 0 || x_pos < 0) { x_pos = 0; }
						else if ((i + x_pos) > 9 || x_pos > 9) { x_pos = 9 - i; }
						
						if ((j + y_pos) < 0 || y_pos < 0) { y_pos = 0; }
						else if ((j + y_pos) > 19) { y_pos = 19 - j; }

					}

				}
			}

			for (int i = 0; i < 3 && !(notOverlapping); i++) {
				if (checkForOverLapping2(bN)) {

					if (i == 0) { x_pos++; }
					if (i == 1) { x_pos -= 2; }
					if (i == 2) { x_pos++; y_pos--; }

				}
				else { notOverlapping = true; }
			}

			if (notOverlapping == false) { x_pos = og_x; y_pos = og_y; rotateBlockBack(); }

		}
		else if (event_var.key.code == sf::Keyboard::Z) {

			og_x = x_pos;
			og_y = y_pos;

			rotateBlockBack();
			//cout << "rotateBlock called" << endl;

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {

					if (pieceNum[i][j] != 0) {

						if ((i + x_pos) < 0 || x_pos < 0) { x_pos = 0; }
						else if ((i + x_pos) > 9 || x_pos > 9) { x_pos = 9 - i; }

						if ((j + y_pos) > 19) { y_pos = 19 - j; }

					}

				}
			}

			for (int i = 0; i < 3 && !(notOverlapping); i++) {
				if (checkForOverLapping2(bN)) {

					if (i == 0) { x_pos++; }
					if (i == 1) { x_pos -= 2; }
					if (i == 2) { x_pos++; y_pos--; }

				}
				else { notOverlapping = true; }
			}

			if (notOverlapping == false) { x_pos = og_x; y_pos = og_y; rotateBlock(); }

		}
		else if (event_var.key.code == sf::Keyboard::Left) {


			if (checkForBounds_left(bN, x_pos, y_pos) == 0) { x_pos--; }

		}
		else if (event_var.key.code == sf::Keyboard::Right) {

			if (checkForBounds_right(bN, x_pos, y_pos) == 0) { x_pos++; }

		}
		else if (event_var.key.code == sf::Keyboard::Down) {
			
			if (checkForBounds_down(bN, x_pos, y_pos) == 0) { y_pos++; }
			
		}

		fitsOnLeft = false; fitsOnRight = false; fitsAbove = false;

	}

	int** returnPieceNum() {
		return pieceNum;
	}

	int returnSize() {
		return size;
	}

	int returnXPos() {
		return x_pos;
	}

	int returnYPos() {
		return y_pos;
	}

	void setXPos(int xP) {
		x_pos = xP;
	}

	void setXnYPos(int xP, int yP) {
		x_pos = xP; y_pos = yP;
	}

	void placeAt(int xP, int yP) {

		for (int i = 0; i < size; i++) {			// now making boardSq a specific color based on boardNum[i][j]
			for (int j = 0; j < size; j++) {

				pieceSq.setPosition(sf::Vector2f(float(50 + (29 * (i + xP))), float(35 + (29 * (j + yP)))));
				
			}
			
		}

	}

	bool checkForOverLapping(int** bN) {

		bool flag = false;

		for (int i = 0; i < size && !(flag); i++) {
			for (int j = 0; j < size && !(flag); j++) {

				if (pieceNum[i][j] != 0 && bN[i + x_pos][j + y_pos] != 0) { flag = true; }

			}
		}

		return flag;

	}

	bool checkForOverLapping(int** bN, int xP, int yP) {

		bool flag = false;

		for (int i = 0; i < size && !(flag); i++) {
			for (int j = 0; j < size && !(flag); j++) {

				if (pieceNum[i][j] != 0) {

					if (bN[i + xP][j + yP] != 0) { flag = true; }

				}

			}
		}

		return flag;

	}

	bool checkForOverLapping2(int** bN) {

		bool flag = false;

		for (int i = 0; i < size && !(flag); i++) {
			for (int j = 0; j < size && !(flag); j++) {

				if ((i + x_pos) < 0 || x_pos < 0) {
					if (pieceNum[i][j] != 0 && bN[0][j + y_pos] != 0) { flag = true; }
				}
				else if ((i + x_pos) > 9 || x_pos > 9) {
					if (pieceNum[i][j] != 0 && bN[9][j + y_pos] != 0) { flag = true; }
				}
				
				if ((j + y_pos) < 0 || y_pos < 0) {
					if (pieceNum[i][j] != 0 && bN[i + x_pos][0] != 0) { flag = true; }
				}
				else if ((j + y_pos) > 19 || y_pos > 19) {
					if (pieceNum[i][j] != 0 && bN[i + x_pos][19] != 0) { flag = true; }
				}

				if (flag == false && (pieceNum[i][j] != 0 && bN[i + x_pos][j + y_pos] != 0)) { flag = true; }

			}
		}

		return flag;

	}
	
	~Tetrimino() {

		for (int i = 0; i < size; i++) {
			delete[] pieceNum[i];
		}

		delete[] pieceNum;

	}

};

class cyanLine : public Tetrimino {

private:

	int colorNum;

public:

	cyanLine() {

		colorNum = 1;
		size = 4;

		for (int i = 0; i < 3; i++) {
			delete[] pieceNum[i];
		}

		pieceNum = new int* [size];
		for (int j = 0; j < size; j++) {
			pieceNum[j] = new int[size];
			for (int k = 0; k < size; k++) {
				pieceNum[j][k] = 0;
			}
		}

		for (int i = 0; i < size; i++) {
			pieceNum[1][i] = colorNum;
		}

	}

};

class blue_revL : public Tetrimino {

private:

	int colorNum;

public:

	blue_revL() {

		colorNum = 2;

		for (int i = 0; i < size; i++) {
			pieceNum[1][i] = colorNum;
		}
		pieceNum[0][2] = colorNum;

	}

};

class orangeL : public Tetrimino {

private:

	int colorNum;

public:

	orangeL() {

		colorNum = 3;

		for (int i = 0; i < 3; i++) {
			pieceNum[1][i] = colorNum;
		}
		pieceNum[2][2] = colorNum;

	}

};

class yellowSquare : public Tetrimino {

private:

	int colorNum;

public:

	yellowSquare() {

		colorNum = 4;
		size = 2;

		for (int i = 0; i < 3; i++) {
			delete[] pieceNum[i];
		}

		pieceNum = new int* [size];
		for (int j = 0; j < size; j++) {
			pieceNum[j] = new int[size];
			for (int k = 0; k < size; k++) {
				pieceNum[j][k] = colorNum;
			}
		}

	}

};

class greenS : public Tetrimino {

private:

	int colorNum;

public:

	greenS() {

		colorNum = 5;

		for (int i = 0; i < 2; i++) {
			pieceNum[i + 1][0] = colorNum;
			pieceNum[i][1] = colorNum;
		}

	}

};

class purpleT : public Tetrimino {

private:

	int colorNum;

public:

	purpleT() {

		colorNum = 6;
		setXnYPos(4, -1);

		for (int i = 0; i < size; i++) {
			pieceNum[i][1] = colorNum;
		}
		pieceNum[1][2] = colorNum;

	}

};

class red_revS : public Tetrimino {

private:

	int colorNum;

public:

	red_revS() {

		colorNum = 7;
		setXnYPos(4, -1);

		for (int i = 0; i < 2; i++) {
			pieceNum[i][1] = colorNum;
			pieceNum[i + 1][2] = colorNum;
		}

	}

};
