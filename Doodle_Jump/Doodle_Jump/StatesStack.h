#ifndef STATESSTACK_H
#define STATESSTACK_H

#include <memory>
#include <stack>
#include "State.h"

/** @class StatesStack
 *	The heart of the game
 */
class StatesStack
{
public:
	enum class Type { TITLE_STATE, MENU_STATE, GAME_STATE, CUSTOMIZE_STATE, GAME_OVER_STATE, PAUSE_STATE};
	/**
	 * \brief Constructor of StatesStack class
	 */
	StatesStack() = default;
	
	/**
	 * \brief Destructor of StatesStack class
	 */
	~StatesStack();

	/**
	 * \brief States stack don't know what state he is currently holding so this function is an obligatory part of it.
	 *		  The operation of the entire game loop placed in run() function is based on this function.
	 * \return  The current game state
	 */
	std::unique_ptr<State>& getCurrent();
	
	/**
	 * \brief Put the next state on top of the state stack but before that
	 *		  it removes the state from which it is currently executing.
	 * \param newState New state to put on the top of the stack.
	 */
	void setState(std::unique_ptr<State> newState);
	
	/**
	 * \brief Pops the current state from the stack.
	 */
	void pop();

	/**
	 * \brief Add the new state on top of the stack without deleting the current state.
	 * \param newState New state to put on the top of the stack.
	 */
	void push(std::unique_ptr<State> newState);
	
	/**
	 * \brief Checks if the stack is empty.
	 * \return True or false depending on state condition.
	 */
	bool isEmpty() const;


	template <typename T, typename... Args>
	void setState( std::shared_ptr<EssentialData>data, Args... args);
	
	
private:
	std::stack<std::unique_ptr<State>> stack;			///< Game stack holding current game state.
};
#endif

template <typename T, typename... Args>
void StatesStack::setState(std::shared_ptr<EssentialData> data, Args... args)
{
	if (!stack.empty())
		stack.pop();
	
	stack.emplace(new T(data, args...));
}
