#include "header.h"
#include<algorithm>
#include<iostream>
#define COUNT 10

using namespace std;

void AVL::Empty(node* a)
{
	if (a == NULL)
		return;
	Empty(a->l);
	Empty(a->l);
	delete a;
}

AVL::node* AVL::Insert(int x, node* a)
{
	if (a == NULL)
	{
		a = new node;
		a->val = x;
		a->height = 0;
		a->l = a->r = NULL;
	}
	else if (x < a->val)
	{
		a->l = Insert(x, a->l);
		if (Height(a->l) - Height(a->r) == 2)
		{
			if (x < a->l->val)
				a = RightRotate(a);
			else
				a = RightRotate(a);
		}
	}
	else if (x > a->val)
	{
		a->r = Insert(x, a->r);
		if (Height(a->r) - Height(a->l) == 2)
		{
			if (x > a->r->val)
				a = LeftRotate(a);
			else
				a = LeftRotate(a);
		}
	}

	a->height = max(Height(a->l), Height(a->r)) + 1;
	return a;

}

AVL::node* AVL::RightRotate(node* &a)
{
	if (a->l) {
		node* b = a->l;
		a->l = b->r;
		b->r = a;
		a->height = max(Height(a->l), Height(a->r)) + 1;
		b->height = max(Height(b->l), a->height) + 1;
		return b;
	}

	return 0;
}

AVL::node * AVL::LeftRotate(node* &a)
{
	if (a->r) {
		node* b = a->r;
		a->r = b->l;
		b->l = a;
		a->height = max(Height(a->l), Height(a->r)) + 1;
		b->height = max(Height(a->r), a->height) + 1;
		return b;
	}
	return 0;
}

AVL::node * AVL::DoubleLeftRotate(node* &a)
{
	a->r = RightRotate(a->r);
	return LeftRotate(a);
}

AVL::node * AVL::DoubleRightRotate(node* &a)
{
	a->l = LeftRotate(a->l);
	return RightRotate(a);
}

AVL::node * AVL::Min(node* a)
{
	if (a == NULL)
		return NULL;
	else if (a->l == NULL)
		return a;
	else
		return Min(a->l);
}

AVL::node * AVL::Max(node* a)
{
	if (a == NULL)
		return NULL;
	else if (a->r == NULL)
		return a;
	else
		return Max(a->r);
}

int AVL::Height(node* a)
{
	return (a == NULL ? -1 : a->height);
}

int AVL::GetBalance(node* a)
{
	if (a == NULL)
		return 0;
	else
		return Height(a->l) - Height(a->r);
}

void AVL::Inorder(node* a)
{
	if (a == NULL)
		return;
	Inorder(a->l);
	cout << a->val << " ";
	Inorder(a->r);
}

void AVL::Preorder(node* a)
{
	if (a == NULL)
		return;
	cout << a->val << " ";
	Inorder(a->l);
	Inorder(a->r);
}

void AVL::Postorder(node* a)
{
	if (a == NULL)
		return;
	Inorder(a->l);
	Inorder(a->r);
	cout << a->val << " ";
}

AVL::node* AVL::Remove(int x, node* a)
{
	node* temp;
	if (a == NULL)  //sprawdzamy czy istnieje
		return NULL;

	else if (x == a->val && a == root)
	{
		int pom = root->val;
		root->val = Min(root->r)->val;
		Min(root->r)->val = pom;
		a->r = Remove(x, a->r);
	}
	else if (x < a->val)//wyszukiwanie elementu
		a->l = Remove(x, a->l);
	else if (x > a->val)
		a->r = Remove(x, a->r);

	else if (a->l && a->r)//jesli ma dwojke dzieci 
	{
		temp = Min(a->r);
		a->val = temp->val;
		a->r = Remove(a->val, a->r);
	}

	else//jesli ma jedno lub wcale dzieci
	{
		temp = a;
		if (a->l == NULL)
			a = a->r;
		else if (a->r == NULL)
			a = a->l;
		delete temp;
	}
	if (a == NULL)
		return a;

	a->height = max(Height(a->l), Height(a->r)) + 1;//update wysokosci

	if (Height(a->l) - Height(a->r) == 2)//jesli usunelismy lewy, right case
	{
		if (Height(a->l->l) - Height(a->l->r) == 1)//right right case
			return LeftRotate(a);
		else//right left case
			return DoubleLeftRotate(a);

	}

	else if (Height(a->r) - Height(a->l) == 2)//jesli usunelismy prawy, left case
	{
		if (Height(a->r->r) - Height(a->r->l) == 1)//left left case
			return RightRotate(a);
		else//left right case
			return DoubleRightRotate(a);
	}
	return a;
}

void AVL::Print2DUtil(node* a, int space)
{
	if (a == NULL)
		return;
	space += COUNT;
	Print2DUtil(a->r, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << a->val << "\n";
	Print2DUtil(a->l, space);
}

void AVL::Print2D(node* a)
{
	Print2DUtil(root, 0);
}




