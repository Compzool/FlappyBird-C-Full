#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Flappy
{
	class HUD
	{
	public:
		HUD(GameDataRef data);
		~HUD();

		void Draw();
		void UpdateScore(int score);

	private:
		GameDataRef _data;

		sf::Text _scoreText;

	};
}
//HUD:
//Display the score on the screen.