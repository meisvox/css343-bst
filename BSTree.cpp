// BSTree.cpp		Author: Sam Hoover
// contains the declarations for the BSTree class
//
#ifndef BSTREE_CPP
#define BSTREE_CPP
#include "BSTree.h"

// BSTree::Node default constructor
// preconditions:	none
// postconditions:	creates a node with m_item, m_left, and m_right 
//					equal to nullptr, and m_itemCount equal to 0.
//
BSTree::Node::Node() : m_item(nullptr), m_itemCount(0), m_left(nullptr), m_right(nullptr) {}

// BSTree::Node constructor(TreeData *data)
// preconditions:	none
// postconditions:	Creates a node with m_left and m_right are set
//					equal to nullptr. If data is not nullptr, a node 
//					with m_item equal to data & m_itemCount equal to 1.
//					If data is nullptr then m_item, m_left, and m_right 
//					are set equal to nullptr, and m_itemCount to 0.
//
BSTree::Node::Node(TreeData *data) : m_left(nullptr), m_right(nullptr) { 
	if(data != nullptr)  {
		m_item = data;
		m_itemCount = 1;
	} else {
		m_item = nullptr;
		m_itemCount = 0;
	}
}

// BSTree::Node copy constructor (deep copy)
// preconditions:	none
// postconditions:	this becomes an identical copy of node, creating
//					new data
//
BSTree::Node::Node(const Node &node) : m_item(new TreeData(*node.m_item)),
									   m_itemCount(node.m_itemCount), 
									   m_left(nullptr), 
									   m_right(nullptr) {}

// BSTree default constructor
// preconditions:	none
// postconsitions:	Creates a tree of size zero (m_root equal to nullptr)
//
BSTree::BSTree() : m_root(nullptr) {}

// BSTree constructor(TreeData *data)
// preconditions:	none
// postconditions:	If data is not a nullptr, then m_root is set to a new
//					node with m_item equal to data and m_itemCount equal
//					to one. If data equals nullptr, m_root is set to
//					nullptr.
//
BSTree::BSTree(TreeData *data) {
	if(data != nullptr) {
		m_root = new Node(data);
	} else {
		m_root = nullptr;
	}
}

// copy constructor (deep copy)
// preconditions:	tree must be a valid BSTree object (must not reference
//					a dereferenced nullptr)
// postconditions:	this becomes an identical node-by-node copy of tree,
//					creating new Nodes and new TreeDatas.
//
BSTree::BSTree(const BSTree &tree) {
	copyNode(m_root, tree.m_root);
}

// copyNode: copy constructor helper (deep copy)
// preconditions:	this not equal to nullptr.
// postconditions:	to becomes an identical copy of from, copying all
//					decendants. 
//
void BSTree::copyNode(Node *&to, Node *from) {
	if(from == nullptr) {
		to = nullptr;
	} else {
		to = new Node(*from);
		copyNode(to->m_left, from->m_left);
		copyNode(to->m_right, from->m_right);
	}
}

// destructor
// preconditions:	none
// postconditions:	All nodes removed and deleted, m_root set to nullptr
//
BSTree::~BSTree() {
	makeEmpty();
}

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
bool BSTree::insert(TreeData *data) {
	return(insert(data, m_root));
}

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
bool BSTree::insert(TreeData *data, Node *&node) {
	if(node == nullptr) {
		node = new Node(data);
	} else {
		if(*data == *node->m_item) {
			node->m_itemCount++;
			return(false);
		}
		if(*data < *node->m_item) {
			insert(data, node->m_left);
		} else {
			insert(data, node->m_right);
		}
	}
	return(true);
}

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
bool BSTree::remove(const TreeData &data) {
	return(remove(data, m_root));
}

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
bool BSTree::remove(const TreeData &data, Node *&node) {
	if(node == nullptr) {
		return(false);
	} else if(data == *node->m_item) {
		if(node->m_itemCount > MIN_ITEM_COUNT) {
			node->m_itemCount--;
		} else {
			deleteNode(node);
		}
		return(true);
	} else if(data < *node->m_item) {
		return(remove(data, node->m_left));
	} else {
		return(remove(data, node->m_right));
	}

	return(false);
}

// deleteNode: remove helper
// Deletes a Node with m_item equal to data from the tree.
// preconditions:	node must be a valid BSTree::Node object not equal to
//					nullptr; this not equal to nullptr.
// postconditions:	node is deleted and set to nullptr.
//
void BSTree::deleteNode(Node *&node) {
	if(node->m_left == nullptr && node->m_right == nullptr) {
		delete node->m_item;
		node->m_item = nullptr;
		delete node;
		node = nullptr;
	} else if(node->m_left == nullptr) {
		Node *temp = node;
		node = node->m_right;
		delete temp->m_item; 
		temp->m_item = nullptr;
		delete temp;
		temp = nullptr;
	} else if(node->m_right == nullptr) {
		Node *temp = node;
		node = node->m_left;
		delete temp->m_item;
		temp->m_item = nullptr;
		delete temp;
		temp = nullptr;
	} else {
		delete node->m_item;
		node->m_item = deleteSmallest(node->m_right);
	}
}

// deleteSmallest: remove helper
// Finds and deletes the Node with the smallest m_item from the tree.
// preconditions:	node must be a valid BSTree::Node object not equal to
//					nullptr; this not equal to nullptr.
// postconditions:	node is deleted and set to nullptr.
//
TreeData* BSTree::deleteSmallest(Node *&node) {
	if(node->m_left == nullptr) {
		TreeData *item = node->m_item;
		Node *temp = node;
		node = node->m_right;
		delete temp;
		temp = nullptr;
		return(item);
	} else {
		return(deleteSmallest(node->m_left));
	}
}

// makeEmpty
// Removes and deletes all nodes from the tree, and set m_root equal to
// nullptr.
// preconditions:	this not equal to nullptr.
// postconditions:	All nodes removed and deleted, m_root set to nullptr
//
void BSTree::makeEmpty() {
	if(!isEmpty()) {
		makeEmpty(m_root);
		m_root = nullptr;
	}
}

// makeEmpty helper
// Removes and deletes all nodes from the tree, and sets m_root equal to
// nullptr.
// preconditions:	this not equal to nullptr
// postconditions:	All nodes removed and deleted, m_root set to nullptr
//
void BSTree::makeEmpty(Node *node) {
	if(node != nullptr) {
		makeEmpty(node->m_left);
		makeEmpty(node->m_right);
		delete node->m_item;
		node->m_item = nullptr;
		delete node;
		node = nullptr;
	}
}

// retrieve
// Searches the tree for data, if found, a const pointer to that object is
// returned, otherwise false is returned.
// preconditions:	data must be a valid TreeData object (must not reference
//					a dereferenced nullptr); this not equal to nullptr.
// postconditions:	If data is found in the tree, a const pointer to the
//					is returned. If data is not found them nullptr is
//					returned.
//
const TreeData* BSTree::retrieve(const TreeData &data) const {
	Node* temp = m_root;
	while(temp != nullptr) {
		if(data == *temp->m_item) {
			return(temp->m_item);
		} else if(data < *temp->m_item) {
			temp = temp->m_left;
		} else {
			temp = temp->m_right;
		}
	}
	return(nullptr);
}

// depth
// Finds the depth of a node with m_item equal to data. Depth of m_root is 
// equal to zero.
// preconditions:	data must be a valid TreeData object (must not reference
//					a dereferenced nullptr); this not equal to nullptr.
// postconditions:	If data is found in the tree, the depth of the node
//					containing data is returned. If data is not found then
//					-1 is returned.
//
int BSTree::depth(const TreeData &data) const {
	int dep = 0;
	Node* temp = m_root;
	while(temp != nullptr) {
		if(data == *temp->m_item) {
			return(dep);
		} else if(data < *temp->m_item) {
			dep++;
			temp = temp->m_left;
		} else {
			dep++;
			temp = temp->m_right;
		}
	}
	return(VALUE_NOT_FOUND);
}

// descendants
// Finds the number of descendants of the node containing data.
// preconditions:	data must be a valid TreeData object (must not reference
//					a dereferenced nullptr); this not equal to nullptr.
// postconditions:	If data is found, the number of descendants are of the
//					node containing data are counted and returned. If data
//					is not found, -1 is returned.
//
int BSTree::descendants(const TreeData &data) const {
	const Node* temp = findNode(data);
	if(temp == nullptr) {
		return(VALUE_NOT_FOUND);
	}

	int des = 0;
	des = descendants(des, temp);
	return(des);
}

// descendants helper
// Finds the number of descendants of the node containing data.
// preconditions:	data must be a valid TreeData object (must not reference
//					a dereferenced nullptr); this not equal to nullptr.
// postconditions:	If data is found, the number of descendants are of the
//					node containing data are counted and returned. If data
//					is not found, -1 is returned.
//
int BSTree::descendants(int &count, const Node *node) const {
	if(node != nullptr) {
		count++;
		descendants(count, node->m_left);
		descendants(count, node->m_right);
	} else {
		return(-1);
	}
	// inital root node is counted, so must decrease couny by one
	return(count - 1);
}

// findNode: descendants helper
// finds a Node with m_item equal to data and retunrs a constant pointer to
// the Node. If no match is found, nullptr is returned.
// preconditions:	data must be a valid TreeData object (must not reference
//					a dereferenced nullptr); this not equal to nullptr.
// postconditions:	if data is found, then a constant pointer to the Node 
//					containing data is returned, else false is returned.
//
const BSTree::Node* BSTree::findNode(const TreeData &data) const {
	Node* temp = m_root;
	while(temp != nullptr) {
		if(data == *temp->m_item) {
			return(temp);
		} else if(data < *temp->m_item) {
			temp = temp->m_left;
		} else {
			temp = temp->m_right;
		}
	}
	return(nullptr);
}

// isEmpty
// Returns true is tree is empty, else false
// preconditions:	this not equal to nullptr.
// postconditions:	If m_root equals nullptr true is returned, else false
//
bool BSTree::isEmpty() const {
	if(m_root == nullptr) {
		return(true);
	}
	return(false);
}

// assignment
// Sets this equal to tree. Performs a deep copy.
// preconditions:	tree must be a valid BSTree object (must not reference
//					a dereferenced nullptr); this not equal to nullptr.
// postconditions:	this becomes an identical node-by-node copy of tree,
//					creating new Nodes and new TreeDatas.
//
const BSTree& BSTree::operator=(const BSTree &tree) {
	if(this != &tree) {
		makeEmpty();
		copyNode(m_root, tree.m_root);
	}
	return(*this);
}

// equality
// Node-by-node comparison of this and tree. Returns true only if the 
// trees have the same data (including m_itemCount) and structure
// preconditions:	tree must be a valid BSTree object (must not reference
//					a dereferenced nullptr); this not equal to nullptr.
// postconditions:	If this and tree have same data and structure then true
//					is returned, else false is returned.
//
bool BSTree::operator==(const BSTree &tree) const {
	if(this == &tree) {
		return(true);
	}
	return(compareNode(m_root, tree.m_root));
}

// compareNode: equality helper
// Node-by-node comparison of this and tree. Returns true only if the 
// trees have the same data (including m_itemCount) and structure
// preconditions:	this not equal to nullptr
// postconditions:	If self and other have same data and structure then true
//					is returned, else false is returned.
//
bool BSTree::compareNode(Node *self, Node *other) const {
	if(self != nullptr && other != nullptr) {
		if(*self->m_item == *other->m_item && self->m_itemCount == other->m_itemCount) {
			bool l_retVal = compareNode(self->m_left, other->m_left);
			bool r_retVal = compareNode(self->m_right, other->m_right);
			
			// logical iff
			if((l_retVal && r_retVal) || (!l_retVal && !r_retVal)) {
				return(true);
			}
		}
	} else if(self == nullptr && other == nullptr) {
		return(true);
	}
	return(false);
}

// inequality
// Node-by-node comparison of this and tree. Returns true only if the 
// trees do not have the same data (including m_itemCount) and structure
// preconditions:	tree must be a valid BSTree object (must not reference
//					a dereferenced nullptr); this not equal to nullptr.
// postconditions:	If this and tree do not have same data and structure
//					then true is returned, else false is returned.
//
bool BSTree::operator!=(const BSTree &tree) const {
	if(!(*this == tree)) {
		return(true);
	}
	return(false);
}

// print: output helper
// Prints the contents of the tree to sout.
// preconditions:	none
// postconditions:	the contents of this are printed to sout. Each line
//					contains a Node in the format: "m_item m_itemCount"
//
void BSTree::print(ostream &sout, Node *node) const {
	if(node != nullptr) {
		print(sout, node->m_left);
		sout << *node->m_item << " " << node->m_itemCount << endl;
		print(sout, node->m_right);
	}
}

// output
// Prints the contents of the tree to the ostream
// preconditions:	tree must be a valid BSTree object (must not reference
//					a dereferenced nullptr); this not equal to nullptr.
// postconditions:	the contents of this are printed to the ostream Each
//					line contains a Node in the format: 
//						"m_item m_itemCount"
//
ostream& operator<<(ostream &sout, const BSTree &tree) {
	tree.print(sout, tree.m_root);
	return(sout);
}
#endif