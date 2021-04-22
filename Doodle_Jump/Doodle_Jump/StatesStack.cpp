#include "StatesStack.h"

StatesStack::~StatesStack()
{
	while (!stack.empty())
	{
		stack.pop();
	}
}

std::unique_ptr<State>& StatesStack::getCurrent()
{
	return stack.top();
}

void StatesStack::setState(std::unique_ptr<State> newState)
{
	if (!stack.empty())
		stack.pop();
	stack.emplace(std::move(newState));
}

void StatesStack::pop()
{
	if (!stack.empty())
		stack.pop();
}

void StatesStack::push(std::unique_ptr<State> newState)
{
	stack.emplace(std::move(newState));
}


bool StatesStack::isEmpty() const
{
	return stack.empty(); 
}



