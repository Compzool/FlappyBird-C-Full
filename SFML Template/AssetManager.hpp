#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace Flappy
{
	class AssetManager
	{
	public:
		AssetManager() { }
		~AssetManager() { }
		//			   name for later use - actual file itself including the path       
		void LoadTexture(std::string name, std::string fileName);//loads a specified texture

		sf::Texture &GetTexture(std::string name);//returns a reference to the texture using the name of the texture supplied by the above method.

		//Same as above but for loading FONTS
		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);

	private:
		//maps that are storing our textures and fonts
		//         key  -   mapped value -  map name
		std::map<std::string, sf::Texture> _textures;//_textures{{name,Texture} , {x,y} , {x,y} ,...};
		std::map<std::string, sf::Font> _fonts;
	};
}
//AssetManager:
/* Allow us to load assets such as textures and fonts that we can easily reuse later in our game.
It comes in handy when it loads a background once in a state for example and we need to use it in five different states.
We can just use it without loading it five different times and take up more memory.
Imagine if you had a game screen you had a hundred different enemies on there but they all had the same
texture but then you could just use this asset manager and just load the image once.
But to use it multiple times.*/

//DLL:
/*DLL Stands for "Dynamic Link Library." A DLL (.dll) file contains a library of functions
and other information that can be accessed by a
Windows program. When a program is launched, links to the necessary .dll files are created.
If a static link is created, the .dll files will be in use as long as the program is active.
If a dynamic link is created, the .dll files will only be used when needed.
Dynamic links help programs use resources, such as memory and hard drive space, more efficiently.*/

//Maps:
/* Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.
In a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this key.
The mapped values in a map can be accessed directly by their corresponding key using the bracket operator ((operator[]).
*/