#pragma once

#include "SFML\Graphics.hpp"

namespace Flappy
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}
		//we pass the actual sprite we want to det - what mouse button we are detecting, it maybe right click, it maybe left click - render window is the window that these items and events are on.
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

		//return a reference to the mouse postion - detects where the mouse is positioned on the window
		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}
//InputManager:
/* Will handle all our input needs
For example we'll provide a feature to be able to handle a sprite click{ block of events }	
So if we click on a sprite we'll be able to detect when that has occurred will we are to get the most position as well really easily.
Anything related to input you can throw it in this class.
*/