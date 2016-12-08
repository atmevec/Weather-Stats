/*Author: Alexander Mevec
Description: This program will allow a user to enter as many months
of weather statistics as they would like then displays the months
and the max/min values out of all the months for rain, snow, and sun.
*/

#pragma once

//Template class similar to the std lib version

template <class T>
class ListNode
{
public:
	ListNode(T nodeValue);
	ListNode<T>* next;
	T value;

};

template<class T>
inline ListNode<T>::ListNode(T nodeValue)
{
	value = nodeValue;
	next = nullptr;
}