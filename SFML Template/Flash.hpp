#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Flappy
{
	class Flash
	{
	public:
		Flash(GameDataRef data);
		~Flash();

		void Show(float dt);//showing method
		void Draw();

	private:
		GameDataRef _data;

		sf::RectangleShape _shape;

		bool _flashOn;

	};
}
//Flash:
/*When the game over flash in the screen*/