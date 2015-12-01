#include <iostream>
#include <string>

using namespace std;


template <class dataNode, typename datatype>
class BST
{
private:
	dataNode *root = nullptr;
	//int height = 0;
	int field = 0;

public:

	BST();

	BST(int sortField);

	~BST();

	void sortLargest();

	void sortSmallest();

	int insert(dataNode *currNode);

	void remove(dataNode *currNode);

	void in_Order(datanode *currNode);

	void post_Order(dataNode *currNode);

	//void breadth_Order(dataNode *currNode);

	bool isEmpty();

	void postTraversal();

	//void breadthTraversal();

	//friend ostream& operator<<(ostream &stream, const dataNode &obj);
};

template <class dataNode, typename datatype>
inline BST<dataNode, datatype>::BST()
{
	
}

template <class dataNode, typename datatype>
inline BST<dataNode, datatype>::BST(int theField)
{
	//set the field being sorted by
	field = theField;
}

template <class dataNode, typename datatype>
inline BST<dataNode, datatype>::~BST()
{

}

template <class dataNode, typename datatype>
inline int BST<dataNode, datatype>::insert(dataNode *currNode)
{
	//if there is no root, make currNode the root
	if (root == nullptr)
	{
		root = new dataNode;
		root = currNode;
		return 0;
	}

	//create a temporary pointer and set it to root
	dataNode *nodePtr= new dataNode;
	nodePtr = root;	
	
	while (nodePtr)
	{
		//compare the pointer's data with the data being inserted
		datatype temp1 = nodePtr->getField(field);
		datatype temp2 = currNode->getField(field);
		int cmp = currNode->compareData(nodePtr, currNode, field);

		//if nodePtr is bigger
		if (cmp > 0)
		{
			if (nodePtr->left == nullptr)
			{
				nodePtr->left = currNode;
				currNode->parent = nodePtr;
				return 0;
			}
			else
			{
				nodePtr = nodePtr->left;
			}
		}
		//if nodePtr is smaller or equal
		else
		{
			if (nodePtr->right == nullptr)
			{
				nodePtr->right = currNode;
				currNode->parent = nodePtr;
				return 0;
			}
			else
			{
				nodePtr = nodePtr->right;
			}
		}


	}
	return 0;
}




template <class dataNode, typename datatype>
inline void BST<dataNode, datatype>::sortSmallest()
{

}

template <class dataNode, typename datatype>
inline void BST<dataNode, datatype>::sortLargest()
{

}

template <class dataNode, typename datatype>
inline bool BST<dataNode, datatype>::isEmpty()
{
	if (root = nullptr)
		return true;
	else
		return false;
}

template <class dataNode>
inline void BST<dataNode, datatype>::in_Order(dataNode *currNode)
{
	if (currNode != nullptr)
	{
		in_Order(currNode->left);
		cout << currNode->returnData();
		in_Order(currNode->right);
	}
}

template <class dataNode, typename datatype>
inline void BST<dataNode, datatype>::post_Order(dataNode *currNode)
{
	if (currNode)
	{
		post_Order(currNode->left);
		post_Order(currNode->right);
		cout << currNode->returnData();
	}

}

/*template <class dataNode, typename datatype>
inline void BST<dataNode, datatype>::breadth_Order(dataNode *currNode)
{
	Queue<dataNode> q;

	// Push the root
	q.enqueue(root);

	while (!q.isEmpty())
	{
		// Dequeue a node from front
		dataNode* v = q.front;
		

		// Enqueue the left children
		if (v->left != NULL)
			q.enqueue(v->left);

		// Enqueue the right children
		if (v->right != NULL)
			q.enqueue(v->right);

		q.dequeue();
	}

}


template <class dataNode, typename datatype>
inline void BST<dataNode, datatype>::breadthTraversal()
{
	dataNode *temp = root;
	breadth_Order(temp);
}*/

template <class dataNode, typename datatype>
inline void BST<dataNode, datatype>::postTraversal()
{
	
	dataNode *temp = root;
	post_Order(temp);
}
