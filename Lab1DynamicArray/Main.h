#pragma once
#include "DynamicArray.h"

#include <iostream>
#include "../myLib/GetValue.h"
using namespace std;

enum class Command
{
	DeleteValue,
	InsertInBegin,
	InsertInEnd,
	InsertAfter,
	Sort,
	LinearSearch,
	BinarySearch,
	Exit
};

std::istream& operator>>(std::istream& inputStream, Command& command)
{
	int value;
	inputStream >> value;
	command = static_cast<Command>(value);

	return inputStream;
}