#include <iostream>
using namespace std;
#include"List.hpp"
template class CList<short>;
template class CList<short int>;
template class CList<signed short>;
template class CList<signed short int>;
template class CList<unsigned short>;
template class CList<unsigned short int>;
template class CList<int>;
template class CList<signed>;
template class CList<signed int>;
template class CList<unsigned>;
template class CList<unsigned int>;
template class CList<long>;
template class CList<long int>;
template class CList<signed long>;
template class CList<signed long int>;
template class CList<unsigned long>;
template class CList<unsigned long int>;
template class CList<long long>;
template class CList<long long int>;
template class CList<signed long long>;
template class CList<signed long long int>;
template class CList<unsigned long long>;
template class CList<unsigned long long int>;
template class CList<size_t>;
template class CList<float>;
template class CList<double>;
template class CList<long double>;

template class CListNode<short>;
template class CListNode<short int>;
template class CListNode<signed short>;
template class CListNode<signed short int>;
template class CListNode<unsigned short>;
template class CListNode<unsigned short int>;
template class CListNode<int>;
template class CListNode<signed>;
template class CListNode<signed int>;
template class CListNode<unsigned>;
template class CListNode<unsigned int>;
template class CListNode<long>;
template class CListNode<long int>;
template class CListNode<signed long>;
template class CListNode<signed long int>;
template class CListNode<unsigned long>;
template class CListNode<unsigned long int>;
template class CListNode<long long>;
template class CListNode<long long int>;
template class CListNode<signed long long>;
template class CListNode<signed long long int>;
template class CListNode<unsigned long long>;
template class CListNode<unsigned long long int>;
template class CListNode<size_t>;
template class CListNode<float>;
template class CListNode<double>;
template class CListNode<long double>;

template class CTreeNode<short>;
template class CTreeNode<short int>;
template class CTreeNode<signed short>;
template class CTreeNode<signed short int>;
template class CTreeNode<unsigned short>;
template class CTreeNode<unsigned short int>;
template class CTreeNode<int>;
template class CTreeNode<signed>;
template class CTreeNode<signed int>;
template class CTreeNode<unsigned>;
template class CTreeNode<unsigned int>;
template class CTreeNode<long>;
template class CTreeNode<long int>;
template class CTreeNode<signed long>;
template class CTreeNode<signed long int>;
template class CTreeNode<unsigned long>;
template class CTreeNode<unsigned long int>;
template class CTreeNode<long long>;
template class CTreeNode<long long int>;
template class CTreeNode<signed long long>;
template class CTreeNode<signed long long int>;
template class CTreeNode<unsigned long long>;
template class CTreeNode<unsigned long long int>;
template class CTreeNode<size_t>;
template class CTreeNode<float>;
template class CTreeNode<double>;
template class CTreeNode<long double>;

template class CTree<short>;
template class CTree<short int>;
template class CTree<signed short>;
template class CTree<signed short int>;
template class CTree<unsigned short>;
template class CTree<unsigned short int>;
template class CTree<int>;
template class CTree<signed>;
template class CTree<signed int>;
template class CTree<unsigned>;
template class CTree<unsigned int>;
template class CTree<long>;
template class CTree<long int>;
template class CTree<signed long>;
template class CTree<signed long int>;
template class CTree<unsigned long>;
template class CTree<unsigned long int>;
template class CTree<long long>;
template class CTree<long long int>;
template class CTree<signed long long>;
template class CTree<signed long long int>;
template class CTree<unsigned long long>;
template class CTree<unsigned long long int>;
template class CTree<size_t>;
template class CTree<float>;
template class CTree<double>;
template class CTree<long double>;

template<typename T>
CList<T>::CList()
{
	p_StartPtr =	nullptr;
	p_EndPtr   =	nullptr;
}

template<typename T>
CList<T>::~CList()
{
	if (!MIsEmpty())
	{
		CListNode<T>* p_currentPtr = p_StartPtr;
		CListNode<T>* p_tempPtr;

		while (p_currentPtr != 0)
		{
			p_tempPtr = p_currentPtr;
			p_currentPtr = p_currentPtr->p_nextPtr;
			delete p_tempPtr;
		}
	}
}
template<typename T>
void CList<T>::MInsertNewNode(T dataIn)
{
	if (MIsEmpty())
	{
		MInsertBegin(dataIn);
	}
	else
	{
		if (dataIn < p_StartPtr->_data)
		{
			MInsertBegin(dataIn);
		}
		else if(dataIn >= p_EndPtr->_data)
		{
			MInsertEnd(dataIn);
		}
		else
		{
			CListNode<T>* p_currentPtr = p_StartPtr;
			CListNode<T>* p_newPtr = new CListNode<T>(dataIn);
			while (p_currentPtr != p_EndPtr)
			{
				if ((p_newPtr->_data < p_currentPtr->p_nextPtr->_data) && (p_newPtr->_data >= p_currentPtr->_data))
				{
					CListNode<T>* p_next = p_currentPtr->p_nextPtr;
					p_currentPtr->p_nextPtr = p_next;
					break;
				}
				p_currentPtr = p_currentPtr->p_nextPtr;
			}
		}
	}
}

template<typename T>
void CList<T>::MPrint()
{
	if(MIsEmpty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		CListNode<T>* p_currentPtr = p_StartPtr;
		cout << "The contents of the list is: ";
		while (p_currentPtr != nullptr)
		{
			cout << p_currentPtr->_data << ' ';
			p_currentPtr = p_currentPtr->p_nextPtr;
		}
		cout << endl;
	}
}

template<typename T>
CListNode<T>* CList<T>::MSearch(T key)
{
	CListNode<T>* p_nodePtr;
	bool b_found = false;

	p_nodePtr = p_StartPtr;

	while ((!b_found) && (p_nodePtr != nullptr))
	{
		if (p_nodePtr->_data == key)
		{
			b_found = true;
		}
		else
		{
			p_nodePtr = p_nodePtr->p_nextPtr;
		}
	}
	return p_nodePtr;
}

template<typename T>
bool CList<T>::MIsEmpty()
{
	if (p_StartPtr == nullptr && p_EndPtr == nullptr)
		return true;
	else
	return false;
}

template<typename T>
void CList<T>::MInsertBegin(T dataIn)
{
	if (!MIsEmpty())
	{
		CListNode<T>* p_newPtr = new CListNode<T>(dataIn);
		p_StartPtr = p_newPtr;
		p_EndPtr = p_newPtr;
	}
	else
	{
		CListNode<T>* p_newPtr = new CListNode<T>(dataIn);
		p_newPtr->p_nextPtr = p_StartPtr;
		p_StartPtr = p_newPtr;
	}
}

template<typename T>
void CList<T>::MInsertEnd(T dataIn)
{
	if (!MIsEmpty())
	{
		CListNode<T>* p_newPtr = new CListNode<T>(dataIn);
		p_StartPtr = p_newPtr;
		p_EndPtr = p_newPtr;
	}
	else
	{
		CListNode<T>* p_newPtr = new CListNode<T>(dataIn);
		p_EndPtr->p_nextPtr = p_newPtr;
		p_EndPtr = p_newPtr;
	}
}

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


template <typename T>
CTree<T>::CTree()
{
	p_rootPtr = 0;
}

template <typename T>
void CTree<T>::MInsertNewNode(T dataIn)
{
	MInsertNewNodeUtility(&p_rootPtr, dataIn); //calls insert new node function passing refernce of the root node and the data to be inserted in the new node
}

template <typename T>
void CTree<T>::MInsertNewNodeUtility(CTreeNode<T>** temp, T dataIn)
{
	if (*temp == 0) //if node is null create a new node with input data
		*temp = new CTreeNode<T>(dataIn);
	else
	{
		if (dataIn < (*temp)->_data) //if input data is less than data in current node
			MInsertNewNodeUtility(&((*temp)->p_leftPtr), dataIn); //recursive function call with current node's left child as input leaf
		else
		{
			if (dataIn >(*temp)->_data) //if input data is greater than data in current node
				MInsertNewNodeUtility(&((*temp)->p_rightPtr), dataIn); //recursive function call with current node's right child as input leaf
			else {}//if input data is equal to data in current node
				 cout << dataIn << " is a duplicate value " << endl; //duplicate values ignored
		}
	}
}

template <typename T>
void CTree<T>::MPreOrderPrint()
{
	MPreOrderPrintUtility(p_rootPtr);
}

template <typename T>
void CTree<T>::MPreOrderPrintUtility(CTreeNode<T>* temp)
{
	if (temp != 0)
	{
		cout << temp->_data << ' '; //process node
		MPreOrderPrintUtility(temp->p_leftPtr); //recursive traversal of left subCTree
		MPreOrderPrintUtility(temp->p_rightPtr); //recursive traversal of right subCTree
	}
}


template <typename T>
void CTree<T>::MInOrderPrint()
{
	MInOrderPrintUtility(p_rootPtr);
}

template <typename T>
void CTree<T>::MInOrderPrintUtility(CTreeNode<T>* temp)
{
	if (temp != 0)
	{
		MInOrderPrintUtility(temp->p_leftPtr); //recursive traversal of left subCTree
		cout << temp->_data << ' ';									   //cout << temp->data << ' '; //process node
		MInOrderPrintUtility(temp->p_rightPtr); //recursive traversal of right subCTree
	}
}


template <typename T>
void CTree<T>::MPostOrderPrint()
{
	MPostOrderPrintUtility(p_rootPtr);
}

template <typename T>
void CTree<T>::MPostOrderPrintUtility(CTreeNode<T>* temp)
{
	if (temp != 0)
	{
		MPostOrderPrintUtility(temp->p_leftPtr); //recursive traversal of left subCTree
		MPostOrderPrintUtility(temp->p_rightPtr); //recursive traversal of right subCTree
		cout << temp->_data << ' ';										  //cout << temp->data << ' '; //process node
	}
}

template <typename T>
CTreeNode<T>* CTree<T>::Mp_search(T key)
{
	return MSearchUtility(p_rootPtr, key);
}

template <typename T>
CTreeNode<T>* CTree<T>::MSearchUtility(CTreeNode<T>* leaf, T key)
{
	if (leaf != 0)
	{
		if (key == leaf->_data)
			return leaf;
		if (key < leaf->_data)
			return MSearchUtility(leaf->p_leftPtr, key);
		else
			return MSearchUtility(leaf->p_rightPtr, key);
	}
	else
		return 0;
}

template<typename T>
inline CTreeNode<T>::CTreeNode(T dataIn)
{
	_data = dataIn;
	p_leftPtr = 0;
	p_rightPtr = 0;
}

template<typename T>
inline T CTreeNode<T>::MGetData()
{
	return _data;
}
