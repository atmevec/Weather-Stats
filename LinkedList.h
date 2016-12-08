/*Author: Alexander Mevec
Description: This program will allow a user to enter as many months
of weather statistics as they would like then displays the months
and the max/min values out of all the months for rain, snow, and sun.
*/

#pragma once
#include "ListNode.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

//Template class similar to the std lib version

template<class T>
class LinkedList
{
public:
	LinkedList();
	void ClearList();
	~LinkedList();

	void AppendNode(T value);
	void InsertNode(T value);
	void DeleteNode(T value);
	T GetNode(int value);
	void DisplayList() const;
private:
	ListNode<T>* head;
};

template<class T>
inline LinkedList<T>::LinkedList()
{
	head = nullptr;
}

template<class T>
inline void LinkedList<T>::ClearList()
{
	ListNode<T>* nodePtr = nullptr;
	ListNode<T>* nextNode = nullptr;

	nodePtr = head;

	while (nodePtr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	head = nullptr;
}

template<class T>
inline LinkedList<T>::~LinkedList()
{
	ClearList();
}

template<class T>
inline void LinkedList<T>::AppendNode(T value)
{
	ListNode<T>* nodePtr = nullptr;
	ListNode<T>* newNode = nullptr;

	newNode = new ListNode<T>(value);

	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		nodePtr->next = newNode;
	}
}

template<class T>
inline void LinkedList<T>::InsertNode(T value)
{
	ListNode<T>* nodePtr = nullptr;
	ListNode<T>* prevNode = nullptr;
	ListNode<T>* newNode = new ListNode<T>(value);

	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;

		while (nodePtr != NULL && nodePtr->value < value)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (prevNode == NULL)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			prevNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

template<class T>
inline void LinkedList<T>::DeleteNode(T value)
{
	ListNode<T>* nodePtr = nullptr;
	ListNode<T>* prevNode = nullptr;

	if (!head)
		return;

	if (head->value == value)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;

		while (nodePtr != NULL && nodePtr->value != value)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			prevNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

template<class T>
inline T LinkedList<T>::GetNode(int value)
{
	ListNode<T>* nodePtr = nullptr;
	nodePtr = head;
	for (int i = 0; i < value; i++)
	{
		nodePtr = nodePtr->next;
	}
	return nodePtr->value;
}

template<class T>
inline void LinkedList<T>::DisplayList() const
{
	ListNode<T>* nodePtr = head;

	while (nodePtr)
	{
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
}
