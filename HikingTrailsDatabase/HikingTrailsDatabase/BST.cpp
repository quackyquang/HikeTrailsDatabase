#include "BST.h"


template <typename Hash, typename datatype>
BST<Hash, datatype>::BST(Hash hashTable, datatype field)
{
	Hash nodePtr = root;

	while (hashTable->next != nullptr)
	{
		Hash newNode = nullptr;

		if (root == nullptr)
			newNode = root;

		while (nodePtr)
		{
			if (nodePtr.getField() > newNode.getField())
			{
				if (nodePtr->left == nullptr)
				{
					newNode->parent = nodePtr;
					break;
				}
				else
				{
					nodePtr = nodePtr->left;
				}
			}
			else
			{
				if (nodePtr->right == nullptr)
				{
					newNode->parent = nodePtr;
					break;
				}
				else
				{
					nodePtr = nodePtr->right;
				}
			}


		}

	}
}

template <typename Hash, typename datatype>
BST<Hash, datatype>::~BST()
{

}
