#include "Tree.hpp"

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
			if (dataIn >(*temp)->data) //if input data is greater than data in current node
				MInsertNewNodeUtility(&((*temp)->p_rightPtr), dataIn); //recursive function call with current node's right child as input leaf
			else //if input data is equal to data in current node
				//cout << dataIn << " is a duplicate value " << endl; //duplicate values ignored
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
		//cout << temp->data << ' '; //process node
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
		//cout << temp->data << ' '; //process node
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
		//cout << temp->data << ' '; //process node
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
	if (leaf != nullptr)
	{
		if (key == leaf->_data)
			return leaf;
		if (key < leaf->_data)
			return MSearchUtility(leaf->p_leftPtr, key);
		else
			return MSearchUtility(leaf->p_rightPtr, key);
	}
	else
		return nullptr;
}