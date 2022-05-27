#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include <vector>

namespace Flappy
{
	class Pipe
	{
	public:
		Pipe(GameDataRef data);

		void SpawnBottomPipe();
		void SpawnTopPipe();
		void SpawnInvisiblePipe();
		void SpawnScoringPipe();//spawn pipes till game is over
		void MovePipes(float dt);
		void DrawPipes();
		void RandomisePipeOffset();

		const std::vector<sf::Sprite> &GetSprites() const;
		std::vector<sf::Sprite> &GetScoringSprites();

	private:
		GameDataRef _data;
		std::vector<sf::Sprite> pipeSprites;
		std::vector<sf::Sprite> scoringPipes;

		int _landHeight;
		int _pipeSpawnYOffset;

	};
}
//Pipe:
/* Obsticale pipes that our flappy bird wil be avoiding
-one pipe facing up.
-one pipe facing down.
*/

//Vector:
/*C++ has a vector class within the std namespace.
A vector is similar to an array, in a sense where a series of elements are stored 
with the same variable name.
Unlike arrays, vectors are dynamically sized,
which is a major advantage.*/
