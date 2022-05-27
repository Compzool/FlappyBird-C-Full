#include "Game.hpp"
#include "DEFINITIONS.hpp"

int main()
{//window that the user will see
			//		width		height			name of the screen
	Flappy::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");

	return EXIT_SUCCESS;
}
//NAME SPACE:
/*Flappy is a namespace,a namespace is designed to overcome this difficulty and is used
as additional information to differentiate 
similar functions, classes, variables etc.
with the same name available in different libraries. 
Using namespace, you can define the context in which names are defined.
In essence, a namespace defines a scope*/ 
