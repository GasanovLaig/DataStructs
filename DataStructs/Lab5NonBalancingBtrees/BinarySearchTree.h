#pragma once
#include "BinaryTreeNode.h"
#include <iostream>
#include <string>

template <class T>
class BinaryTree
{
public:
	~BinaryTree();
	void Add(T data) { AddRecursive(_root, data); }
	void Remove(T data) { RemoveRecursive(_root, data); }
	const BstNode<T>* Find(T data) { return FindRecursive(_root, data); }
	const BstNode<T>* FindMin() { return FindMinRecursive(_root); }
	const BstNode<T>* FindMax() { return FindMaxRecursive(_root); }
	void Print() { PrintRecursive(_root, "", false); }

private:
	void DestroyTree(BstNode<T>* current);
	void AddRecursive(BstNode<T>*& current, T data);
	void RemoveRecursive(BstNode<T>*& current, T data);
	const BstNode<T>* FindRecursive(BstNode<T>* current, T data);
	BstNode<T>*& FindMinRecursive(BstNode<T>*& current);
	BstNode<T>*& FindMaxRecursive(BstNode<T>*& current);
	void PrintRecursive(BstNode<T>* current, std::string prefix,
		bool isRight);

	BstNode<T>* _root;
};

template <class T>
BinaryTree<T>::~BinaryTree()
{
	DestroyTree(_root);
	_root = nullptr;
}

template <class T>
void BinaryTree<T>::DestroyTree(BstNode<T>* current)
{
	if (current == nullptr)
	{
		return;
	}

	DestroyTree(current->Left);
	DestroyTree(current->Right);
	delete current;
}

template <class T>
void BinaryTree<T>::AddRecursive(BstNode<T>*& current, T data)
{
	if (current == nullptr)
	{
		current = new BstNode<T>{ nullptr, nullptr, data };
		return;
	}
	
	if (data == current->Data)
	{
		return;
	}
	else if (data < current->Data)
	{
		AddRecursive(current->Left, data);
	}
	else
	{
		AddRecursive(current->Right, data);
	}
}

template <class T>
void BinaryTree<T>::RemoveRecursive(BstNode<T>*& current, T data)
{
	if (current == nullptr)
	{
		return;
	}
	
	if (data == current->Data)
	{
		BstNode<T>* newSuccessor = nullptr;
		if (current->Left != nullptr && current->Right != nullptr)
		{
			BstNode<T>*& successor = FindMinRecursive(current->Right);
			current->Data = successor->Data;
			RemoveRecursive(successor, successor->Data);
			return;
		}
		else if (current->Left != nullptr)
		{
			newSuccessor = current->Left;
		}
		else if (current->Right != nullptr)
		{
			newSuccessor = current->Right;
		}
		delete current;
		current = newSuccessor;
	}
	else if (data < current->Data)
	{
		RemoveRecursive(current->Left, data);
	}
	else
	{
		RemoveRecursive(current->Right, data);
	}
}

template <class T>
const BstNode<T>* BinaryTree<T>::FindRecursive(BstNode<T>* current, T data)
{
	if (current == nullptr)
	{
		return nullptr;
	}
	
	if (data == current->Data)
	{
		return current;
	}
	else if (data < current->Data)
	{
		return FindRecursive(current->Left, data);
	}
	else
	{
		return FindRecursive(current->Right, data);
	}
}

template <class T>
BstNode<T>*& BinaryTree<T>::FindMinRecursive(BstNode<T>*& current)
{
	if (current->Left == nullptr)
	{
		return current;
	}
	return FindMinRecursive(current->Left);
}

template <class T>
BstNode<T>*& BinaryTree<T>::FindMaxRecursive(BstNode<T>*& current)
{
	if (current->Right != nullptr)
	{
		return current;
	}
	return FindMaxRecursive(current->Left);
}

template <class T>
void BinaryTree<T>::PrintRecursive(BstNode<T>* current,
	std::string prefix, bool isRight)
{
	if (current != nullptr)
	{
		std::cout << prefix;
		std::cout << "|_____";
		std::cout << current->Data << '\n';

		PrintRecursive(current->Right,
			prefix + (isRight ? "|     " : "     "), true);
		PrintRecursive(current->Left,
			prefix + (isRight ? "|     " : "     "), false);
	}
}