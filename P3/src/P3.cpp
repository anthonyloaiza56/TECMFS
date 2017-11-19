//============================================================================
// Name        : P3.cpp
// Author      : Tony
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
int main()
{
	sf::RenderWindow window(sf::VideoMode(500,500), "TECMFS");
	sf::RectangleShape rectangle(sf::Vector2f(200, 50)); //boton 1
	sf::RectangleShape rectangle2(sf::Vector2f(200, 50)); //boton 2
	sf::RectangleShape rectangle3(sf::Vector2f(200, 50)); //boton 3
	sf::Font font;
	if (!font.loadFromFile("Stonehen.ttf"))
	{
		// error...
	}
	rectangle.setFillColor(sf::Color::Green);
	rectangle.setPosition(150,200);
	rectangle2.setFillColor(sf::Color::Green);
	rectangle2.setPosition(150,310);
	rectangle3.setFillColor(sf::Color::Green);
	rectangle3.setPosition(150,420);

	sf::Text text;
	text.setFont(font);
	text.setString("1.Index Folder");
	text.setCharacterSize(32);
	text.setColor(sf::Color::White);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(150,200);

	sf::Text text3;
	text3.setFont(font);
	text3.setString("2.Load Video");
	text3.setCharacterSize(32);
	text3.setColor(sf::Color::White);
	text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text3.setPosition(150,310);

	sf::Text text2;
	text2.setFont(font);
	text2.setString("3.Play Video");
	text2.setCharacterSize(32);
	text2.setColor(sf::Color::White);
	text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text2.setPosition(150,420);

	static bool pressed=false;
	sf::Vector2i position;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed){
				position = sf::Mouse::getPosition(window);

				if(150<position.x and position.x<350 and 200<position.y and position.y<250){
					cout<<"Index Folder \n"; //aqui podria poner la funcion respectiva de indexar folder
					pressed=true;
					continue;
				}
				if(150<position.x and position.x<350 and 310<position.y and position.y<360){
					cout<<"Load Video\n";//aqui podria poner la funcion respectiva de cargar video
					pressed=true;
					continue;
				}
				if(150<position.x and position.x<350 and 420<position.y and position.y<470){
					cout<<"Play Video \n";//aqui podria poner la funcion respectiva de reproducir video
					pressed=true;
					continue;
				}

			}
		}  else {
			pressed=false;
		}

        window.clear();
        window.draw(rectangle);
        window.draw(rectangle2);
        window.draw(rectangle3);
        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.display();
    }

    return 0;
}
