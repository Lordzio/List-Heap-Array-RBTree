#include "stdafx.h"
#include "RBTree.h"


void RBTree::RemoveAll(RBNode * p)
{
	if (p != &S)
	{
		RemoveAll(p->left);   
		RemoveAll(p->right);  
		delete p;              
	}
}

RBTree::RBTree()
{
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	S.color = 'B';          //guard initialization
	S.up = &S;
	S.left = &S;
	S.right = &S;
	root = &S;
}


RBTree::~RBTree()
{
	RemoveAll(root);
}


void RBTree::Displayin(std::string sp, std::string sn, RBNode * p)
{
	std::string t;

	if (p != &S)
	{
		t = sp;
		if (sn == cr) t[t.length() - 2] = ' ';
		Displayin(t + cp, cr, p->right);

		t = t.substr(0, sp.length() - 2);
		std::cout << t << sn << p->color << ":" << p->key << std::endl;

		t = sp;
		if (sn == cl) t[t.length() - 2] = ' ';
		Displayin(t + cp, cl, p->left);
	}
}

void RBTree::Display()
{
	Displayin("", "", root);
}
#pragma optimize( "", off )
RBNode *RBTree::Search(int k)
{
	RBNode *p;
	p = root;
	while ((p != &S) && (p->key != k))
		if (k < p->key) p = p->left;
		else           p = p->right;
		if (p == &S) return NULL;
		return p;
}
#pragma optimize( "", on )
void RBTree::Add(int k)
{
	RBNode *X, *Y;

	X = new RBNode;        
	X->left = &S;          
	X->right = &S;
	X->up = root;
	X->key = k;
	if (X->up == &S) root = X; 
	else
		while (true)             
		{
			if (k < X->up->key)
			{
				if (X->up->left == &S)
				{
					X->up->left = X;  
					break;
				}
				X->up = X->up->left;
			}
			else
			{
				if (X->up->right == &S)
				{
					X->up->right = X; 
					break;
				}
				X->up = X->up->right;
			}
		}
	X->color = 'R';         
	while ((X != root) && (X->up->color == 'R'))
	{
		if (X->up == X->up->up->left)
		{
			Y = X->up->up->right; 

			if (Y->color == 'R')  
			{
				X->up->color = 'B';
				Y->color = 'B';
				X->up->up->color = 'R';
				X = X->up->up;
				continue;
			}

			if (X == X->up->right) 
			{
				X = X->up;
				rot_L(X);
			}

			X->up->color = 'B'; 
			X->up->up->color = 'R';
			rot_R(X->up->up);
			break;
		}
		else
		{                  
			Y = X->up->up->left;

			if (Y->color == 'R') 
			{
				X->up->color = 'B';
				Y->color = 'B';
				X->up->up->color = 'R';
				X = X->up->up;
				continue;
			}

			if (X == X->up->left) 
			{
				X = X->up;
				rot_R(X);
			}

			X->up->color = 'B'; 
			X->up->up->color = 'R';
			rot_L(X->up->up);
			break;
		}
	}
	root->color = 'B';
}

void RBTree::rot_L(RBNode * e)
{
	RBNode * B, *p;

	B = e->right;
	if (B != &S)
	{
		p = e->up;
		e->right = B->left;
		if (e->right != &S) e->right->up = e;

		B->left = e;
		B->up = p;
		e->up = B;

		if (p != &S)
		{
			if (p->left == e) p->left = B; else p->right = B;
		}
		else root = B;
	}
}

void RBTree::rot_R(RBNode * e)
{
	RBNode * B, *p;

	B = e->left;
	if (B != &S)
	{
		p = e->up;
		e->left = B->right;
		if (e->left != &S) e->left->up = e;

		B->right = e;
		B->up = p;
		e->up = B;

		if (p != &S)
		{
			if (p->left == e) p->left = B; else p->right = B;
		}
		else root = B;
	}
}

bool RBTree::Remove(int k)
{
	RBNode *p;
	RBNode *W, *Y, *Z;
	bool removed = false;

	while ((p = Search(k)) != NULL) {
		removed = true;
		if ((p->left == &S) || (p->right == &S)) Y = p;
		else                                    Y = succ(p);

		if (Y->left != &S) Z = Y->left;
		else              Z = Y->right;

		Z->up = Y->up;

		if (Y->up == &S) root = Z;
		else if (Y == Y->up->left) Y->up->left = Z;
		else                      Y->up->right = Z;

		if (Y != p) p->key = Y->key;

		if (Y->color == 'B')
			while ((Z != root) && (Z->color == 'B'))
				if (Z == Z->up->left)
				{
					W = Z->up->right;

					if (W->color == 'R')
					{
						W->color = 'B';
						Z->up->color = 'R';
						rot_L(Z->up);
						W = Z->up->right;
					}

					if ((W->left->color == 'B') && (W->right->color == 'B'))
					{
						W->color = 'R';
						Z = Z->up;
						continue;
					}

					if (W->right->color == 'B')
					{
						W->left->color = 'B';
						W->color = 'R';
						rot_R(W);
						W = Z->up->right;
					}

					W->color = Z->up->color;
					Z->up->color = 'B';
					W->right->color = 'B';
					rot_L(Z->up);
					Z = root;
				}
				else
				{
					W = Z->up->left;

					if (W->color == 'R')
					{
						W->color = 'B';
						Z->up->color = 'R';
						rot_R(Z->up);
						W = Z->up->left;
					}

					if ((W->left->color == 'B') && (W->right->color == 'B'))
					{
						W->color = 'R';
						Z = Z->up;
						continue;
					}

					if (W->left->color == 'B')
					{
						W->right->color = 'B';
						W->color = 'R';
						rot_L(W);
						W = Z->up->left;
					}

					W->color = Z->up->color;
					Z->up->color = 'B';
					W->left->color = 'B';
					rot_R(Z->up);
					Z = root;
				}

		Z->color = 'B';

		delete Y;

	}
	if (removed) return true;
	else {
		std::cout << "Klucz nie zostal znaleziony.\n";
		return false;
	}
}

RBNode * RBTree::succ(RBNode * p)
{
	RBNode *r;

	if (p != &S)
	{
		if (p->right != &S) return Min(p->right);
		else
		{
			r = p->up;
			while ((r != &S) && (p == r->right))
			{
				p = r;
				r = r->up;
			}
			return r;
		}
	}
	return &S;
}

RBNode * RBTree::Min(RBNode * p)
{
	if (p != &S)
		while (p->left != &S) p = p->left;
	return p;
}
