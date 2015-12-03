// Specification File for class HBSTNode

#ifndef HBSTNode_H
#define HBSTNode_H

template<class S, class T> // Trail Object
class HBSTNode
{
private:
	T item;					// trailObj
	S searchKey;			// trailObj->trailName
	HBSTNode<S, T> * leftNode;	// Hash table will only use one of these node pointers, BST will use all
	HBSTNode<S, T> * rightNode;
	HBSTNode<S, T> * parentNode;
public:
	HBSTNode();
	HBSTNode(const T anItem, const S key);
	HBSTNode(const T anItem, const S key, HBSTNode<T> * left);
	HBSTNode(const T anItem, const S key, HBSTNode<T> * left, HBSTNode<T> * right, HBSTNode<T> * parent);
	virtual ~HBSTNode();

	T getItem() const;
	void setItem(const T);
	S getKey() const;
	void setKey(const S);
	HBSTNode<T>* getLeft() const;
	void setLeft(HBSTNode<T>*);
	HBSTNode<T>* getRight() const;
	void setRight(HBSTNode<T>*);
	HBSTNode<T>* getParent() const;
	void setParent(HBSTNode<T>*);

	T getField(int number);	// getField, passed a number and returns field (attribute) based on that number
	void returnData();	// returnData, no parameters, displays hashTable
};


// Implementation for class HBSTNode

// Default Constructor
template<class S, class T>
HBSTNode<S, T>::HBSTNode() : leftNode(nullptr), rightNode(nullptr), parentNode(nullptr)
{
}

// Item only constructor
template<class S, class T>
HBSTNode<S, T>::HBSTNode(const T anItem, const S key) : item(anItem), searchKey(key), leftNode(nullptr), rightNode(nullptr), parentNode(nullptr)
{
}

// Hash Node Constructor
template<class S, class T>
HBSTNode<S, T>::HBSTNode(const T anItem, const S key, HBSTNode<S, T>* next) : item(anItem), searchKey(key), leftNode(next), rightNode(nullptr), parentNode(nullptr)
{
}

// BST Node Constructor
template<class S, class T>
HBSTNode<S, T>::HBSTNode(const T anItem, HBSTNode<S, T> * left, HBSTNode<S, T> * right, HBSTNode<S, T> * parent)
{
	item = anItem;
	leftNode = left;
	rightNode = right;
	parentNode = parent;
}

// Destructor
template<class S, class T>
HBSTNode<S, T>::~HBSTNode()
{
	// left
	delete leftNode;
	leftNode = nullptr;
	// right
	delete rightNode;
	rightNode = nullptr;
	// parent
	delete parentNode;
	parentNode = nullptr;
}

template<class S, class T>
T HBSTNode<S, T>::getItem() const
{
	return item;
}

template<class S, class T>
void HBSTNode<S, T>::setItem(const T it)
{
	item = it;
}

template<class S, class T>
S HBSTNode<S, T>::getKey() const
{
	return searchKey;
}

template<class S, class T>
void HBSTNode<S, T>::setItem(const S key)
{
	searchKey = key;
}

template<class S, class T>
HBSTNode<S, T>* HBSTNode<S, T>::getLeft() const
{
	return leftNode;
}

template<class S, class T>
void HBSTNode<S, T>::setNext(HBSTNode<S, T>* left)
{
	leftNode = left;
}

template<class S, class T>
HBSTNode<S, T>* HBSTNode<S, T>::getRight() const
{
	return rightNode;
}

template<class S, class T>
void HBSTNode<S, T>::setRight(HBSTNode<S, T>* right)
{
	rightNode = right;
}

template<class S, class T>
HBSTNode<S, T>* HBSTNode<S, T>::getParent() const
{
	return parentNode;
}

template<class S, class T>
void HBSTNode<S, T>::setNext(HBSTNode<S, T>* parent)
{
	parentNode = parent;
}

template <class S, class T>
T getField(int num) // need to split this into strings and doubles based on num?
{
	/* EXAMPLE
	Name:Mori Ridge Trail:		1
	Park:Sweeney Ridge:			2
	Location:Pacifica:			3
	Distance:4:					4
	Difficulty:2.5:				5
	Poplularity:4.5				6
	*/
	switch (num)
	{
	case 1:
		return this->getName(); // string
		break;
	case 2:
		return this->getPark(); // string
		break;
	case 3:
		return this->getLocation(); // string
		break;
	case 4:
		return this->getDistance(); // double
		break;
	case 5:
		return this->getDifficulty(); // double
		break;
	case 6:
		return this->getPopularity(); // double
		break;
	case default:
		// throw exception;
		cout << "Invalid input." << endl;
	}
}

template<class S, class T>
void returnData()
{
	HashTable<S, T>::printEntries();
}

#endif // HBSTNode_H
