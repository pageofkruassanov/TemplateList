#pragma once
#include "includes.h"
namespace MyList {
	template <typename T>
	struct Node {
		T obj;

		Node* m_next;

		Node(const T obj);
	};

	template<typename T>
	Node<T>::Node(const T obj)
	{
		this->obj = obj;
		m_next = nullptr;
	}
}
