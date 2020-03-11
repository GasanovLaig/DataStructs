#pragma once
#include "AvlTreeNode.h"
#include <iostream>
#include <string>

template <class T>
class AvlTree
{
public:
	AvlTree() : _root(nullptr)
	{
	}

	~AvlTree() { DestroyTree(_root); }
	void Add(T key) { AddRecursive(_root, key); }
	void Remove(T key) { RemoveRecursive(_root, key); }
	bool Find(T key) { return FindRecursive(_root, key); }
	size_t GetHeight() { return GetNodeHeight(_root); }
	void Print() { PrintRecursive(_root, "", false); }

private:
	void DestroyTree(AvlTreeNode<T>* node);
	void AddRecursive(AvlTreeNode<T>*& node, T key);
	void Balance(AvlTreeNode<T>*& node);
	short GetNodeHeight(AvlTreeNode<T>* node);
	short GetBalanceFactor(AvlTreeNode<T>* node);
	void FixHeight(AvlTreeNode<T>* node);
	void LeftRotate(AvlTreeNode<T>*& node);
	void RightRotate(AvlTreeNode<T>*& node);
	void RemoveRecursive(AvlTreeNode<T>*& node, T key);
	AvlTreeNode<T>* GetSuccessor(AvlTreeNode<T>* node);
	AvlTreeNode<T>* FindMinSuccessor(AvlTreeNode<T>*& node);
	bool FindRecursive(AvlTreeNode<T>* node, T key);
	void PrintRecursive(AvlTreeNode<T>* node, std::string prefix,
		bool isRight);

	AvlTreeNode<T>* _root;
};

template <class T>
inline void AvlTree<T>::DestroyTree(AvlTreeNode<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	DestroyTree(node->Left);
	DestroyTree(node->Right);
	delete node;
}

template <class T>
inline void AvlTree<T>::AddRecursive(AvlTreeNode<T>*& node, T key)
{
	if (node == nullptr)
	{
		node = new AvlTreeNode<T>{ nullptr, nullptr, 1, key };
		return;
	}

	if (key == node->Data)
	{
		return;
	}
	else if (key < node->Data)
	{
		AddRecursive(node->Left, key);
	}
	else
	{
		AddRecursive(node->Right, key);
	}
	Balance(node);
}

template <class T>
inline void AvlTree<T>::Balance(AvlTreeNode<T>*& node)
{
	FixHeight(node);
	if (GetBalanceFactor(node) == -2)
	{
		if (GetBalanceFactor(node->Left) > 0)
		{
			LeftRotate(node->Left);
		}
		RightRotate(node);
	}
	else if (GetBalanceFactor(node) == 2)
	{
		if (GetBalanceFactor(node->Right) < 0)
		{
			RightRotate(node->Right);
		}
		LeftRotate(node);
	}
}

template <class T>
inline short AvlTree<T>::GetNodeHeight(AvlTreeNode<T>* node)
{
	return (node == nullptr) ? 0 : node->Height;
}

template <class T>
inline short AvlTree<T>::GetBalanceFactor(AvlTreeNode<T>* node)
{
	return (GetNodeHeight(node->Right) -
		GetNodeHeight(node->Left));
}

template <class T>
inline void AvlTree<T>::FixHeight(AvlTreeNode<T>* node)
{
	short leftChildHeight = GetNodeHeight(node->Left);
	short rightChildHeight = GetNodeHeight(node->Right);

	node->Height = ((leftChildHeight > rightChildHeight) ?
		leftChildHeight :
		rightChildHeight) + 1;
}

template <class T>
inline void AvlTree<T>::LeftRotate(AvlTreeNode<T>*& node)
{
	AvlTreeNode<T>* rightChild = node->Right;
	node->Right = rightChild->Left;
	rightChild->Left = node;
	node = rightChild;
	FixHeight(node->Left);
	FixHeight(node);
}

template <class T>
inline void AvlTree<T>::RightRotate(AvlTreeNode<T>*& node)
{
	AvlTreeNode<T>* leftChild = node->Left;
	node->Left = leftChild->Right;
	leftChild->Right = node;
	node = leftChild;
	FixHeight(node->Right);
	FixHeight(node);
}

template <class T>
inline void AvlTree<T>::RemoveRecursive(AvlTreeNode<T>*& node, T key)
{
	if (node == nullptr)
	{
		return;
	}

	if (key == node->Data)
	{
		AvlTreeNode<T>* newSuccessor = GetSuccessor(node);
		delete node;
		node = newSuccessor;
		return;
	}
	else if (key < node->Data)
	{
		RemoveRecursive(node->Left, key);
	}
	else
	{
		RemoveRecursive(node->Right, key);
	}
	Balance(node);
}

template <class T>
inline AvlTreeNode<T>* AvlTree<T>::GetSuccessor(AvlTreeNode<T>* node)
{
	AvlTreeNode<T>* newSuccessor = nullptr;
	if (node->Left != nullptr && node->Right != nullptr)
	{
		newSuccessor = FindMinSuccessor(node->Right);
		newSuccessor->Left = node->Left;
		newSuccessor->Right = node->Right;
	}
	else if (node->Left != nullptr)
	{
		newSuccessor = node->Left;
	}
	else if (node->Right != nullptr)
	{
		newSuccessor = node->Right;
	}

	return newSuccessor;
}

template <class T>
inline AvlTreeNode<T>* AvlTree<T>::FindMinSuccessor(AvlTreeNode<T>*& node)
{
	if (node->Left == nullptr)
	{
		AvlTreeNode<T>* findedNode = node;
		node = node->Right;
		return findedNode;
	}
	AvlTreeNode<T>* temporary = FindMinSuccessor(node->Left);
	Balance(node);

	return temporary;
}


template <class T>
inline bool AvlTree<T>::FindRecursive(AvlTreeNode<T>* node, T key)
{
	if (node == nullptr)
	{
		return false;
	}

	if (key == node->Data)
	{
		return true;
	}
	else if (key < node->Data)
	{
		return FindRecursive(node->Left, key);
	}
	else
	{
		return FindRecursive(node->Right, key);
	}
}

template <class T>
inline void AvlTree<T>::PrintRecursive(AvlTreeNode<T>* node,
	std::string prefix, bool isRight)
{
	if (node != nullptr)
	{
		std::cout << prefix;
		std::cout << "|___";
		std::cout << '(' << GetBalanceFactor(node) << ") " <<
			node->Data << '\n';

		PrintRecursive(node->Right,
			prefix + (isRight ? "|\t" : " \t"), true);
		PrintRecursive(node->Left,
			prefix + (isRight ? "|\t" : " \t"), false);
	}
}