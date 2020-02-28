#pragma once
#include <iostream>

enum class CommandMenu
{
	AvlTree,
	RedBlackTree,
	Testing,
	Exit
};

std::istream& operator>>(std::istream& inputStream, CommandMenu& command)
{
	int value;
	inputStream >> value;
	command = static_cast<CommandMenu>(value);

	return inputStream;
}

enum class Command
{
	AddRandomValues,
	AddValue,
	RemoveValue,
	FindValue,
	Exit
};

std::istream& operator>>(std::istream& inputStream, Command& command)
{
	int value;
	inputStream >> value;
	command = static_cast<Command>(value);

	return inputStream;
}