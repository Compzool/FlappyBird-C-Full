#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace Flappy
{
	class SplashState : public State //inheritance from State class
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _background;
	};
}
//Splash State:
/*It would be the first screen to show up when the game launches
Logo of a company\ brand...
*/