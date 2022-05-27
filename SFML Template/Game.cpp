#include "Game.hpp"
#include "SplashState.hpp"

#include <stdlib.h>
#include <time.h>


namespace Flappy
{
	Game::Game(int width, int height, std::string title)
	{
		srand(time(NULL));

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		_data->machine.AddState(StateRef(new SplashState(this->_data)));

		this->Run();
	}

	void Game::Run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		//Frames and Changes of the game.
		while (this->_data->window.isOpen())
		{
			this->_data->machine.ProcessStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;//handling frames

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;//restricting it so it doesn't get too high
			}

			currentTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt)
			{
				this->_data->machine.GetActiveState()->HandleInput();
				this->_data->machine.GetActiveState()->Update(dt);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;//constructing the frame points within range
			this->_data->machine.GetActiveState()->Draw(interpolation);//pacing of the game
		}
	}
}