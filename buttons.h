#pragma once
#include "tetriminoClass.h"
#include <SFML/Graphics.hpp>

class PlayButton {

private:
	float width;
	float height;
	sf::RectangleShape buttonRect;
	sf::Text playText;

public:

	float x_pos;
	float y_pos;

	PlayButton(sf::Font f) {

		width = 200.f;
		height = 100.f;
		x_pos = 275.f;
		y_pos = 510.f;

		buttonRect.setSize(sf::Vector2f(width, height));
		buttonRect.setPosition(sf::Vector2f(x_pos, y_pos));
		buttonRect.setOutlineThickness(5.f);
		buttonRect.setFillColor(sf::Color(255, 0, 255));
		buttonRect.setOutlineColor(sf::Color(200, 0, 200));

		playText.setString("Play");
		playText.setFont(f);
		playText.setCharacterSize(54);
		playText.setPosition(sf::Vector2f(x_pos, y_pos));
		playText.setFillColor(sf::Color::White);

	}

	float otherX() {
		return (width + x_pos);
	}

	float otherY() {
		return (height + y_pos);
	}

	void draw(sf::RenderWindow& window) {

		window.draw(buttonRect);
		window.draw(playText);

	}

	bool pressedIt() { return true; }

};