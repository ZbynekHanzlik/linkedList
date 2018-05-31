#ifndef TREE_HPP
#define TREE_HPP

#include "TreeNode.hpp"


template<typename T>
class CTree
{
public:
	 CTree();
	static void MInsertNewNode(T);
	static void MPreOrderPrint();
	static void MInOrderPrint();
	static void MPostOrderPrint();
	static CTreeNode<T>* Mp_search(T);
private:
	CTreeNode<T>* p_rootPtr;
	//bool Mb_IsEmtpy();

	void MInsertNewNodeUtility(CTreeNode<T>**, T);
	void MPreOrderPrintUtility(CTreeNode<T>*);
	void MInOrderPrintUtility(CTreeNode<T>*);
	void MPostOrderPrintUtility(CTreeNode<T>*);
	CTreeNode<T>* MSearchUtility(CTreeNode<T>*, T);
	
};

#endif // !TREE_HPP
