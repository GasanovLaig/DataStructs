#pragma once
#include "TreapNode.h"
#include <algorithm>

template <class T>
class Treap
{
public:
	~Treap();
	void AddNonOptimized(T key);
	void AddOptimized(T key) { AddRecursive(_root, key, GetPriority()); }
	void RemoveNonOptimized(T);
	void RemoveOptimized(T key) { RemoveRecursive(_root, key); }
	bool Find(T key) { return FindRecursive(_root, key); }
	size_t GetHeight() { return GetHeightRecursive(_root); }
	void Print() { PrintRecursive(_root, "", false); }

private:
	void DestroyTreap(TreapNode<T>* current);
	void Split(TreapNode<T>* current, T key, TreapNode<T>*& left,
		TreapNode<T>*& right);
	TreapNode<T>* Merge(TreapNode<T>* left, TreapNode<T>* right);
	void AddRecursive(TreapNode<T>*& current, T key, T priority);
	void RemoveRecursive(TreapNode<T>*& current, T key);
	bool FindRecursive(TreapNode<T>* current, T key);
	size_t GetHeightRecursive(TreapNode<T>* current);
	void PrintRecursive(TreapNode<T>* current, std::string prefix,
		bool isRight);

	T GetPriority() { return rand(); }

	TreapNode<T>* _root;
};

template <class T>
Treap<T>::~Treap()
{
	DestroyTreap(_root);
	_root = nullptr;
}

template <class T>
inline void Treap<T>::DestroyTreap(TreapNode<T>* current)
{
	if (current == nullptr)
	{
		return;
	}

	DestroyTreap(current->Left);
	DestroyTreap(current->Right);
	delete current;
}

template <class T>
inline void Treap<T>::Split(TreapNode<T>* current,
 T key,	TreapNode<T>*& left, TreapNode<T>*& right)
{
	if (current == nullptr)
	{
		left = right = nullptr;
		return;
	}

	if (key < current->Key)
	{
		Split(current->Left, key, left, current->Left);
		right = current;
	}
	else
	{
		Split(current->Right, key, current->Right, right);
		left = current;
	}
}

template <class T>
inline TreapNode<T>* Treap<T>::Merge(TreapNode<T>* left,
	TreapNode<T>* right)
{
	if (left == nullptr)
	{
		return right;
	}
	if (right == nullptr)
	{
		return left;
	}

	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	else
	{
		right->Left = Merge(left, right->Left);
		return right;
	}
}

template <class T>
inline void Treap<T>::AddNonOptimized(T key)
{
	TreapNode<T>* left;
	TreapNode<T>* right;
	Split(_root, key, left, right);
	TreapNode<T>* newTree = new TreapNode<T>{ nullptr, nullptr, key,
		GetPriority() };
	_root = Merge(Merge(left, newTree), right);
}

template <class T>
inline void Treap<T>::AddRecursive(TreapNode<T>*& current,
 T key,	T priority)
{
	if (current == nullptr)
	{
		current = new TreapNode<T>{ nullptr, nullptr, key, GetPriority() };
		return;
	}
	
	if (priority >= current->Priority)
	{
		TreapNode<T>* left;
		TreapNode<T>* right;
		Split(current, key, left, right);
		TreapNode<T>* newTree = new TreapNode<T>{ left, right,
			key, priority };
		current = newTree;
	}
	else if (key < current->Key)
	{
		AddRecursive(current->Left, key, priority);
	}
	else
	{
		AddRecursive(current->Right, key, priority);
	}
}

template <class T>
inline void Treap<T>::RemoveNonOptimized(T key)
{
	TreapNode<T>* left;
	TreapNode<T>* right;
	Split(_root, key, left, right);
	TreapNode<T>* destroyedTree;
	Split(left, key - 1, left, destroyedTree);

	if (destroyedTree == nullptr)
	{
		return;
	}
	DestroyTreap(destroyedTree);
	_root = Merge(left, right);
}

template <class T>
inline void Treap<T>::RemoveRecursive(TreapNode<T>*& current, T key)
{
	if (current == nullptr)
	{
		return;
	}
	
	if (key == current->Key)
	{
		TreapNode<T>* destroyedNode = current;
		current = Merge(current->Left, current->Right);
		delete destroyedNode;
	}
	else if (key < current->Key)
	{
		RemoveRecursive(current->Left, key);
	}
	else
	{
		RemoveRecursive(current->Right, key);
	}
}

template <class T>
inline bool Treap<T>::FindRecursive(TreapNode<T>* current, T key)
{
	if (current == nullptr)
	{
		return false;
	}

	if (key == current->Key)
	{
		return true;
	}
	else if (key < current->Key)
	{
		return FindRecursive(current->Left, key);
	}
	else
	{
		return FindRecursive(current->Right, key);
	}
}

template <class T>
inline size_t Treap<T>::GetHeightRecursive(TreapNode<T>* current)
{
	if (current == nullptr)
	{
		return 0;
	}

	return std::max(GetHeightRecursive(current->Left),
		GetHeightRecursive(current->Right)) + 1;
}

template <class T>
inline void Treap<T>::PrintRecursive(TreapNode<T>* current,
	std::string prefix, bool isLeft)
{
	if (current != nullptr)
	{
		std::cout << prefix;
		std::cout << "|_______";
		std::cout << current->Key << "; " << current->Priority << "\n|";

		PrintRecursive(current->Right,
			prefix + (isLeft ? "|\t    " : "\t    "), true);
		PrintRecursive(current->Left,
			prefix + (isLeft ? "|\t    " : "\t    "), false);
	}
}