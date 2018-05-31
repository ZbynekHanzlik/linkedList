#include "TreeNode.hpp"


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
