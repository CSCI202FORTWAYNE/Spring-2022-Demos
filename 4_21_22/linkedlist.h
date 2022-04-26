#ifndef LINKED_H
#define LINKED_H
#include "linkedListIterator.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <class Type>
class linkedListType
{
public:
	const linkedListType<Type>& operator=(const linkedListType<Type>&);
	void initializeList();
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList();
	Type front() const;
	Type back() const;
	virtual bool search(const Type& searchItem) const = 0;
	virtual void insertFirst(const Type& newItem) = 0;
	virtual void insertLast(const Type& newItem) = 0;
	virtual void deleteNode(const Type& deleteItem) = 0;
	linkedListIterator<Type> begin();
	linkedListIterator<Type> end();
	linkedListType();
	linkedListType(const linkedListType<Type> &otherList);
	~linkedListType();
	
protected:
	int count;
	nodeType<Type> * first;
	nodeType<Type> * last;
private: 
	void copyList(const linkedListType<Type>& otherList);
};

template<class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return (first == nullptr);
}

template<class Type>
linkedListType<Type>::linkedListType()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

template<class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type> * temp;
	while(first != nullptr)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = nullptr;
	count = 0;
}

template<class Type>
void linkedListType<Type>::initializeList()
{
	destroyList();
}

template<class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type> * current;
	current = first;
	while(current != nullptr)
	{
		cout << *(current->info) << " ";
		current = current->link;
	}
}

template <class Type>
int linkedListType<Type>::length() const
{
	return count;
}

template <class Type>
Type linkedListType<Type>::front() const
{
	if(this->isEmptyList())
		throw out_of_range("Cannot get first item of an empty list");
	return *(first->info);
}

template <class Type>
Type linkedListType<Type>::back() const
{
	if(this->isEmptyList())
		throw out_of_range("Cannot get last item of an empty list");
		return *(last->info);
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
	linkedListIterator<Type> temp(first);
	return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
	linkedListIterator<Type> temp(nullptr);
	return temp;
}

template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
	nodeType<Type> *newNode;
	nodeType<Type> *current;
	
	if(!this->isEmptyList())
		destroyList();
		
	if(otherList.first == nullptr)
	{
		first = nullptr;
		last = nullptr;
		count = 0;
	} 
	else
	{
		current = otherList.first;
		count = otherList.count;
		first = new nodeType<Type>;
		first->info = new Type(*(current->info));
		first->link = nullptr;
		last = first;
		current = current->link;
		while(current != nullptr)
		{
			newNode = new nodeType<Type>;
			newNode->info = new Type(*(current->info));
			newNode->link = nullptr;
			last->link = newNode;
			last = newNode;
			
			current = current->link;
		}
	}
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
	destroyList();
}



template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
	first = nullptr;
	copyList(otherList);
}

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
	if(this != &otherList)
	{
		copyList(otherList);
	}
	return *this;
}



































































































































































#endif