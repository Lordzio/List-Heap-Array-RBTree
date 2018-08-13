#pragma once
class List
{
private:

	struct Element {
		int data;
		Element *next;
		Element *prev;
	};

	void RmFr();
	void RmBck(Element *&e);
	void RmMid(Element *&point);

	Element *head;

public:	

	List();
	~List();
	void Add(int value1, int value2);
	void Remove(int value);
	void Display();
	void AddFr(int value);
	bool Search(int value);
};

