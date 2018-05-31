#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

template<typename T>
class CList;

template<typename T>
class CListNode
{
	friend class CList<T>;
public:
	 CListNode(T);
	static T MGetData();
private:
	T _data;
	CListNode* p_nextPtr;
};


#endif // !LIST_NODE_HPP

