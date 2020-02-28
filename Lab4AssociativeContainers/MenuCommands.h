#pragma once
#include <iostream>

enum class CommandMenu
{
	HashTable,
	Dictionary,
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
	AddPair,
	RemovePair,
	FindPairs,
	AddRandomPairs,
	Exit
};

std::istream& operator>>(std::istream& inputStream, Command& command)
{
	int value;
	inputStream >> value;
	command = static_cast<Command>(value);

	return inputStream;
}