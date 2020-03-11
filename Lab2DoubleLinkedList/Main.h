#pragma once
#include "List.h"
#include "Check.h"
#include "Print.h"

#include <iostream>
#include <exception>
#include "../Common/GetValue.h"
using namespace std;

enum class Command
{
	AddValue,
	DeleteValue,
	InsertInBegin,
	InsertInEnd,
	InsertAfter,
	InsertBefore,
	Sort,
	LinearSearch,
	Exit
};

std::istream& operator>>(std::istream& inputStream, Command& command)
{
	int value;
	inputStream >> value;
	command = static_cast<Command>(value);

	return inputStream;
}