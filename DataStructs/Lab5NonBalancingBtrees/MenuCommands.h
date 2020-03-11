#pragma once
#include <iostream>

enum class CommandMenu
{
	BinarySearchTree,
	Treap,
	Exit
};

std::istream& operator>>(std::istream& inputStream, CommandMenu& command)
{
	int value;
	inputStream >> value;
	command = static_cast<CommandMenu>(value);

	return inputStream;
}

enum class TreapCommand
{
	AddRandomValues,
	AddValueNonOptimized,
	AddValueOptimized,
	RemoveValueNonOptimized,
	RemoveValueOptimized,
	FindValue,
	Testing,
	Exit
};

std::istream& operator>>(std::istream& inputStream, TreapCommand& command)
{
	int value;
	inputStream >> value;
	command = static_cast<TreapCommand>(value);

	return inputStream;
}

enum class BstCommand
{
	AddValue,
	AddRandomValues,
	RemoveValue,
	FindValue,
	FindMin,
	FindMax,
	Exit
};

std::istream& operator>>(std::istream& inputStream, BstCommand& command)
{
	int value;
	inputStream >> value;
	command = static_cast<BstCommand>(value);

	return inputStream;
}