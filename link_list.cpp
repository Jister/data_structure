#include "link_list.h"
#include <iostream>
using namespace std;

template<class T>
Node<T>::Node()
{
	next = nullptr;
}

template<class T>
Node<T>::Node(T item, Node<T> * link)
{
	data = item;
	next = link;
}

template<class T>
Node<T> * SimpleLinkList<T>::GetElemPtr(int position) const
{
	Node<T> * tempPtr = head;
	int curPosition = 0;

	while(tempPtr != nullptr && curPosition < position)
	{
		tempPtr = tempPtr->next;
		curPosition++;
	}

	if(tempPtr != nullptr && curPosition == position)
	{
		return tempPtr;
	}else
	{
		return nullptr;
	}
}

template<class T>
void SimpleLinkList<T>::Init()
{
	head = new Node<T>;
}

//constructor
template<class T>
SimpleLinkList<T>::SimpleLinkList()
{
	Init();
}

template<class T>
SimpleLinkList<T>::~SimpleLinkList()
{
	Clear();
	delete head;
}

template<class T>
int SimpleLinkList<T>::Length() const
{
	int count = 0;
	for(Node<T> * tempPtr = head->next; tempPtr != nullptr; tempPtr = tempPtr->next)
	{
		count++;
	}
	return count;
}

template<class T>
bool SimpleLinkList<T>::Empty() const
{
	return head->next == nullptr;
}

template<class T>
void SimpleLinkList<T>::Clear()
{
	T tmpElem;
	while(Length()>0)
	{
		Delete(1, tmpElem);
	}
}

template<class T>
void SimpleLinkList<T>::Traverse()
{

}

template<class T>
StatusCode SimpleLinkList<T>::GetElem(int position, T& e) const
{
	if(position < 1 || position > Length())
	{
		cout << "RANGE_ERROR" << endl;
		return RANGE_ERROR;
	}else
	{
		Node<T> * tempPtr;
		tempPtr = GetElemPtr(position);
		e = tempPtr->data;
		return ENTRY_FOUND;
	}
}

template<class T>
StatusCode SimpleLinkList<T>::SetElem(int position, const T& e)
{
	if(position < 1 || position > Length())
	{
		cout << "RANGE_ERROR" << endl;
		return RANGE_ERROR;
	}else
	{
		Node<T> * tempPtr;
		tempPtr = GetElemPtr(position);
		tempPtr->data = e;
		return SUCCESS;
	}
}

template<class T>
StatusCode SimpleLinkList<T>::Insert(int position, const T& e)
{
	if(position < 1 || position > Length()+1)
	{
		cout << "RANGE_ERROR" << endl;
		return RANGE_ERROR;
	}else
	{
		Node<T> * tempPtr;
		tempPtr = GetElemPtr(position-1);
		Node<T> * newPtr;
		newPtr = new Node<T>(e, tempPtr->next);
		tempPtr->next = newPtr;
		return SUCCESS;
	}
}

template<class T>
StatusCode SimpleLinkList<T>::Delete(int position, T& e)
{
	if(position < 1 || position > Length())
	{
		cout << "RANGE_ERROR" << endl;
		return RANGE_ERROR;
	}else
	{
		Node<T> * tempPtr;
		tempPtr = GetElemPtr(position-1);
		Node<T> * nextPtr = tempPtr->next;
		tempPtr->next = nextPtr->next;
		e = nextPtr->data;
		delete nextPtr;
		return SUCCESS;
	}
}

template<class T>
SimpleLinkList<T>::SimpleLinkList(const SimpleLinkList<T>& copy)
{

}

template<class T>
SimpleLinkList<T>& SimpleLinkList<T>::operator= (const SimpleLinkList<T>& copy)
{

}



int main()
{
	SimpleLinkList<int> a;
	for(int i = 0; i < 10; i++)
	{
		a.Insert(i+1,i);
	}
	cout << "size: " << a.Length() << endl;
	int temp;
	a.Delete(5,temp);
	for(int i = 0; i < a.Length(); i++)
	{
		int n;
		a.GetElem(i+1, n);
		cout << "data: " << n << endl;
	}
	return 0;  
}
