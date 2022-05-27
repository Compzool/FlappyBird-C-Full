#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"

namespace Flappy
{
	struct GameData //accessed by all
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;//GameDataRef is now a shared pointer of type GameData

	class Game
	{
	public:
		Game(int width, int height, std::string title);//width and height and name of our screen

	private:
		// Updates run at 60 per second.
		const float dt = 1.0f / 60.0f;//frame rate aka how many updates per second so in this case it is 60 times
		sf::Clock _clock;//required for handling the frame rate

		GameDataRef _data = std::make_shared<GameData>();//GameDataRef instance - we use this to access all of the pieces of game data that are found in the struct above

		void Run();//runs the game
	};
}//Game Loop:
/* It is going to handle.
Basically our scenes, everything it will just going to bring all of our components together so the state machine
and any other sort of asset managers or any sort of managers that we've created will be bought to be back in the game loop.
*/

//shared_ptr:
/* Lets you copy a smart pointer.
-It works by refrence counting which keeps track of the count of how many refrences you have to your pointer
and as soon as that count reached zero, that is when it gets deleted.
-allocates a control block to store the refrence count.

*/