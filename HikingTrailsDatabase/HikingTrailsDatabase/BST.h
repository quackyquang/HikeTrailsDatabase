

template <typename Hash, typename datatype>

class BST
{
private:
	Hash *parent;
	Hash *left = nullptr;
	Hash *right = nullptr;
	Hash *root = nullptr;

public:
	BST(Hash hashTable, datatype field);

	~BST();

	void sortLargest(datatype field);

	void sortSmallest(datatype field);

	void insert(datatype field);

	void remove(datatype field);
};
