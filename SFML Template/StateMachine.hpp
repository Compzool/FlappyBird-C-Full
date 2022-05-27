#pragma once//include guard

#include <memory>//dealing with memory
#include <stack>

#include "State.hpp"

namespace Flappy
{
	typedef std::unique_ptr<State> StateRef;//StateRef is now a smart pointer of type State

	class StateMachine//handles all our states
	{
	public:
		StateMachine() { }
		~StateMachine() { }
	 //is replacing: replace the old state with the current state, pop the old one and add the new one instead of just adding it on top of the old one becuase there is no persistance to still have the old one running, so if you want the old state you can just create it again and do the same thing.				
		void AddState(StateRef newState, bool isReplacing = true);//adding a state on the stack
		void RemoveState();//manually remove the state
		// Run at start of each loop in Game.cpp
		void ProcessStateChanges();//runs when every state is running

		StateRef &GetActiveState();// returns a refrence to the top level state such as handling input, updating...

	private:
		std::stack<StateRef> _states;// all the states present on our stack
		StateRef _newState;//latest state to add

		bool _isRemoving;
		bool _isAdding, _isReplacing;
	};
}
//State Machine:
/*You have states in your game and these can be states such as the main menu state 
the game state, the game overstate.
Like the players died and you could have like a splash screen state
say you would show off say your logo your company's logo any or intro video that sort of stuff.*/

//Stack:
/*The State machine would be based on a stack
- the top state would be running and it can be poped off
so for example suppose that pause the top state, you can pop it off and return to the game scene.*/

//Smart Pointers:
/* new keyword is used to allocate memory on the heap
delete keyword is used to free the allocated memory from the heap because it wouldn't be free automatically.
- now smart pointers are used to automate that process meaning that when you call new you don't have to call delete
and in many cases you don't have to call new
a smart pointer is essentially a wrapper around a real pointer and when you create it, it will call new and allocate your memory for you
and it will be automatically free at some point.
-unique_ptr:
-it is a scoped pointer so when it goes out of scope it will call delete and get destroyed.
-similar to objects on how they get destroyed by the destructor when it goes out of scope.
-you can't copy a unique pointer because both pointers would then be pointing at the same block of memory 
so when one of them dies the allocated memory would be deleted thus the other pointer would be pointing to nothing, so basically unique is only for itself
*/