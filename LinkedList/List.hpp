#ifndef LIST_HPP
#define LIST_HPP

//
//#include "listNode.hpp"

template<typename T>
class CList;
template<typename T>
class CTree;

template<typename T>
class CListNode
{
	friend class CList<T>;
public:
	CListNode(T);
	 T MGetData();
private:
	T _data;
	CListNode* p_nextPtr;
};

template<typename T>
class CList
{
public:
	 CList();
	 ~CList();
	 void MInsertNewNode(T dataIn);
	 void MPrint();
	 CListNode<T>* MSearch(T key);
private:
	CListNode<T>* p_StartPtr;
	CListNode<T>* p_EndPtr;
	bool MIsEmpty();
	void MInsertBegin(T dataIn);
	void MInsertEnd(T dataIn);
};


template<typename T>
class CTreeNode
{
	friend class CTree<T>;
public:
	CTreeNode(T);
	 T MGetData();

private:
	T _data;
	CTreeNode* p_leftPtr;
	CTreeNode* p_rightPtr;
};


template<typename T>
class CTree
{
public:
	CTree();
	 void MInsertNewNode(T);
	 void MPreOrderPrint();
	 void MInOrderPrint();
	 void MPostOrderPrint();
	 CTreeNode<T>* Mp_search(T);
private:
	CTreeNode<T>* p_rootPtr;
	//bool Mb_IsEmtpy();

	void MInsertNewNodeUtility(CTreeNode<T>**, T);
	void MPreOrderPrintUtility(CTreeNode<T>*);
	void MInOrderPrintUtility(CTreeNode<T>*);
	void MPostOrderPrintUtility(CTreeNode<T>*);
	CTreeNode<T>* MSearchUtility(CTreeNode<T>*, T);

};

#endif // !LIST_HPP

