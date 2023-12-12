#include <SFML/Graphics.hpp>
using namespace sf;
void circle(Shape& shape) {
	shape.setPosition(shape.getPosition().x + 0.01, shape.getPosition().y + 0.01);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Lesson 2. kychka-pc.ru");
	window.setFramerateLimit(30);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);
	int x = 0, y = 0;
	while (window.isOpen())
	{
		sf::Event event;
		if (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		circle(shape);
		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}