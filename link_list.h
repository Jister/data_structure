#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

enum StatusCode{
	SUCCESS = 0,
	ENTRY_FOUND,
	RANGE_ERROR
};

template <class T>
struct Node
{
	T data;
	Node<T> *next;

	Node();
	Node(T item, Node<T> * link = nullptr);
};

template <class T>
class SimpleLinkList
{
protected:
	Node<T> * head;
	Node<T> * GetElemPtr(int position) const;  //return the ptr of postion-th node
	void Init();

public:
	SimpleLinkList();
	virtual ~SimpleLinkList();
	int Length() const;
	bool Empty() const;
	void Clear();
	void Traverse();
	StatusCode GetElem(int position, T& e) const;
	StatusCode SetElem(int position, const T& e);
	StatusCode Insert(int position, const T& e);
	StatusCode Delete(int position, T& e);
	SimpleLinkList(const SimpleLinkList<T>& copy);
	SimpleLinkList<T> &operator= (const SimpleLinkList<T>& copy);
	
};

#endif