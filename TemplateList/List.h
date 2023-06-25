#pragma once
#include "Node.h"

template<typename T>
class List {
	Node<T>* m_head;

	unsigned int m_size;
public:
	List(const T obj);
	void AddToHead(const T obj);
	void AddToTail(const T obj);
	void DeleteFromHead();
	void DeleteFromTail();
	void DeleteAll();
	void Show();
	Node<T>* FindNode(unsigned int pos);
	void InsertNode(unsigned int pos, const T el);
	void RemoveNode(unsigned int pos);
	int ChangeNode(const T from, const T to);
	void ReverseList();
};

template<typename T>
List<T>::List(const T obj)
{
	m_head = new Node<T>(obj);
	m_size = 1;
}

template<typename T>
void List<T>::AddToHead(const T obj)
{
	Node<T>* newNode = new Node<T>(obj);
	if (m_head == nullptr) {
		m_head = newNode;
		++m_size;
	}
	else {
		newNode->m_next = m_head;
		m_head = newNode;
		++m_size;
	}
}

template<typename T>
void List<T>::AddToTail(const T obj)
{
	Node<T>* newNode = new Node<T>(obj);
	if (m_head == nullptr) {
		m_head = newNode;
		++m_size;
	}
	else {
		Node<T>* tempNode = m_head;
		while (tempNode->m_next != nullptr) {
			tempNode = tempNode->m_next;
		}
		tempNode->m_next = newNode;
		++m_size;
	}
}

template<typename T>
void List<T>::DeleteFromHead()
{
	if (m_head == nullptr)
		return;

	Node<T>* tempNode = m_head->m_next;
	delete m_head;
	m_head = tempNode;
	--m_size;
}

template<typename T>
void List<T>::DeleteFromTail()
{
	Node<T>* tempNode = m_head;
	int tempSize = 1;
	while (tempSize < m_size - 1) {
		tempNode = tempNode->m_next;
		++tempSize;
	}
	delete (tempNode->m_next);
	tempNode->m_next = nullptr;
	--m_size;
}

template<typename T>
void List<T>::DeleteAll()
{
	if (m_head == nullptr)
		return;

	Node<T>* tempNode = m_head;

	if (tempNode->m_next == nullptr) {
		delete tempNode;
		m_head = nullptr;
		--m_size;
		return;
	}

	tempNode = tempNode->m_next;
	while (tempNode->m_next != nullptr) {
		delete m_head->m_next;
		m_head->m_next = tempNode;
		tempNode = tempNode->m_next;
	}
	delete m_head;
	m_head = nullptr;
	m_size = 0;
}

template<typename T>
void List<T>::Show()
{
	if (m_head == nullptr)
		return;

	Node<T>* tempNode = m_head;
	for (int i = 0; i < m_size; i++) {
		std::cout << i + 1 << " element: " << tempNode->obj << std::endl;
		tempNode = tempNode->m_next;
	}
}

template<typename T> // need test for pos (in for pos or pos - 1)
Node<T>* List<T>::FindNode(unsigned int pos)
{
	if (pos < 1 || pos > m_size)
		return nullptr;
	Node<T>* tempNode = m_head;
	for (int i = 1; i < pos; i++) {
		tempNode = tempNode->m_next;
	}
	return tempNode;
}

template<typename T>
void List<T>::InsertNode(unsigned int pos, const T el)
{
	Node<T>* newNode = new Node<T>(el);
	if (pos < 1 || pos > m_size + 1)
		return;
	else if (pos == 1) {
		this->AddToHead(el);
	}
	else if (pos == m_size + 1) {
		this->AddToTail(el);
	}
	else {
		newNode->m_next = FindNode(pos);
		FindNode(pos - 1)->m_next = newNode;
		++m_size;
	}
}

template<typename T>
void List<T>::RemoveNode(unsigned int pos)
{
	if (pos < 1 || pos > m_size)
		return;
	else if (pos == 1) {
		this->DeleteFromHead();
		return;
	}
	else if (pos == m_size) {
		this->DeleteFromTail();
		return;
	}
	Node<T>* tempNode = this->FindNode(pos);
	FindNode(pos - 1)->m_next = tempNode->m_next;
	delete tempNode;
	--m_size;
}

template<typename T>
int List<T>::ChangeNode(const T from, const T to)
{
	int amount = -1;
	Node<T>* tempNode = m_head;
	for (int i = 0; i < m_size; i++) {
		if (tempNode->obj == from) {
			tempNode->obj = to;
			++amount;
		}
		tempNode = tempNode->m_next;
	}
	if (amount != -1)
		++amount;
	return amount;
}

template<typename T>
void List<T>::ReverseList()
{
	if (this->m_size <= 1)
		return;
	Node<T>* tempNode = this->FindNode(m_size);
	for (int i = m_size; i > 1; --i) {
		this->FindNode(i)->m_next = this->FindNode(i - 1);
	}
	m_head = tempNode;
	this->FindNode(m_size)->m_next = nullptr;

}
