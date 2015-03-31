#ifndef BST_H
#define BST_H

/****************************************************************************************
 *							Templated Binary Search Tree - C++
 *
 *	This is adapted from Tony Gaddis's Starting Out With C++ Sixth Edition.
 *
 * This implementation has all the functionality expected from a binary search tree
 * except that it can take any type. Something to note, if we want to use objects
 * with the BST, we may want to look in to overloading the >, <, ==, <=, >= operators.
 ****************************************************************************************/

template<class T>
class BinarySearchTree
{
	private:
		template<class U>
		class Node
		{
			friend class BinarySearchTree;
			U value;
			Node<U> *right;
			Node<U> *left;
			Node(U value, Node<U>* right = NULL, Node<U>* left = NULL)
			{
				this->value = value;
				this->right = right;
				this->left = left;
			}
		};
		Node<T>* root;
		void insert(Node<T> *&, T);
		void destroySubtree(Node<T> *);
		void remove (Node<T> *&, T);
		void performDeletion(Node<T> *&);
		void displayInOrder(Node<T> *);
		void displayInPreOrder(Node<T> *);
		void displayInPostOrder(Node<T> *);
	
	public:
		BinarySearchTree() { root = NULL; }
		~BinarySearchTree() { destroySubtree(root); }
		void insert(T value) { insert(root, value); }
		void remove(T value) { remove(root, value); }
		void makeDeletion(Node<T> *& node) { performDeletion(node); }
		void showInOrder() { displayInOrder(root); }
		void showInPostOrder() { displayInPostOrder(root); }
		void showInPreOrder() { displayInPreOrder(root); }
		bool search(T value);
};

/*
 * Insert a new node in to the tree. 
 */
template <class T>
void BinarySearchTree<T>::insert(Node<T> *&tree, T value)
{
	if(tree == NULL)						// Check to see if tree is null
	{
		tree = new Node<T>(value);			// If so, make the new node the root node
		return;
	}
	
	if(tree->value == value)				// Does the node already exist in the tree?
	{
		return;								// If so, return to prevent duplicate entries
	}

	
	if(tree->value > value)					// If the value is greater than a root node
	{
		insert(tree->left, value);			// Recursively call insert to the left subtree
	}
	else
	{
		insert(tree->right, value);			// Recursively call insert to the right subtree
	}
}

/*
 * Remove a specific node from the tree
 */
template <class T>
void BinarySearchTree<T>::remove(Node<T> *&tree, T value)
{
	if (tree == null)						// Make sure tree isn't empty
	{
		return;
	}

	if (tree->value > value)				// Find where the value is
	{
		remove(tree->left, value);
	}
	else if (tree->value < value)
	{
		remove(tree->right, value);
	}
	else
	{
		performDeletion(tree);				// Delete the node from the tree
	}
}

template <class T>
void BinarySearchTree<T>::performDeletion(Node<T> *&tree)
{

	Node<T> *nodeToRemove = tree;			// Hold node to be deleted
	Node<T> *nodeLink;						// used to find left subtree link attachment
	
	if (tree->right == null)				// if right child is null
	{				
		tree = tree->left;					// replace the tree with the left subtree
	}
	else if (tree->left == null)			// If left child is null
	{
		tree = tree->right;					// replace the tree with the right subtree
	}
	else
	{
		nodeLink = tree->right;				// We have two children from the root node, attach the right side of the tree
		while (nodeLink->left != null)		// Find the smallest node in the right-left subtree
		{
			nodeLink = nodeLink->left;		// assign left subtree to nodeLink
		}
		nodeLink->left = tree->left;		// attach left subtree of oringinal tree as left subtree of smallest node in right subtree
		tree = tree->right;					
	}
	delete nodeToRemove;					// Remove the node we want to delete
}

template <class T>
void BinarySearchTree<T>::displayInOrder(Node<T> *tree)
{
	if (tree)
	{
		displayInOrder(tree->left);
		std::cout << tree->value << " ";
		displayInOrder(tree->right);
	}
	std::cout << std::endl;
}

template <class T>
void BinarySearchTree<T>::displayInPostOrder(Node<T> *tree)
{
	if(tree)
	{
		cout << tree->value << " ";
		displayInPostOrder(tree->left);
		displayInPostOrder(tree->right);
	}
	std::cout << std::endl;
}

template <class T>
void BinarySearchTree<T>::displayInPreOrder(Node<T> *tree)
{
	if(tree)
	{
		displayInPreOrder(tree->left);
		displayInPreOrder(tree->right);
		cout << tree->value << " ";
	}
	std::cout << std::endl;
}


template <class T>
bool BinarySearchTree<T>::search(T value)
{
	Node<T>* tree = root;

	while (tree)
	{
		if (tree->value)
		{
			return true;
		}
		else if (tree->value > value)
		{
			tree = tree->left;
		}
		else
		{
			tree = tree->right;
		}
	}
	return false;
}


template <class T>
void BinarySearchTree<T>::destroySubtree(Node<T>* tree)
{
	if (!tree)
		return;
	destroySubtree(tree->left);
	destroySubtree(tree->right);
	delete tree;
}
#endif