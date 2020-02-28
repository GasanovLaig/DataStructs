#pragma once
#include "List.h"

class HashTable
{
public:
	HashTable();
	~HashTable();
	void Add(const Pair& pair);
	void Remove(const std::string& key);
	std::vector<const Pair*> Find(const std::string& key);
	void Print();

	size_t GetSize() { return _size; }
	size_t GetMaxSize() { return _maxSize; }

private:
	size_t Hash(const std::string&);
	void Resize();
	void Rehashing(List** newArray, size_t oldMaxSize);

	float GetGrowthFactor() { return 1.5; }
	size_t _size;
	size_t _maxSize;
	List** _lists;
};