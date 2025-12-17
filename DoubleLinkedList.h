#pragma once
#include <iostream>
#include <string>
struct Node
{
	T data;
	Node* prev;
	Node* next;
	Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};
template <typename T>
class DoubleLinkedList
{
private:
	Node<T>* first;
	Node<T>* last;
	size_t size;

public:
	DoubleLinkedList()
	{
		first = nullptr;
		last = nullptr;
		size = 0;
	}
	~DoubleLinkedList()
	{
		clear();
	}
	bool empty() const
	{

		return first == nullptr;
	}

	size_t getSize() const
	{
		return size;
	}
	void push_back(const T& value)
	{

		Node<T>* newNode = new Node<T>(value);


		if (empty())
		{

			first = last = newNode;
		}
		else {

			last->next = newNode;
			newNode->prev = last;
			last = newNode;
		}


		size++;
	}
	void push_front(const T& value)
	{
		Node<T>* newNode = new Node<T>(value);

		if (empty())
		{
			first = last = newNode;
		}
		else
		{
			newNode->next = first;
			first->prev = newNode;
			first = newNode;
		}

		size++;
	}
	void insert(size_t pos, const T& value)
	{

		if (pos > size)
		{
			throw out_of_range("Позиция " + to_string(pos) + " выходит за границы списка");
		}


		if (pos == 0)
		{
			push_front(value);
			return;
		}

		if (pos == size)
		{
			push_back(value);
			return;
		}


		Node<T>* newNode = new Node<T>(value);

		/
			Node<T>*current = first;
		for (size_t i = 0; i < pos - 1; i++)
		{
			current = current->next;
		}


		newNode->prev = current;
		newNode->next = current->next;


		current->next->prev = newNode;
		current->next = newNode;


		size++;
	}
	void pop_back()
	{
		if (empty()) throw out_of_range("...");

		if (first == last)
		{
			delete last;
			first = last = nullptr;
		}
		else
		{
			Node<T>* target = last;
			last = last->prev;
			last->next = nullptr;
			delete target;
		}

		size--;
	}
	void pop_front()
	{
		if (empty()) throw out_of_range("...");

		if (first == last)
		{
			delete first;
			first = last = nullptr;
		}
		else {
			Node<T>* target = first;
			first = first->next;
			first->prev = nullptr;
			delete target;

			size--;
		}
		void erase(size_t pos)
		{
			if (empty()) throw out_of_range("...");
			if (pos >= size) throw out_of_range("...");

			if (pos == 0) { pop_front(); return; }
			if (pos == size - 1) { pop_back(); return; }

			Node<T>* current = first;
			for (size_t i = 0; i < pos; i++)
			{
				current = current->next;
			}

			/
				current->prev->next = current->next;
			current->next->prev = current->prev;

			delete current;
			size--;
		}
		T& at(size_t index)
		{
			if (index >= size) throw out_of_range("...");

			Node<T>* current = first;
			for (size_t i = 0; i < index; i++)
			{
				current = current->next;
			}

			return current->data;
		}
		void clear()
		{
			while (first != nullptr)
			{
				Node<T>* target = first;
				first = first->next;
				delete target;
			}
			last = nullptr;
			size = 0;
		}
		void printForward() const {
			Node<T>* current = first;
			while (current != nullptr) {
				cout << current->data;
				if (current->next != nullptr) cout << " ⇄ ";
				current = current->next;
			}
			cout << " → NULL" << endl;
		}

		void printBackward() const
		{
			Node<T>* current = last;
			while (current != nullptr)
			{
				cout << current->data;
				if (current->prev != nullptr) cout << " ⇄ ";
				current = current->prev;
			}
			cout << " → NULL" << endl;
		}