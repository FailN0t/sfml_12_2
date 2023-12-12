#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
void circle(Shape& shape) {
	shape.setPosition(shape.getPosition().x + 4, shape.getPosition().y + 4);
}
void circleMgnum(CircleShape& shape, CircleShape& shape2, RenderWindow& window) {
	if (shape.getPosition().x <= 0) {
		shape2.setPosition((float)window.getSize().x + shape.getPosition().x, shape2.getPosition().y);
		if (shape.getPosition().x < (1 - (float)window.getSize().x)) {
			shape.setPosition(0, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y <= 0) {
		shape2.setPosition(shape2.getPosition().x, (float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y < (1 - (float)window.getSize().y)) {
			shape.setPosition(shape.getPosition().x, 0);
		}
	}
	if (shape.getPosition().x + shape.getRadius() * 2 >= window.getSize().x) {
		shape2.setPosition(-(float)window.getSize().x + shape.getPosition().x, shape2.getPosition().y);
		if (shape.getPosition().x + shape.getRadius() * 2 - (float)window.getSize().x > window.getSize().x) {
			shape.setPosition(-shape.getRadius() * 2, shape.getPosition().y);
		}
	}
	if (shape.getPosition().y + shape.getRadius() * 2 >= window.getSize().y) {
		shape2.setPosition(shape2.getPosition().x, -(float)window.getSize().y + shape.getPosition().y);
		if (shape.getPosition().y + shape.getRadius() * 2 - (float)window.getSize().x > window.getSize().y) {
			shape.setPosition(shape.getPosition().x, -shape.getRadius() * 2);
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Lesson 2. kychka-pc.ru");
	window.setFramerateLimit(30);
	sf::CircleShape shape(100.f);
	
	//shape.setFillColor(sf::Color::Red);

	Texture textureFont;
	textureFont.loadFromFile("res/font.jpg");
	RectangleShape recShape(Vector2f(window.getSize()));
	recShape.setTexture(&textureFont);


	Texture textureCircle;
	textureCircle.loadFromFile("res/circle.jpg");
	shape.setTexture(&textureCircle);
	CircleShape shape2;
	shape2 = shape;
	shape2.setPosition((Vector2f)window.getSize());
	int x = 0, y = 0;
	while (window.isOpen())
	{
		sf::Event event;
		if (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		circleMgnum(shape, shape2, window);
		circle(shape);
		window.clear();
		window.draw(recShape);
		window.draw(shape);
		window.draw(shape2);
		window.display();
	}

	return 0;
}