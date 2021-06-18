#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>
#include <time.h>

int values[100];
sf::RectangleShape* rectangles[100];

int main() {
	
	for (int i = 0; i < 100; i++) {
		/* generate secret number 0 to 500: */
		values[i] = rand() % 500;
	}
	
	sf::RenderWindow window(sf::VideoMode(1000, 500), "Bubble_Sort");
	window.setFramerateLimit(30);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(sf::Color::Color(12, 12, 12));
		//-------Swapping-------
		for (int i = 0; i < 99; i++) {
			if (values[i] > values[i + 1]) {
				int temp = values[i];
				values[i] = values[i + 1];
				values[i + 1] = temp;
			}
		}

		for (int i = 0; i < 100; i++) {
			rectangles[i] = new sf::RectangleShape(sf::Vector2f(8, values[i]));
			rectangles[i]->setFillColor(sf::Color::Red);
			rectangles[i]->setPosition(sf::Vector2f(1 + 10 * i, 500 - values[i]));
			rectangles[i]->setSize(sf::Vector2f(8, values[i]));
			window.draw(*rectangles[i]);
		}

		window.display();
	}

	delete[] rectangles;

	return 0;
}
