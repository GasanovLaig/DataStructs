#pragma once
#include "../Lab3/StructNode.h"
#include "StructPair.h"
#include <vector>

class List
{
public:
	~List();
	void Add(Node<Pair>* node);
	size_t Remove(const std::string& key);
	std::vector<const Pair*> Find(const std::string& key);

	Node<Pair>* GetHead() { return _head; }
	void SetHeadNull() { _head = nullptr; }

private:
	Node<Pair>* _head;
};