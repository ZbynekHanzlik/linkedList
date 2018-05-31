#ifndef TREE_NODE_HPP
#define TREE_NODE_HPP

template<typename T>
class CTree;

template<typename T>
class CTreeNode
{
	friend class CTree<T>;
public:
	 CTreeNode(T);
	static T MGetData();

private:
	T _data;
	CTreeNode* p_leftPtr;
	CTreeNode* p_rightPtr;
};

#endif // !TREE_NODE_HPP
