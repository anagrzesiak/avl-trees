
#pragma once
#include<iostream>

using namespace std;

class AVL
{
	struct node
	{
		int val;
		node* l;
		node* r;
		int height;
		friend class TREE;
	};

	node* root;
	void Empty(node* a);
	node* Insert(int x, node* a);
	node* RightRotate(node* &a);
	node* LeftRotate(node* &a);
	node* DoubleLeftRotate(node* &a);
	node* DoubleRightRotate(node* &a);
	node* Min(node* a);
	node* Max(node* a);
	int Height(node* a);
	int GetBalance(node* a);
	void Inorder(node* a);
	void Preorder(node *a);
	void Postorder(node *a);
	void Print2DUtil(node *a, int space);
	void Print2D(node *a);
	node* Remove(int x, node *a);

public:
	AVL() {
		root = nullptr;
	}

	void Insert(int x) {
		root = Insert(x, root);
	}

	node* Remove(int x) {
		root = Remove(x, root);
		return 0;
	}

	void Print2D() {
		Print2D(root);
	}

	void Show() {
		Inorder(root);
		cout << endl;
		//Preorder(root);
		//cout << endl;
		//Postorder(root);
		//cout << endl;
	}
};
