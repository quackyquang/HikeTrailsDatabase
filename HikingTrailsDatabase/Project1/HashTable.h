// Hash Table header file

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HBSTNode.h"
#include <string>
using namespace std;

template <class keyType, class itemType> // trailName is searchKey, trailObj is itemType
class HashTable // Implement as Array of Linked HashBSTNodes
{
private:
	// size of array
	int size;
	// array of pointers to HashBSTNodes, needs to be dynamic
	HBSTNode<keyType, itemType> ** hashTable;
public:
	// constructors
	HashTable();
	HashTable(size);

	// destructor
	virtual ~HashTable();

	int hash(const keyType searchKey) const;	// hash function, take in object, convert keyType(string in this case) to int
	bool add(const keyType searchKey, const HDSTNode<keyType, itemType> value);	// takes in searchKey and item and puts into table, handles collisions
	bool remove(const keyType searchKey);	// takes in address and deletes entry
	void empty();	// clears the hash table
	itemType getValue(searchKey) const;
	// traverse (see returnData for print all values)
	void printEntries();
	void printKeys();
};

// Constructor Default
template <class searchKey, class itemType>
HashTable<searchKey, itemType>::HashTable()
{
	size = 0;
	hashTable = nullptr;
}

// Constructor 1
template <class searchKey, class itemType>
HashTable<searchKey, itemType>::HashTable(int size)
{
	hashTable = new HBSTNode<T>*[size];
	this->size = size;
}

// Destructor
template <class searchKey, class itemType>
HashTable<searchKey, itemType>::~HashTable()
{
	// calls empty
	empty();
}

// Hash Function
template <class searchKey, class itemType>
int HashTable<searchKey, itemType>::hash(searchKey key)	// trailName
{
	// get characters from string
	// convert each to int
	// add them together
	int i, sum = 0, intFromChar;
	for (i = 0; i < trailName.size(); i++)
	{
		intFromChar = trailName.at(i);
		sum += intFromChar;
	}
	return sum % size;	// return this index % size
	// consider converting each char in string to binary form instead of int with same operations
}

// add
template <class searchKey, class itemType>
bool HashTable<searchKey, itemType>::add(searchKey key, itemType trailObj)
{
	// create a new object with key and item
	HBSTNode<searchKey, itemType> * newNode = new HBSTNode<searchKey, itemType>(key, trailObj);

	// add item to the list, get index from key value
	int index = hash(key);

	// newNode will point to what headPtr pointed to
	// this could be a nullptr or a previously added HBSTNode
	newNode->setLeft(hashTable[index]);
	hashTable[index] = newNode; // puts HBSTNode at this location in the hash table
	return true;

}

// remove
template <class searchKey, class itemType>
bool HashTable<searchKey, itemType>::remove(searchKey key)
{
	// find the item based on key
	// use hash to get index
	// if the item is found, remove it
	// else return not found
}

template <class searchKey, class itemType>
void HashTable<searchKey, itemType>::empty()
{
	// empty the entire hash table
	// go by index
	// check if the hash table is empty
	// if so then nothing to do
	if (hashTable == nullptr) // hashTable holds nullptr, nothing in it
	{
		return;
	}
	// otherwise remove items one by one
	// make each item nullptr
	int i;
	for (i = 0; i < size; i++)
	{
		delete hashTable[i]; // think about delete [] hashTable outside loop
		*(hashTable + i) = nullptr;
	}
}

template <class searchKey, class itemType>
void HashTable<searchKey, itemType>::traverse(void visit(itemType item))
{
	// go from the beginning of the table to the end based on size
	int i;
	for (i = 0; i < size; i++)
	{
		while (hashTable[i]) // != nullptr i.e. end of HBSTNodes at particular index
		{
			visit(hashTable[i]->getItem());
			// update
			hashTable[i] = hashTable[i]->getLeft();
		}
	}
}
#endif
