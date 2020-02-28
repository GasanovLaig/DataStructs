#pragma once
#include "HashTable.h"

class Dictionary
{
public:
	void Add(const Pair& pairs);
	std::vector<const Pair*> Find(const std::string& key);

	void Remove(const std::string& key) { return _table.Remove(key); }
	void Print() { return _table.Print(); }
	size_t GetSize() { return _table.GetSize(); }
	size_t GetMaxSize() { return _table.GetMaxSize(); }

private:
	HashTable _table;
};