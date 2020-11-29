#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Node
{
	string data;
	Node* left;
	Node* right;
};

enum OrderedType { PRE_ORDER, IN_ORDER, POST_ORDER };

class BinarySearchTree
{
private:
	Node* root;
public:
	BinarySearchTree();
	~BinarySearchTree();
	void make_empty();
	bool is_empty();
	bool is_full();
	int length();
	void get(string& item, bool& found);
	void insert(string item);
	void remove(string item);
	// void reset(OrderedType order);
	void print() const;
};

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}

void _destroy(Node*& tree)
{
	if (tree != nullptr) {
		_destroy(tree->left);
		_destroy(tree->right);
		delete tree;
	}
}

BinarySearchTree::~BinarySearchTree()
{
	_destroy(root);
}

void BinarySearchTree::make_empty()
{
	_destroy(root);
	root = nullptr;
}

bool BinarySearchTree::is_empty() 
{
	return root == nullptr; 
}

bool BinarySearchTree::is_full()
{
	Node* node;
	try {
		node = new Node;
		delete node;
		return false;
	}
	catch (std::bad_alloc exception) {
		return true;
	}
}

int count_node(Node* tree)
{
	if (tree == nullptr) {
		return 0;
	}
	else {
		return count_node(tree->left) + count_node(tree->right) + 1;
	}
}

int BinarySearchTree::length()
{ 
	return count_node(root); 
}

void _get(Node* tree, string& item, bool& found)
{
	if (tree == nullptr) {
		found = false;
	}
	else if (item < tree->data) {
		_get(tree->left, item, found);
	}
	else if (item > tree->data) {
		_get(tree->right, item, found);
	}
	else {
		item = tree->data;
		found = true;
	}
}

void BinarySearchTree::get(string& item, bool& found) 
{ 
	_get(root, item, found); 
}

void _insert(Node*& tree, string item)
{
	if (tree == nullptr) {
		tree = new Node;
		tree->right = nullptr;
		tree->left = nullptr;
		tree->data = item;
	}
	else if (item < tree->data) {
		_insert(tree->left, item);
	}
	else {
		_insert(tree->right, item);
	}
}

void BinarySearchTree::insert(string item) 
{ 
	_insert(root, item); 
}

void _get_predecessor(Node* tree, string& data)
{
	while (tree->right != nullptr) {
		tree = tree->right;
	}
	data = tree->data;
}

void _remove(Node*& tree, string item);

void _remove_node(Node*& tree)
{
	string item;
	Node* temp = tree;
	if (tree->left == nullptr) {
		tree = tree->right;
		delete temp;
	}
	else if (tree->right == nullptr) {
		tree = tree->left;
		delete temp;
	}
	else {
		_get_predecessor(tree->left, item);
		tree->data = item;
		_remove(tree->left, item);
	}
}

void _remove(Node*& tree, string item)
{
	if (item < tree->data) {
		_remove(tree->left, item);
	}
	else if (item > tree->data) {
		_remove(tree->right, item);
	}
	else {
		_remove_node(tree);
	}
}

void BinarySearchTree::remove(string item)
{
	_remove(root, item);
}

void _print(const Node* tree)
{
	if (tree != nullptr) {
		_print(tree->left);
		cout << tree->data << ' ';
		_print(tree->right);
	}
}

void BinarySearchTree::print() const
{
	_print(root);
}