#include <iostream>
#include <string>
#include "BST.h"

using namespace std;
int main(int argc, char* argv[])
{
	BinarySearchTree<int> bst;

	for (int i = 0; i < 10; i++)
	{
		bst.insert(i);
	}
	bst.showInOrder();
	bst.showInPreOrder();
	bst.showInPostOrder();

	bst.~BinarySearchTree();
	getchar();
	return 0;
}