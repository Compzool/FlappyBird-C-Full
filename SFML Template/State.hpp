#pragma once

namespace Flappy
{
	class State
	{
	public:
					//initializing state
		virtual void Init() = 0;
					//every sequance related to a state
		virtual void HandleInput() = 0;//pure virtual methods
		virtual void Update(float dt) = 0;
		virtual void Draw(float dt) = 0;

		virtual void Pause() { }
		virtual void Resume() { }
	};
}
//Polymorphism:
/* using the same function and having multiple outcomes.
-virtual for overriding methods of the base class in the sub class.
-just put virtual key word before the method in the base class.
-you can use the label override to indicate that this method is overridden, it helps in detecting if you had a spelling error of a method of the base class.
-pure virtual function is a method definition with virtual keyword and is initialized to 0.
-pure virtual function also has to be implemented in a sub class if you want to be able to instantiate that class. */

//DT:
/*Time delta.
That's just the time difference between frames.
This just allows us to create frame independent gameplay by factoring in the frame rate.
You don't want less if you have a device that can run your game at 60 fps.
You don't want it to run twice as fast as the one that can run it at 30 fps.
Second you want it to be smooth or you want the actual pacing to be the same.*/