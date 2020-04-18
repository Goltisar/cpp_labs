#pragma once
#include <unordered_map>
#include <cassert>

using namespace std;

template<typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void push_back(T data);
	void deleteDuplicates();
	void pop_front();
	T getElementFromEnd(const int k) const;
	int getSize() const { return size; }
	T& operator[](const int index) const;

private:
	template<typename T>
	class Node
	{
	public:
		T data;
		Node *pNext;
		Node(T data = T())
		{
			this->data = data;
			this->pNext = nullptr;
		}
	};
	
	Node<T> *head;
	int size;
};

template<typename T>
LinkedList<T>::LinkedList()
{
	size = 0;
	head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	while (size)
		pop_front();
}

template<typename T>
void LinkedList<T>::push_back(T data)
{
	if (head == nullptr)
		head = new Node<T>(data);
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
			current = current->pNext;
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<typename T>
void LinkedList<T>::deleteDuplicates()
{
	Node<T>* previous = nullptr;
	Node<T>* current = this->head;
	unordered_map<T, int> map;
	while (current != nullptr) {
		if (map.find(current->data) != map.end())
		{
			map[current->data]++;
			previous->pNext = current->pNext;
			current = current->pNext;
			size--;
		}
		else 
		{
			map[current->data] = 1;
			previous = current;
			current = current->pNext;
		}
	}
}

template<typename T>
void LinkedList<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
T& LinkedList<T>::operator[](const int index) const
{
	assert(index >= 0 && index < size);
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
			return current->data;
		current = current->pNext;
		counter++;
	}
}

template<typename T>
T LinkedList<T>::getElementFromEnd(const int k) const
{
	//start from 1
	assert(size - k >= 0 && size - k < size);
	return this->operator[](size - k);
}