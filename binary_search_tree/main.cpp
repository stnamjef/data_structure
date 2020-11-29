#include "binary_search_tree.h"
using namespace std;

int main()
{
	BinarySearchTree bst;

	bst.insert("k");
	bst.insert("d");
	bst.insert("o");
	bst.insert("a");
	bst.insert("f");
	bst.insert("x");
	bst.insert("v");

	bst.print();

	return 0;
}