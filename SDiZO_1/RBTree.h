#pragma once
#include <string>
struct RBNode {
	RBNode *up, *left, *right;
	int key;
	char color;
};
class RBTree
{
private:

	RBNode S;
	RBNode *root;
	std::string cr, cl, cp;

	int nodes;

	void RemoveAll(RBNode *p);


public:
	RBTree();
	~RBTree();
	void Displayin(std::string sp, std::string sn, RBNode *p);
	void Display();
	RBNode *Search(int k);
	void Add(int k);
	void rot_L(RBNode *p);
	void rot_R(RBNode *p);
	bool Remove(int k);
	RBNode *succ(RBNode *p);
	RBNode *Min(RBNode *p);

};

