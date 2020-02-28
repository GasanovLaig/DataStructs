#pragma once
#include <iostream>

enum class Command
{
	Stack,
	DoubleStackQueue,
	RingBuffer,
	Exit
};

std::istream& operator>>(std::istream& inputStream, Command& command)
{
	int value;
	inputStream >> value;
	command = static_cast<Command>(value);

	return inputStream;
}

enum class CommandAsd
{
	Input,
	Output,
	Exit
};

std::istream& operator>>(std::istream& inputStream, CommandAsd& command)
{
	int value;
	inputStream >> value;
	command = static_cast<CommandAsd>(value);

	return inputStream;
}