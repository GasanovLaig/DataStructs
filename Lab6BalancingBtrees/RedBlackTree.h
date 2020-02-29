#pragma once
#include "RedBlackTreeNode.h"
#include <algorithm>
#include <string>

template <class T>
class RedBlackTree
{
public:
	RedBlackTree();
	~RedBlackTree();
	void Add(T key) { AddRecursive(_root, key); }
	void Remove(T key) { RemoveRecursive(_root, key); }
	const RbTreeNode<T>* Find(T key) { return FindRecursive(_root, key); }
	size_t GetHeight() { return GetHeightRecursive(_root); }
	void Print() { PrintRecursive(_root, "", false); }

private:
	void DestroyTree(RbTreeNode<T>* node);
	void AddRecursive(RbTreeNode<T>*& node, T key);
	void Balance(RbTreeNode<T>* node);
	bool IsLeftChild(RbTreeNode<T>* node);
	void Recolor(RbTreeNode<T>* grandParent);
	void LeftRotate(RbTreeNode<T>* node);
	void RightRotate(RbTreeNode<T>* node);
	void SwapColor(RbTreeNode<T>* node1, RbTreeNode<T>* node2);
	RbTreeNode<T>* GetUncle(RbTreeNode<T>* node);
	void RemoveRecursive(RbTreeNode<T>*& node, T key);
	void RemoveNill(RbTreeNode<T>*& node);
	RbTreeNode<T>* GetBrother(RbTreeNode<T>* node);
	RbTreeNode<T>** FindMinSuccessor(RbTreeNode<T>** node);
	RbTreeNode<T>* FindRecursive(RbTreeNode<T>* node, T key);
	size_t GetHeightRecursive(RbTreeNode<T>* node);
	void PrintRecursive(RbTreeNode<T>* node, std::string prefix,
		bool isRight);

	RbTreeNode<T>* _root;
	RbTreeNode<T>* _nil;
};

template <class T>
RedBlackTree<T>::RedBlackTree()
{
	_nil = new RbTreeNode<T>{ nullptr, nullptr, nullptr, true };
	_root = _nil;
}

template <class T>
RedBlackTree<T>::~RedBlackTree()
{
	DestroyTree(_root);
	delete _nil;
}

template <class T>
inline void RedBlackTree<T>::DestroyTree(RbTreeNode<T>* node)
{
	if (node == _nil)
	{
		return;
	}

	DestroyTree(node->Left);
	DestroyTree(node->Right);
	delete node;
}

template <class T>
inline void RedBlackTree<T>::AddRecursive(RbTreeNode<T>*& node, T key)
{
	if (node == _nil)
	{
		node = new RbTreeNode<T>{ _nil, _nil, _nil, false, key };
		return;
	}

	if (key == node->Data)
	{
		return;
	}
	else if (key < node->Data)
	{
		AddRecursive(node->Left, key);
		node->Left->Parent = node;
		Balance(node->Left);
	}
	else
	{
		AddRecursive(node->Right, key);
		node->Right->Parent = node;
		Balance(node->Right);
	}
}

template <class T>
inline void RedBlackTree<T>::Balance(RbTreeNode<T>* node)
{
	if (node->Parent == _nil ||
		node->Parent->Parent == _nil)
	{
		_root->IsBlack = true;
		return;
	}

	if (!node->Parent->IsBlack && !node->IsBlack)
	{
		if (!GetUncle(node)->IsBlack)
		{
			return Recolor(node->Parent->Parent);
		}
		else if (IsLeftChild(node->Parent))
		{
			if (!IsLeftChild(node))
			{
				LeftRotate(node->Parent);
				return RightRotate(node->Parent);
			}
			RightRotate(node->Parent->Parent);
		}
		else
		{
			if (IsLeftChild(node))
			{
				RightRotate(node->Parent);
				return LeftRotate(node->Parent);
			}
			LeftRotate(node->Parent->Parent);
		}
		_root->IsBlack = true;
	}
}

template <class T>
inline bool RedBlackTree<T>::IsLeftChild(RbTreeNode<T>* node)
{
	return (node == node->Parent->Left);
}

template <class T>
inline void RedBlackTree<T>::Recolor(RbTreeNode<T>* grandParent)
{
	grandParent->IsBlack = false;
	grandParent->Left->IsBlack = grandParent->Right->IsBlack = true;
}

template <class T>
inline void RedBlackTree<T>::LeftRotate(RbTreeNode<T>* node)
{
	SwapColor(node, node->Right);
	RbTreeNode<T>* rightChild = node->Right;
	node->Right = rightChild->Left;
	rightChild->Left->Parent = node;
	rightChild->Left = node;
	if (node != _root)
	{
		(IsLeftChild(node)) ?
			node->Parent->Left = rightChild :
			node->Parent->Right = rightChild;
	}
	else
	{
		_root = rightChild;
	}

	rightChild->Parent = node->Parent;
	node->Parent = rightChild;
}

template <class T>
inline void RedBlackTree<T>::RightRotate(RbTreeNode<T>* node)
{
	SwapColor(node, node->Left);
	RbTreeNode<T>* leftChild = node->Left;
	node->Left = leftChild->Right;
	leftChild->Right->Parent = node;
	leftChild->Right = node;
	if (node != _root)
	{
		(IsLeftChild(node)) ?
			node->Parent->Left = leftChild :
			node->Parent->Right = leftChild;
	}
	else
	{
		_root = leftChild;
	}

	leftChild->Parent = node->Parent;
	node->Parent = leftChild;
}

template <class T>
inline void RedBlackTree<T>::SwapColor(RbTreeNode<T>* node1,
	RbTreeNode<T>* node2)
{
	bool color = node1->IsBlack;
	node1->IsBlack = node2->IsBlack;
	node2->IsBlack = color;
}

template <class T>
inline RbTreeNode<T>* RedBlackTree<T>::GetUncle(RbTreeNode<T>* node)
{
	return (node->Parent == node->Parent->Parent->Left) ?
		node->Parent->Parent->Right :
		node->Parent->Parent->Left;
}

template <class T>
inline void RedBlackTree<T>::RemoveRecursive(RbTreeNode<T>*& node, T key)
{
	if (node == _nil)
	{
		return;
	}

	if (key == node->Data)
	{
		RbTreeNode<T>* newSuccessor;
		if (node->Left != _nil && node->Right != _nil)
		{
			RbTreeNode<T>** successor = FindMinSuccessor(&(node->Right));
			node->Data = (*successor)->Data;
			return RemoveRecursive((*successor), (*successor)->Data);
		}
		else if (node->Left != _nil)
		{
			newSuccessor = node->Left;
		}
		else if (node->Right != _nil)
		{
			newSuccessor = node->Right;
		}
		else
		{
			if (node->IsBlack && node != _root)
			{
				return RemoveNill(node);
			}
			delete node;
			node = _nil;
			return;
		}
		newSuccessor->IsBlack = true;
		newSuccessor->Parent = node->Parent;
		delete node;
		node = newSuccessor;
	}
	else if (key < node->Data)
	{
		RemoveRecursive(node->Left, key);
	}
	else
	{
		RemoveRecursive(node->Right, key);
	}
}

template <class T>
inline RbTreeNode<T>** RedBlackTree<T>::FindMinSuccessor(RbTreeNode<T>** node)
{
	RbTreeNode<T>** current = node;
	while ((*current)->Left != _nil)
	{
		current = &((*current)->Left);
	}

	return current;
}

template <class T>
inline void RedBlackTree<T>::RemoveNill(RbTreeNode<T>*& node)
{
	RbTreeNode<T>* brother = GetBrother(node);
	delete node;
	node = _nil;
	if (!brother->IsBlack)
	{
		RbTreeNode<T>* brotherParent = brother->Parent;
		if (IsLeftChild(brother))
		{
			brother = brother->Right;
			RightRotate(brotherParent);
		}
		else
		{
			brother = brother->Left;
			LeftRotate(brotherParent);
		}
	}
	if (brother->Left->IsBlack && brother->Right->IsBlack)
	{
		brother->IsBlack = false;
		brother->Parent->IsBlack = true;
		return;
	}
	if (brother->Right->IsBlack && !brother->Left->IsBlack)
	{
		RightRotate(brother);
		brother = brother->Parent;
	}
	if (!brother->Right->IsBlack)
	{
		brother->Right->IsBlack = true;
		if (IsLeftChild(brother))
		{
			LeftRotate(brother);
			return RightRotate(brother->Parent->Parent);
		}
		LeftRotate(brother->Parent);
	}
}

template <class T>
inline RbTreeNode<T>* RedBlackTree<T>::GetBrother(RbTreeNode<T>* node)
{
	return (node == node->Parent->Left) ?
		node->Parent->Right :
		node->Parent->Left;
}

template <class T>
inline RbTreeNode<T>* RedBlackTree<T>::FindRecursive(RbTreeNode<T>* node,
	T key)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (key == node->Data)
	{
		return node;
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
inline size_t RedBlackTree<T>::GetHeightRecursive(RbTreeNode<T>* node)
{
	if (node == _nil)
	{
		return 0;
	}

	return std::max(GetHeightRecursive(node->Left),
		GetHeightRecursive(node->Right)) + 1;
}

template <class T>
void RedBlackTree<T>::PrintRecursive(RbTreeNode<T>* node,
	std::string prefix, bool isRight)
{
	if (node != _nil)
	{
		std::cout << prefix;
		std::cout << "|___";
		std::cout << (node->IsBlack ? "Черный " : "Красный ")
			<< node->Data << '\n';

		PrintRecursive(node->Right,
			prefix + (isRight ? "|\t" : " \t"), true);
		PrintRecursive(node->Left,
			prefix + (isRight ? "|\t" : " \t"), false);
	}
}