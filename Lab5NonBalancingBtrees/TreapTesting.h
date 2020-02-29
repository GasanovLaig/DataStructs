#pragma once
#include "Treap.h"
#include "../myLib/Timer.h"

template <typename U>
void Test(Treap<U> &treap, void (Treap<U>::*TestingFunction)(U data),
	size_t elementCount)
{
	Timer time;
	for (size_t i = 0; i < elementCount; ++i)
	{
		(treap.*TestingFunction)(static_cast<short>(i));
	}
}

void Testing(size_t elementCount)
{
	Treap<short> treap;
	std::cout << "Т№хьџ эхюяђшьшчш№ютрээющ тёђртъш: ";
	Test(treap, &Treap<short>::AddNonOptimized, elementCount);
	std::cout << " (тћёюђр фх№хтр = " << treap.GetHeight() << ")\n";

	std::cout << "\nТ№хьџ эхюяђшьшчш№ютрээюую ѓфрыхэшџ фюсртыхээћѕ §ыхьхэђют: ";
	Test(treap, &Treap<short>::RemoveNonOptimized, elementCount);

	std::cout << "Т№хьџ юяђшьшчш№ютрээющ тёђртъш: ";
	Test(treap, &Treap<short>::AddOptimized, elementCount);
	std::cout << " (тћёюђр фх№хтр = " << treap.GetHeight() << ")\n";

	std::cout << "\nТ№хьџ юяђшьшчш№ютрээюую ѓфрыхэшџ фюсртыхээћѕ §ыхьхэђют: ";
	Test(treap, &Treap<short>::RemoveOptimized, elementCount);
}