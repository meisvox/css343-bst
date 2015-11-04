// BSTree.h		Author: Sam Hoover
// contains the declarations for the BSTree class
//
#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include "TreeData.h"
using namespace std;

// MIN_ITEM_COUNT
// the minimum number of a BSTree::Node object's m_itemCount
//
const int MIN_ITEM_COUNT = 1;

// VALUE_NOT_FOUND
// the value returned when a search for a dersired value was not met
//
const int VALUE_NOT_FOUND = -1;

// BSTree
// A binary search tree class used to store TreeData objects. TreeData objects
// are stored in a Node containing, a pointer to the TreeData object (m_item), a
// counter variable to track the number of occurrences of m_item (m_itemCount),
// and pointers to left and right children (m_left, m_right).
//
// New nodes are inserted into the tree in the format:
//			node < root = insert(root->left)
//			node >= root = insert(root->right)
// 
// New nodes are only added to the tree if the data being inserted is unique
// (not already in the tree). If the data is not unique, then the counter (
// m_ItemCount) of the node matching data is incremented by one.
//
// Nodes are removed only if m_ItemCount is equal to one. If m-ItemCount is 
// greater than one, m_ItemCount is decremented by one.
//
// BSTree requires the following operators to be overloaded in the TreeData 
// class for proper functionality: operator==, operator!=, operator<, 
// operator>, operator<=, operator>=, and operator<<.
//
class BSTree {
	
	// output
	// Prints the contents of the tree to the ostream
	// preconditions:	tree must be a valid BSTree object (must not reference
	//					a dereferenced nullptr); this not equal to nullptr.
	// postconditions:	the contents of this are printed to the ostream Each
	//					line contains a Node in the format: 
	//						"m_item m_itemCount"
	//
	friend ostream& operator<<(ostream &sout, const BSTree &tree);

public:
	// CONSTRUCTORS

	// default constructor
	// preconditions:	none
	// postconsitions:	Creates a tree of size zero (m_root equal to nullptr)
	//
	BSTree();

	// constructor(TreeData *data)
	// preconditions:	none
	// postconditions:	If data is not a nullptr, then m_root is set to a new
	//					node with m_item equal to data and m_itemCount equal
	//					to one. If data equals nullptr, m_root is set to
	//					nullptr.
	//
	BSTree(TreeData *data);

	// copy constructor (deep copy)
	// preconditions:	tree must be a valid BSTree object (must not reference
	//					a dereferenced nullptr)
	// postconditions:	this becomes an identical node-by-node copy of tree,
	//					creating new Nodes and new TreeDatas.
	//
	BSTree(const BSTree &tree);

	// destructor
	// preconditions:	none
	// postconditions:	All nodes removed and deleted, m_root set to nullptr
	//
	~BSTree();

	// MUTATORS

	// insert
	// Inserts a pointer to a TreeData object into the tree. If a node  
	// containing the object already exists in the tree, the object's 
	// m_itemCount in incremented by one. For the tree and all subtrees nodes
	// are inserted with the formula: 
	//			node < root = insert left
	//			node >= root = insert right
	// preconditions:	this not equal to nullptr.
	// postconditions:	If data does not already exist in the tree, then a new
	//					node with m_item equal to data is inserted into the
	//					tree. If the data already exists, then m_itemCount is
	//					incremented by one.
	//
	bool insert(TreeData *data);

	// remove
	// Removes a TreeData object equal to data from the tree. If there is only
	// one TreeData object, the node containing that object is removed and
	// deleted.
	// preconditions:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr); this not equal to nullptr.
	// postconditions:	If data is not found, then false is returned. If data
	//					is found and m_itemCount > 1 then m_itemCount is 
	//					decremented by one; if m_itemCount == 1 then the node
	//					is removed from the tree and deleted.
	//
	bool remove(const TreeData &data);

	// makeEmpty
	// Removes and deletes all nodes from the tree, and set m_root equal to
	// nullptr.
	// preconditions:	this not equal to nullptr.
	// postconditions:	All nodes removed and deleted, m_root set to nullptr
	//
	void makeEmpty();
	
	// ACCESSORS

	// retrieve
	// Searches the tree for data, if found, a const pointer to that object is
	// returned, otherwise false is returned.
	// preconditions:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr); this not equal to nullptr.
	// postconditions:	If data is found in the tree, a const pointer to the
	//					is returned. If data is not found them nullptr is
	//					returned.
	//
	const TreeData* retrieve(const TreeData &data) const;

	// depth
	// Finds the depth of a node with m_item equal to data. Depth of m_root is 
	// equal to zero.
	// preconditions:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr); this not equal to nullptr.
	// postconditions:	If data is found in the tree, the depth of the node
	//					containing data is returned. If data is not found then
	//					-1 is returned.
	//
	int depth(const TreeData &data) const;

	// descendants
	// Finds the number of descendants of the node containing data.
	// preconditions:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr); this not equal to nullptr.
	// postconditions:	If data is found, the number of descendants are of the
	//					node containing data are counted and returned. If data
	//					is not found, -1 is returned.
	//
	int descendants(const TreeData &data) const;

	// isEmpty
	// Returns true is tree is empty, else false
	// preconditions:	this not equal to nullptr.
	// postconditions:	If m_root equals nullptr true is returned, else false
	//
	bool isEmpty() const;

	// OPERATORS

	// assignment
	// Sets this equal to tree. Performs a deep copy.
	// preconditions:	tree must be a valid BSTree object (must not reference
	//					a dereferenced nullptr); this not equal to nullptr.
	// postconditions:	this becomes an identical node-by-node copy of tree,
	//					creating new Nodes and new TreeDatas.
	//
	const BSTree& operator=(const BSTree &tree);

	// equality
	// Node-by-node comparison of this and tree. Returns true only if the 
	// trees have the same data (including m_itemCount) and structure
	// preconditions:	tree must be a valid BSTree object (must not reference
	//					a dereferenced nullptr); this not equal to nullptr.
	// postconditions:	If this and tree have same data and structure then true
	//					is returned, else false is returned.
	//
	bool operator==(const BSTree &tree) const;

	// inequality
	// Node-by-node comparison of this and tree. Returns true only if the 
	// trees do not have the same data (including m_itemCount) and structure
	// preconditions:	tree must be a valid BSTree object (must not reference
	//					a dereferenced nullptr); this not equal to nullptr.
	// postconditions:	If this and tree do not have same data and structure
	//					then true is returned, else false is returned.
	//
	bool operator!=(const BSTree &tree) const;

private:
	// DATA

	// struct Node
	// a node containing a pointer to a TreeData object, an item count, and
	// pointers to left and right children
	// 
	struct Node {
		// default constructor
		// preconditions:	none
		// postconditions:	creates a node with m_item, m_left, and m_right 
		//					equal to nullptr, and m_itemCount equal to 0.
		//
		Node();

		// constructor(TreeData *data)
		// preconditions:	none
		// postconditions:	Creates a node with m_left and m_right are set
		//					equal to nullptr. If data is not nullptr, a node 
		//					with m_item equal to data & m_itemCount equal to 1.
		//					If data is nullptr then m_item, m_left, and m_right 
		//					are set equal to nullptr, and m_itemCount to 0.
		//
		Node(TreeData *data);

		// copy constructor (deep copy)
		// preconditions:	node must be a valid BSTree::Node object (must not 
		//					reference a dereferenced nullptr)
		// postconditions:	this becomes an identical copy of node, creating
		//					new data
		//
		Node(const Node &node);

		// m_item
		// a pointer to a TreeData object
		//
		TreeData *m_item;

		// m_itemCount
		// a counter for the number of occurences of m_item
		//
		int m_itemCount;

		// m_left
		// a pointer to left child
		//
		Node *m_left;

		// m_right
		// a pointer to wrathchild
		//
		Node *m_right;
	};

	// m_root
	// a pointer to the root of the this
	//
	Node *m_root;

	// HELPER FUNCTIONS

	// copyNode: copy constructor helper (deep copy)
	// preconditions:	this not equal to nullptr.
	// postconditions:	to becomes an identical copy of from, copying all
	//					decendants. 
	//
	void copyNode(Node *&to, Node *from);

	// insert helper
	// Inserts a pointer to a TreeData object into the tree. If a node  
	// containing the object already exists in the tree, the object's 
	// m_itemCount in incremented by one.
	// preconditions:	node->m_item must be a valid TreeData object not equal
	//					to nullptr; this not equal to nullptr.
	// postconditions:	If data does not already exist in the tree, then a new
	//					node with m_item equal to data is inserted into the
	//					tree. If the data already exists, then m_itemCount is
	//					incremented by one.
	//
	bool insert(TreeData *data, Node *&node);
	
	// remove helper
	// Removes a TreeData object equal to data from the tree. If there is only
	// one TreeData object, the node containing that object is removed and
	// deleted.
	// preconditions:	node->m_item must be a valid TreeData object not equal
	//					to nullptr; this not equal to nullptr.
	// postconditions:	If data is not found, then false is returned. If data
	//					is found and m_itemCount > 1 then m_itemCount is 
	//					decremented by one; if m_itemCount == 1 then the node
	//					is removed from the tree and deleted.
	//
	bool remove(const TreeData &data, Node *&node);
	
	// deleteNode: remove helper
	// Deletes a Node with m_item equal to data from the tree.
	// preconditions:	node must be a valid BSTree::Node object not equal to
	//					nullptr; this not equal to nullptr.
	// postconditions:	node is deleted and set to nullptr.
	//
	void deleteNode(Node *&node);
	
	// deleteSmallest: remove helper
	// Finds and deletes the Node with the smallest m_item from the tree.
	// preconditions:	node must be a valid BSTree::Node object not equal to
	//					nullptr; this not equal to nullptr.
	// postconditions:	node is deleted and set to nullptr.
	//
	TreeData* deleteSmallest(Node *&node);
	
	// makeEmpty helper
	// Removes and deletes all nodes from the tree, and sets m_root equal to
	// nullptr.
	// preconditions:	this not equal to nullptr
	// postconditions:	All nodes removed and deleted, m_root set to nullptr
	//
	void makeEmpty(Node *node);

	// compareNode: equality helper
	// Node-by-node comparison of this and tree. Returns true only if the 
	// trees have the same data (including m_itemCount) and structure
	// preconditions:	this not equal to nullptr
	// postconditions:	If self and other have same data and structure then true
	//					is returned, else false is returned.
	//
	bool compareNode(Node *self, Node *other) const;
	
	// findNode: descendants helper
	// finds a Node with m_item equal to data and retunrs a constant pointer to
	// the Node. If no match is found, nullptr is returned.
	// preconditions:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr); this not equal to nullptr.
	// postconditions:	if data is found, then a constant pointer to the Node 
	//					containing data is returned, else false is returned.
	//
	const Node* findNode(const TreeData &data) const;
	
	// descendants helper
	// Finds the number of descendants of the node containing data.
	// preconditions:	data must be a valid TreeData object (must not reference
	//					a dereferenced nullptr); this not equal to nullptr.
	// postconditions:	If data is found, the number of descendants are of the
	//					node containing data are counted and returned. If data
	//					is not found, -1 is returned.
	//
	int descendants(int &count, const Node *node) const;
	
	// print: output helper
	// Prints the contents of the tree to sout.
	// preconditions:	none
	// postconditions:	the contents of this are printed to sout. Each line
	//					contains a Node in the format: "m_item m_itemCount"
	//
	void print(ostream &sout, Node *node) const;
};

#endif