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

	void sortLargest(dataNode *currNode);

	void sortSmallest(dataNode *currNode);

	int insert(dataNode *currNode);

	void remove(dataNode *currNode);

	bool isEmpty();

	void printTree(dataNode *currNode);

	void in_Order(datanode *currNode);

	void post_Order(dataNode *currNode);

	//void breadth_Order(dataNode *currNode);

	void postTraversal();

	void inTraversal();

	//void breadthTraversal();
};

template <class dataNode, typename datatype>
inline BST<dataNode, datatype>::BST()
{
	field = 1;
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
		int cmp = compareData(nodePtr, currNode);

		//if nodePtr is bigger
		if (cmp > 0)
		{
			if (nodePtr->leftNodeNode == nullptr)
			{
				nodePtr->leftNodeNode = currNode;
				currNode->parentNode = nodePtr;
				return 0;
			}
			else
			{
				nodePtr = nodePtr->leftNodeNode;
			}
		}
		//if nodePtr is smaller or equal
		else
		{
			if (nodePtr->rightNode == nullptr)
			{
				nodePtr->rightNode = currNode;
				currNode->parentNode = nodePtr;
				return 0;
			}
			else
			{
				nodePtr = nodePtr->rightNode;
			}
		}


	}
	return 0;
}


template <class dataNode, typename datatype>
inline void BST<dataNode, datatype>::sortSmallest(dataNode *currNode)
{
	if (currNode != nullptr)
	{
		in_Order(currNode->leftNodeNode);
		cout << currNode->returnData();
		in_Order(currNode->rightNode);
	}
}

template <class dataNode, typename datatype>
inline void BST<dataNode, datatype>::sortLargest(dataNode *currNode)
{
	if (currNode != nullptr)
	{
		in_Order(currNode->rightNode);
		cout << currNode->returnData();
		in_Order(currNode->leftNodeNode);
	}
}

template <class dataNode, typename datatype>
inline bool BST<dataNode, datatype>::isEmpty()
{
	if (root = nullptr)
		return true;
	else
		return false;
}

template <class dataNode, typename datatype>
inline void BST<dataNode, datatype>::printTree(dataNode *currNode)
{
	if (currNode != nullptr)
	{
		cout << currNode->getField(field);
		in_Order(currNode->leftNodeNode);
		in_Order(currNode->rightNode);
	}
}

template <class dataNode>
inline void BST<dataNode, datatype>::in_Order(dataNode *currNode)
{
	if (currNode != nullptr)
	{
		in_Order(currNode->leftNodeNode);
		cout << currNode->returnData();
		in_Order(currNode->rightNode);
	}
}

template <class dataNode, typename datatype>
inline void BST<dataNode, datatype>::post_Order(dataNode *currNode)
{
	if (currNode)
	{
		post_Order(currNode->leftNodeNode);
		post_Order(currNode->rightNode);
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
		

		// Enqueue the leftNode children
		if (v->leftNode != NULL)
			q.enqueue(v->leftNode);

		// Enqueue the rightNode children
		if (v->rightNode != NULL)
			q.enqueue(v->rightNode);

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
	delete temp;
}

template <class dataNode, typename datatype>
inline void BST<dataNode, datatype>::inTraversal()
{
	dataNode *temp = root;
	in_Order(temp);
	delete temp;
}

template <class dataNode, typename datatype>
inline void BST::<dataNode, datatype>::compareData(dataNode node1, dataNode node2)
{
	if (node1->getField(field) > node2->getField(field))
		return 1;
	else
		return -1;
}
