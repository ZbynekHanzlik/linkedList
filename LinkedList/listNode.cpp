#include "listNode.hpp"
template <typename T>
CListNode<T>::CListNode(T dataIn)
{
	_data = dataIn; //stores data in node
	p_nextPtr = 0; //initializes point to next node to null
}

template <typename T>
T CListNode<T>::MGetData() //returns data stored in node
{
	return _data;
}